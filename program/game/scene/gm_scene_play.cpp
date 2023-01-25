#include "../gm_manager.h"
#include "../gm_camera.h"
#include "../character/character.h"
#include "gm_scene_play.h"
#include "gm_scene_object.h"
#include "gm_scene_result.h"

tnl::Quaternion	fix_rot;

ScenePlay::~ScenePlay() {
	delete camera_;
	delete player_;
	delete stageobj_;
}

// 画像の登録 初期化
void ScenePlay::initialzie() {

	camera_ = new GmCamera();
	camera_->pos_ = { 0, 150, -300 };

	player_ = new Character();
	player_->initialzie();

	stageobj_ = new SceneObject();
	stageobj_->initialzie();
}

// フレーム
void ScenePlay::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();

	tnl::Vector3 move_v = { 0,0,0 };

	// キー入力で移動した所に対しての進行描画
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
		player_->rot_.slerp(tnl::Quaternion::LookAtAxisY(player_->pos_, player_->pos_ + move_v), 0.3f);
		player_->pos_ += move_v * 2.0f;
		stageobj_->stage_plane1->pos_ -= move_v * 2.0f;
		stageobj_->stage_plane2->pos_ -= move_v * 2.0f;
		stageobj_->charaobj1->pos_ -= move_v * 2.0f;
		stageobj_->charaobj2->pos_ -= move_v * 2.0f;
	}

	player_->update(delta_time);

	stageobj_->update(delta_time);

	imagechange(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene(new SceneResult());
	}
}

// プレイ画面での描画
void ScenePlay::render()
{
	camera_->update();

	stageobj_->render();

	// プレイヤーをカメラに描画
	player_->render(camera_);

	DrawStringEx(50, 50, -1, "%f", player_->pos_.x); // プレイヤー座標

	// ワールドグリッド線の表示
	//DrawGridGround(camera_, 50, 50);

	//DrawOBB(camera_, sprite_->pos_, sprite_->rot_, { 32, 48, 32 });
	//DrawStringEx(50, 50, -1, "scene play");
	//DrawStringEx(50, 70, -1, "camera [ ← : A ] [ ↑ : W ] [ → : D ] [ ↓ : S ]");
	//DrawStringEx(50, 90, -1, "camera [ 遠 : Z ] [ 近 : X ] ");
	//DrawStringEx(50, 120, -1, "character [ 左 : ← ] [ 奥 : ↑ ] [ 右 : → ] [ 手前 : ↓ ] ");
}

void ScenePlay::imagechange(float delta_time)
{
	// 左に行き過ぎると止まる
	if (player_->pos_.x < -210) {

		player_->pos_.x = -210;
		stageobj_->stage_plane1->pos_.x = 1410;
		stageobj_->charaobj1->pos_.x = 2354;
		stageobj_->charaobj2->pos_.x = 725;
	}
	else { camera_->target_ = player_->pos_; }
}