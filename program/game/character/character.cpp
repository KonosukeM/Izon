#include "../model/gm_anim_sprite3d.h"
#include "character.h"

Character::~Character(){
	delete sprite_;
}

void Character::initialzie(dxe::Camera* camera) {

	sprite_ = new AnimSprite3D(camera);

	// �v���C���[�ҋ@���[�V����
	sprite_->regist(256, 480, "front_right", "graphics/anim_stayright.png", tnl::SeekUnit::ePlayMode::REPEAT, 2.5f, 4, 480, 0);
	sprite_->regist(256, 480, "front_left", "graphics/anim_stayleft.png", tnl::SeekUnit::ePlayMode::REPEAT, 2.5f, 4, 480, 0);

	// �v���C���[�ړ����[�V����
	sprite_->regist(256, 480, "walk_right", "graphics/anim_right.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "walk_left", "graphics/anim_left.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);

	// �v���C���[���]���[�V����
	sprite_->regist(256, 480, "right_turn", "graphics/anim_rightturn.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 3, 480, 0);
	sprite_->regist(256, 480, "left_turn", "graphics/anim_leftturn.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 3, 480, 0);

	// �v���C���[�A�N�V�������[�V����
	sprite_->regist(256, 480, "squat_down", "graphics/anim_squatdown.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "squat_up", "graphics/anim_squatup.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 4, 480, 0);

	// �ŏ��̃v���C���[�`��摜
	sprite_->setCurrentAnim("front_right");
}

// �t���[��
void Character::update(float delta_time)
{
	// �E�����������̑ҋ@���[�V����
	if (!tnl::Input::IsKeyDown(eKeys::KB_RIGHT) && motionchange == 1) {

		sprite_->setCurrentAnim("front_right");
	}

	// �������������̑ҋ@���[�V����
	if (!tnl::Input::IsKeyDown(eKeys::KB_LEFT) && motionchange == 2) {
		
		sprite_->setCurrentAnim("front_left");
	}

	sprite_->update(delta_time);
}

// �v���C���[�摜�̕`��
void Character::render(dxe::Camera* camera)
{
	// �v���C���[���J�����ɕ`��
	sprite_->render(camera);
}