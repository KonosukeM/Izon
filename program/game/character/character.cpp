#include "../model/gm_anim_sprite3d.h"
#include "character.h"

Character::~Character(){
	delete sprite_;
}

void Character::initialzie(dxe::Camera* camera) {

	sprite_ = new AnimSprite3D(camera);

	// プレイヤー待機モーション
	sprite_->regist(256, 480, "front_right", "graphics/anim_stayright.png", tnl::SeekUnit::ePlayMode::REPEAT, 2.5f, 4, 480, 0);
	sprite_->regist(256, 480, "front_left", "graphics/anim_stayleft.png", tnl::SeekUnit::ePlayMode::REPEAT, 2.5f, 4, 480, 0);

	// プレイヤー移動モーション
	sprite_->regist(256, 480, "walk_right", "graphics/anim_right.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "walk_left", "graphics/anim_left.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);

	// プレイヤー反転モーション
	sprite_->regist(256, 480, "right_turn", "graphics/anim_rightturn.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 3, 480, 0);
	sprite_->regist(256, 480, "left_turn", "graphics/anim_leftturn.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 3, 480, 0);

	// プレイヤーアクションモーション
	sprite_->regist(256, 480, "squat_down", "graphics/anim_squatdown.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "squat_up", "graphics/anim_squatup.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 4, 480, 0);

	// 最初のプレイヤー描画画像
	sprite_->setCurrentAnim("front_right");
}

// フレーム
void Character::update(float delta_time)
{
	// 右を向いた時の待機モーション
	if (!tnl::Input::IsKeyDown(eKeys::KB_RIGHT) && motionchange == 1) {

		sprite_->setCurrentAnim("front_right");
	}

	// 左を向いた時の待機モーション
	if (!tnl::Input::IsKeyDown(eKeys::KB_LEFT) && motionchange == 2) {
		
		sprite_->setCurrentAnim("front_left");
	}

	sprite_->update(delta_time);
}

// プレイヤー画像の描画
void Character::render(dxe::Camera* camera)
{
	// プレイヤーをカメラに描画
	sprite_->render(camera);
}