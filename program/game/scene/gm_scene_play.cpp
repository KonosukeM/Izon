#include "../gm_manager.h"
#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "../audio/audio.h"
#include "../character/character.h"
#include "../character/object.h"
#include "gm_scene_play.h"
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
	player->initialzie(camera);

	stageobj = new Object();
	stageobj->initialzie(camera);

	stagesound = new Audio();
	stagesound->initialzie(camera);
}

// �t���[��
void ScenePlay::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();

	// �ړ�����
	int t = tnl::GetXzRegionPointAndOBB(
		camera->pos_
		, player->pos_
		, { 256, 480, 32 }
	, player->rot_);

	// �����œ��̓L�[�ƃA�j���[�V���������킹�Ă���
	if (player->movechange) {

		std::string anim_names[4] = {
			"front_left", "walk_right", "front_right", "walk_left"
		};
		player->sprite_->setCurrentAnim(anim_names[t]);
	}

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

		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RIGHT)) { player->motionchange = 1; }
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LEFT)) { player->motionchange = 2; }

		stageobj->stage_plane1_1->pos_ -= move_v * 2.0f;
		stageobj->stage_plane1_2->pos_ -= move_v * 2.0f;
		stageobj->charaobj1->pos_ -= move_v * 2.0f;
		stageobj->charaobj2->pos_ -= move_v * 2.0f;
	}

	camera->target_ = player->sprite_->pos_;

	player->update(delta_time);

	stageobj->update(delta_time);

	event(delta_time);

	if (player->pos_.x >= 8500) {
		mgr->chengeScene(new SceneResult());
	}
}

// �v���C��ʂł̕`��
void ScenePlay::render()
{
	camera->update();

	stageobj->render(camera);

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
	
	//playtime = delta_time;
	//noisetime += playtime;
	
	// ���ɍs���߂���Ǝ~�܂�
	if (player->pos_.x < -210) {

		player->pos_.x = -210;
		stageobj->stage_plane1_1->pos_.x = 1410;
		stageobj->stage_plane1_2->pos_.x = 6610;
		stageobj->charaobj1->pos_.x = 725;
		stageobj->charaobj2->pos_.x = 2354;
	}
	else if (player->pos_.x == 2600) {

		player->pos_.x = 4400;
		stageobj->stage_plane1_1->pos_.x = -3200;
		stageobj->stage_plane1_2->pos_.x = 2000;
		stageobj->charaobj1->pos_.x = -3885;
		stageobj->charaobj2->pos_.x = -2256;

	}
	else if (player->pos_.x == 4300) {

		player->pos_.x = 2500;
		stageobj->stage_plane1_1->pos_.x = -1300;
		stageobj->stage_plane1_2->pos_.x = 3900;
		stageobj->charaobj1->pos_.x = -1985;
		stageobj->charaobj2->pos_.x = -356;
	}
	// �E�ɍs���Ǝ��̖ʂ�
	else if (player->pos_.x > 8500) {

		player->pos_.x = 8500;
		stageobj->stage_plane1_1->pos_.x = -7300;
		stageobj->stage_plane1_2->pos_.x = -2100;
		stageobj->charaobj1->pos_.x = -7985;
		stageobj->charaobj2->pos_.x = -6356;
	}
	else { camera->target_ = player->pos_; }

	// �m�C�Y��������
	if (player->pos_.x >= 2580 && player->pos_.x <= 4320) {

		stageobj->noiseflag = true;
		stagesound->noiseaudioplay();
	}
	else { 
		
		stageobj->noiseflag = false;
		stagesound->noiseplayflag = false;
		StopSoundMem(stagesound->noiseaudio);
	}

	// �X�e�[�W1��BGM
	if (player->pos_.x > -220 && player->pos_.x < 8490) {

		stagesound->stagebgm1();
	}
	else {

		stagesound->stagebgmplayflag = false;
		StopSoundMem(stagesound->stageaudio);
	}

	// �I�u�W�F�N�g1�̌��ʉ�����
	if (player->pos_.x > 340 && player->pos_.x < 690) {

		stagesound->charaobjseplay1();
	}
	else { 
		
		stagesound->charaobj1seplayflag = false; 
		StopSoundMem(stagesound->chara1audio);
	}

	// �p�`���R�̌��ʉ�����
	if (player->pos_.x > 750 && player->pos_.x < 1650) {

		stagesound->pachincoseplay();
	}
	else {

		stagesound->stageseplayflag = false;
		StopSoundMem(stagesound->stagese);
	}

	// �I�u�W�F�N�g2�̌��ʉ�����
	if (player->pos_.x > 1950 && player->pos_.x < 2300) {

		stagesound->charaobjseplay2();
	}
	else {

		stagesound->charaobj2seplayflag = false;
		StopSoundMem(stagesound->chara2audio);
	}
	/*
	// �ŏ��̓G��������
	if (player->pos_.x >= 0 && player->pos_.x <= 7020) {

		stageobj->firstenemyflag = true;
		//stagesound->noiseaudioplay();
	}
	else {

		stageobj->firstenemyflag = false;
		//stagesound->noiseplayflag = false;
		//StopSoundMem(stagesound->noiseaudio);
	}*/
}