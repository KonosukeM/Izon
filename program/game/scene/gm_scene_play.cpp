#include "../gm_manager.h"
#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "../character/character.h"
#include "gm_scene_play.h"
#include "gm_scene_result.h"

tnl::Quaternion	fix_rot;

ScenePlay::~ScenePlay() {
	delete camera_;
	delete player_;
	delete stage_1;
	delete object_1;
	delete object_2;
}

// 画像の登録 初期化
void ScenePlay::initialzie() {

	camera_ = new GmCamera();
	camera_->pos_ = { 0, 150, -300 };

	player_ = new Character(camera_);
	player_->initialzie();

	stage_1 = new Character(camera_);
	stage_1->initialzie();

	object_1 = new Character(camera_);
	object_1->initialzie();

	object_2 = new Character(camera_);
	object_2->initialzie();
}

// フレーム
void ScenePlay::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();

	player_->update(delta_time);

	stage_1->update(delta_time);

	object_1->update(delta_time);

	object_2->update(delta_time);

	// 340~670 men 800~1700 pacinco 1950~2300 women

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene(new SceneResult());
	}
}

// プレイヤー画像の描画
void ScenePlay::render()
{
	camera_->update();

	// プレイヤーをカメラに描画
	player_->render(camera_);

	//stage_1->render(camera_);

	object_1->render(camera_);
	object_2->render(camera_);


	// ワールドグリッド線の表示
	//DrawGridGround(camera_, 50, 50);

	//DrawOBB(camera_, sprite_->pos_, sprite_->rot_, { 32, 48, 32 });
	//DrawStringEx(50, 50, -1, "scene play");
	//DrawStringEx(50, 70, -1, "camera [ ← : A ] [ ↑ : W ] [ → : D ] [ ↓ : S ]");
	//DrawStringEx(50, 90, -1, "camera [ 遠 : Z ] [ 近 : X ] ");
	//DrawStringEx(50, 120, -1, "character [ 左 : ← ] [ 奥 : ↑ ] [ 右 : → ] [ 手前 : ↓ ] ");
}
