#include "../gm_manager.h"
#include "../gm_camera.h"
#include "../audio/audio.h"
#include "../character/character.h"
#include "gm_scene_play.h"
#include "gm_scene_object.h"
#include "gm_scene_result.h"

tnl::Quaternion	fix_rot;

ScenePlay::~ScenePlay() {
	delete camera;
	delete player;
	delete stageobj;
	delete stagesound;
}

// �摜�̓o�^ ������
void ScenePlay::initialzie() {

	camera = new GmCamera();
	camera->pos_ = { 0, 150, -300 };

	player = new Character();
	player->initialzie();

	stageobj = new SceneObject();
	stageobj->initialzie();

	stagesound = new Audio();
	stagesound->initialzie();
}

// �t���[��
void ScenePlay::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();

	tnl::Vector3 move_v = { 0,0,0 };

	// �L�[���͂ňړ��������ɑ΂��Ă̐i�s�`��
	tnl::Vector3 dir[2] = {
		//camera_->front().xz(), 
		camera->right().xz(),
		//camera_->back().xz(),
		camera->left().xz(),
	};

	// �L�[�{�[�h�������ɃR�[���o�b�N�֐������s
	tnl::Input::RunIndexKeyDown([&](uint32_t idx) {
		move_v += dir[idx];
		}, eKeys::KB_RIGHT, eKeys::KB_LEFT);

	// �L�[�{�[�h�������o
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT, eKeys::KB_LEFT)) {
		move_v.normalize();
		player->rot_.slerp(tnl::Quaternion::LookAtAxisY(player->pos_, player->pos_ + move_v), 0.3f);
		player->pos_ += move_v * 2.0f;
		stageobj->stage_plane1->pos_ -= move_v * 2.0f;
		stageobj->stage_plane2->pos_ -= move_v * 2.0f;
		stageobj->charaobj1->pos_ -= move_v * 2.0f;
		stageobj->charaobj2->pos_ -= move_v * 2.0f;
	}

	player->update(delta_time);

	stageobj->update(delta_time);

	stagesound->stagebgm1();
	stagesound->stagebgmplayflag = true;

	event(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene(new SceneResult());
	}
}

// �v���C��ʂł̕`��
void ScenePlay::render()
{
	camera->update();

	stageobj->render();

	// �v���C���[���J�����ɕ`��
	player->render(camera);

	DrawStringEx(50, 50, -1, "%f", player->pos_.x); // �v���C���[���W

	// ���[���h�O���b�h���̕\��
	//DrawGridGround(camera_, 50, 50);

	//DrawOBB(camera_, sprite_->pos_, sprite_->rot_, { 32, 48, 32 });
	//DrawStringEx(50, 50, -1, "scene play");
	//DrawStringEx(50, 70, -1, "camera [ �� : A ] [ �� : W ] [ �� : D ] [ �� : S ]");
	//DrawStringEx(50, 90, -1, "camera [ �� : Z ] [ �� : X ] ");
	//DrawStringEx(50, 120, -1, "character [ �� : �� ] [ �� : �� ] [ �E : �� ] [ ��O : �� ] ");
}

void ScenePlay::event(float delta_time)
{
	// ���ɍs���߂���Ǝ~�܂�
	if (player->pos_.x < -210) {

		player->pos_.x = -210;
		stageobj->stage_plane1->pos_.x = 1410;
		stageobj->charaobj1->pos_.x = 2354;
		stageobj->charaobj2->pos_.x = 725;
	}
	else { camera->target_ = player->pos_; }

	// �I�u�W�F�N�g2�̌��ʉ�����
	if (player->pos_.x > 340 && player->pos_.x < 690) {

		stagesound->charaobjseplay2();
		
	}
}