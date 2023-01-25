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

// �摜�̓o�^ ������
void ScenePlay::initialzie() {

	camera_ = new GmCamera();
	camera_->pos_ = { 0, 150, -300 };

	player_ = new Character();
	player_->initialzie();

	stageobj_ = new SceneObject();
	stageobj_->initialzie();
}

// �t���[��
void ScenePlay::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();

	tnl::Vector3 move_v = { 0,0,0 };

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

// �v���C��ʂł̕`��
void ScenePlay::render()
{
	camera_->update();

	stageobj_->render();

	// �v���C���[���J�����ɕ`��
	player_->render(camera_);

	DrawStringEx(50, 50, -1, "%f", player_->pos_.x); // �v���C���[���W

	// ���[���h�O���b�h���̕\��
	//DrawGridGround(camera_, 50, 50);

	//DrawOBB(camera_, sprite_->pos_, sprite_->rot_, { 32, 48, 32 });
	//DrawStringEx(50, 50, -1, "scene play");
	//DrawStringEx(50, 70, -1, "camera [ �� : A ] [ �� : W ] [ �� : D ] [ �� : S ]");
	//DrawStringEx(50, 90, -1, "camera [ �� : Z ] [ �� : X ] ");
	//DrawStringEx(50, 120, -1, "character [ �� : �� ] [ �� : �� ] [ �E : �� ] [ ��O : �� ] ");
}

void ScenePlay::imagechange(float delta_time)
{
	// ���ɍs���߂���Ǝ~�܂�
	if (player_->pos_.x < -210) {

		player_->pos_.x = -210;
		stageobj_->stage_plane1->pos_.x = 1410;
		stageobj_->charaobj1->pos_.x = 2354;
		stageobj_->charaobj2->pos_.x = 725;
	}
	else { camera_->target_ = player_->pos_; }
}