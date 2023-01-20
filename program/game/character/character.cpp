#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "character.h"

Character::~Character(){
	delete camera_;
	delete sprite_;
	delete charaobj1;
	delete charaobj2;
}

void Character::initialzie() {

	camera_ = new GmCamera();
	camera_->pos_ = { 0, 150, -300 };

	sprite_ = new AnimSprite3D(camera_);

	// プレイヤー待機モーション
	sprite_->regist(256, 480, "front_right", "graphics/anim_stayright.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "front_left", "graphics/anim_stayleft.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);

	// プレイヤー移動モーション
	sprite_->regist(256, 480, "walk_right", "graphics/anim_right.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "walk_left", "graphics/anim_left.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);

	// プレイヤー反転モーション
	sprite_->regist(256, 480, "right_turn", "graphics/anim_rightturn.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 3, 480, 0);
	sprite_->regist(256, 480, "left_turn", "graphics/anim_leftturn.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 3, 480, 0);

	// プレイヤーアクションモーション
	sprite_->regist(256, 480, "squat_down", "graphics/anim_squatdown.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "squat_up", "graphics/anim_squatup.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 4, 480, 0);

	// 最初のプレイヤー描画画像
	sprite_->setCurrentAnim("front_right");

	// オブジェクトの設定
	charaobj1 = dxe::Mesh::CreatePlane({ 256, 480, 0 });
	charaobj1->setTexture(dxe::Texture::CreateFromFile("graphics/object1.png"));
	charaobj1->pos_ = { 2144, 100, 1 };

	charaobj2 = dxe::Mesh::CreatePlane({ 213, 400, 0 });
	charaobj2->setTexture(dxe::Texture::CreateFromFile("graphics/object2.png"));
	charaobj2->pos_ = { 515, 100, 1 };
}

// フレーム
void Character::update(float delta_time)
{
	// 移動制御
	int t = tnl::GetXzRegionPointAndOBB(
		camera_->pos_
		, sprite_->pos_
		, { 256, 480, 32 }
	, sprite_->rot_);

	// ここで入力キーとアニメーションを合わせている
	std::string anim_names[4] = {
		"front_left", "walk_right", "front_right", "walk_left"
	};
	sprite_->setCurrentAnim(anim_names[t]);

	tnl::Vector3 move_v = { 0,0,0 };

	// キー入力で移動した所に対しての描画
	tnl::Vector3 dir[2] = {
		//camera_->front().xz(), 
		camera_->right().xz(),
		//camera_->back().xz(),
		camera_->left().xz(),
	};

	// キーボード押下時にコールバック関数を実行
	tnl::Input::RunIndexKeyDown([&](uint32_t idx) {
		move_v += dir[idx];
		}, eKeys::KB_RIGHT, eKeys::KB_LEFT);

	// キーボード押下検出
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT, eKeys::KB_LEFT)) {
		move_v.normalize();
		sprite_->rot_.slerp(tnl::Quaternion::LookAtAxisY(sprite_->pos_, sprite_->pos_ + move_v), 0.3f);
		sprite_->pos_ += move_v * 2.0f;

		// 右キーを押されたとき
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT)) {

			motionchange = 1;
		}

		// 左キーを押されたとき
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT)) {

			motionchange = 2;
		}
	}


	// 右を向いた時の待機モーション
	if (!tnl::Input::IsKeyDown(eKeys::KB_RIGHT) && motionchange == 1) {

		sprite_->setCurrentAnim("front_right");
	}

	// 左を向いた時の待機モーション
	if (!tnl::Input::IsKeyDown(eKeys::KB_LEFT) && motionchange == 2) {

		sprite_->setCurrentAnim("front_left");
	}

	// カメラ制御
	tnl::Vector3 rot[4] = {
		{ 0, tnl::ToRadian(1.0f), 0 },
		{ 0, -tnl::ToRadian(1.0f), 0 },
		{ tnl::ToRadian(1.0f), 0, 0 },
		{ -tnl::ToRadian(1.0f), 0, 0 } };

	// 左に行き過ぎるとカメラ止まる
	if (sprite_->pos_.x < -210) {

		sprite_->pos_.x = -210;

	}// 右に行き過ぎるとカメラ止まる
	else if (sprite_->pos_.x > 2610) {

		sprite_->pos_.x = 2610;
	}
	else { camera_->target_ = sprite_->pos_; }

	//camera_->target_ = sprite_->pos_;
	sprite_->update(delta_time);
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		//mgr->chengeScene(new SceneResult());
	}
}

// プレイヤー画像の描画
void Character::render(dxe::Camera* camera)
{
	camera_->update();

	// オブジェクトの描画
	charaobj1->render(camera_);
	charaobj2->render(camera_);

	// プレイヤーをカメラに描画
	sprite_->render(camera_);

	//DrawOBB(camera_, sprite_->pos_, sprite_->rot_, { 32, 48, 32 });

	DrawStringEx(50, 50, -1, "%f", sprite_->pos_.x); // プレイヤー座標
	//DrawStringEx(50, 50, -1, "scene play");
	//DrawStringEx(50, 70, -1, "camera [ ← : A ] [ ↑ : W ] [ → : D ] [ ↓ : S ]");
	//DrawStringEx(50, 90, -1, "camera [ 遠 : Z ] [ 近 : X ] ");
	//DrawStringEx(50, 120, -1, "character [ 左 : ← ] [ 奥 : ↑ ] [ 右 : → ] [ 手前 : ↓ ] ");

}