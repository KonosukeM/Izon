#include "../../dxlib_ext/dxlib_ext.h"
#include "../character/character.h"
#include "../character/object.h"
#include "audio.h"

Audio::~Audio() {
	delete eventpoint;
}

void Audio::initialzie(dxe::Camera* camera) {

	// �I�u�W�F�N�g�̃C���X�^���X�Ə�����
	eventpoint = new Object;
	eventpoint->initialzie(camera);

	if (!audioloadflag) {
		// �^�C�g��
		titleaudio = LoadSoundMem("sound/water_01.wav");
		titlese = LoadSoundMem("sound/�L�����Z��8.mp3");
		
		// �X�e�[�W
		stageaudio = LoadSoundMem("sound/VSQSE_0545_traffic_city_01.mp3");
		stagese = LoadSoundMem("sound/pachinco.mp3");
		
		// �m�C�Y
		noiseaudio = LoadSoundMem("sound/tutu4.mp3");

		// �I�u�W�F�N�g
		chara1audio = LoadSoundMem("sound/ojisan.wav");
		chara2audio = LoadSoundMem("sound/horror_nakigoe6.mp3");
		
		// ��x�����ǂݍ��ރt���O
		audioloadflag = true;
	}
}

// �^�C�g���ł̉��y�Đ��p
void Audio::titlebgm() {

	if (!titleplayflag) {
	
		// �{�����[��
		ChangeVolumeSoundMem(230, titleaudio);
		PlaySoundMem(titleaudio, DX_PLAYTYPE_LOOP, true);
		titleplayflag = true;
	}

	// �G���^�[��������N���b�N���ƃ^�C�g������~
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		PlaySoundMem(titlese, DX_PLAYTYPE_NORMAL, true);
		StopSoundMem(titleaudio);
	}
}

// �X�e�[�W1�ł̉��y�Đ��p
void Audio::stagebgm1() {

	if (!stagebgmplayflag) {

		// �{�����[��
		ChangeVolumeSoundMem(130, stageaudio);
		PlaySoundMem(stageaudio, DX_PLAYTYPE_LOOP, true);
		stagebgmplayflag = true;
	}
}

// �m�C�Y������
void Audio::noiseaudioplay() {

	if (!noiseplayflag) {

		// �{�����[��
		ChangeVolumeSoundMem(200, noiseaudio);
		PlaySoundMem(noiseaudio, DX_PLAYTYPE_LOOP, true);
		noiseplayflag = true;
	}
}

// �p�`���R�X�O
void Audio::pachincoseplay() {

	if (!stageseplayflag) {

		// �{�����[��
		ChangeVolumeSoundMem(100, stagese);
		PlaySoundMem(stagese, DX_PLAYTYPE_LOOP, true);
		stageseplayflag = true;
	}
}

// �I�u�W�F�N�g1�p
void Audio::charaobjseplay1() {

	// �w�i�I�u�W�F�N�g�̍��W���
	VECTOR point1;
	point1.x = eventpoint->charaobj1->pos_.x;
	point1.y = eventpoint->charaobj1->pos_.y;
	point1.z = eventpoint->charaobj1->pos_.z;

	if (!charaobj1seplayflag) {

		// �{�����[��
		ChangeVolumeSoundMem(255, chara1audio);

		// �����Đ��ꏊ
		Set3DPositionSoundMem(point1, chara1audio);

		// �����Đ��͈�
		Set3DRadiusSoundMem(1.0f, chara1audio);

		PlaySoundMem(chara1audio, DX_PLAYTYPE_BACK, true);
		charaobj1seplayflag = true;
	}
}

// �I�u�W�F�N�g2�p
void Audio::charaobjseplay2() {

	// �w�i�I�u�W�F�N�g�̍��W���
	VECTOR point2;
	point2.x = eventpoint->charaobj2->pos_.x;
	point2.y = eventpoint->charaobj2->pos_.y;
	point2.z = eventpoint->charaobj2->pos_.z;

	if (!charaobj2seplayflag) {

		// �{�����[��
		ChangeVolumeSoundMem(255, chara2audio);

		// �����Đ��ꏊ
		Set3DPositionSoundMem(point2, chara2audio);
		
		// �����Đ��͈�
		Set3DRadiusSoundMem(1.0f, chara2audio);
		
		PlaySoundMem(chara2audio, DX_PLAYTYPE_BACK, true);
		charaobj2seplayflag = true;
	}
}