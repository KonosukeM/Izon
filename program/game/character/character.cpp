#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "character.h"

Character::~Character(){
	delete camera_;
	delete sprite_;
}

void Character::initialzie() {

	camera_ = new GmCamera();
	camera_->pos_ = { 0, 150, -300 };

	sprite_ = new AnimSprite3D(camera_);

	// �v���C���[�ҋ@���[�V����
	sprite_->regist(256, 480, "front_right", "graphics/anim_stayright.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "front_left", "graphics/anim_stayleft.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);

	// �v���C���[�ړ����[�V����
	sprite_->regist(256, 480, "walk_right", "graphics/anim_right.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "walk_left", "graphics/anim_left.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 480, 0);

	// �v���C���[���]���[�V����
	sprite_->regist(256, 480, "right_turn", "graphics/anim_rightturn.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 3, 480, 0);
	sprite_->regist(256, 480, "left_turn", "graphics/anim_leftturn.png", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 3, 480, 0);

	// �v���C���[�A�N�V�������[�V����
	sprite_->regist(256, 480, "squat_down", "graphics/anim_squatdown.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 4, 480, 0);
	sprite_->regist(256, 480, "squat_up", "graphics/anim_squatup.png", tnl::SeekUnit::ePlayMode::SINGLE, 1.0f, 4, 480, 0);

	// �ŏ��̃v���C���[�`��摜
	sprite_->setCurrentAnim("front_right");
}

// �t���[��
void Character::update(float delta_time)
{
	// �ړ�����
	int t = tnl::GetXzRegionPointAndOBB(
		camera_->pos_
		, sprite_->pos_
		, { 256, 480, 32 }
	, sprite_->rot_);

	// �����œ��̓L�[�ƃA�j���[�V���������킹�Ă���
	std::string anim_names[4] = {
		"front_left", "walk_right", "front_right", "walk_left"
	};
	sprite_->setCurrentAnim(anim_names[t]);

	tnl::Vector3 move_v = {0,0,0};

	// �L�[���͂ňړ��������ɑ΂��Ă̐i�s�`��
	tnl::Vector3 dir[2] = {
		//camera_->front().xz(), 
		camera_->right().xz(),
		//camera_->back().xz(),
		camera_->left().xz(),
	};

	// �L�[�{�[�h�������ɃR�[���o�b�N�֐������s
	tnl::Input::RunIndexKeyDown([&](uint32_t idx) {
		move_v += dir[idx];
		}, eKeys::KB_RIGHT, eKeys::KB_LEFT);

	// �L�[�{�[�h�������o
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT, eKeys::KB_LEFT)) {
		move_v.normalize();
		sprite_->rot_.slerp(tnl::Quaternion::LookAtAxisY(sprite_->pos_, sprite_->pos_ + move_v), 0.3f);
		sprite_->pos_ += move_v * 2.0f;

		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT)) { motionchange = 1; }
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT)) { motionchange = 2; }
	}

	// �E�����������̑ҋ@���[�V����
	if (!tnl::Input::IsKeyDown(eKeys::KB_RIGHT) && motionchange == 1) {

		sprite_->setCurrentAnim("front_right");
	}

	// �������������̑ҋ@���[�V����
	if (!tnl::Input::IsKeyDown(eKeys::KB_LEFT) && motionchange == 2) {
		
		sprite_->setCurrentAnim("front_left");
	}

	camera_->target_ = sprite_->pos_;

	sprite_->update(delta_time);
}

// �v���C���[�摜�̕`��
void Character::render(dxe::Camera* camera)
{
	camera_->update();

	// �v���C���[���J�����ɕ`��
	sprite_->render(camera_);
}