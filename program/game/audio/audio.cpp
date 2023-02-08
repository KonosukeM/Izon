#include "../../dxlib_ext/dxlib_ext.h"
#include "../scene/gm_scene_object.h"
#include "audio.h"

Audio::~Audio() {

	delete eventpoint;
}

void Audio::initialzie() {

	eventpoint = new SceneObject;
	eventpoint->initialzie();

	if (!audioloadflag) {
		titleaudio = LoadSoundMem("sound/water_01.wav");
		titlese = LoadSoundMem("sound/ƒLƒƒƒ“ƒZƒ‹8.mp3");
		stageaudio = LoadSoundMem("sound/VSQSE_0545_traffic_city_01.mp3");
		stagese = LoadSoundMem("sound/pachinco.mp3");
		chara1audio = LoadSoundMem("sound/horror_nakigoe6.mp3");
		chara2audio = LoadSoundMem("sound/ojisan.wav");
		audioloadflag = true;
	}
}

void Audio::update(float delta_time) {

	// 340~690 men 888~1450 pacinco 1950~2300 women

}

void Audio::render() {

}

void Audio::titlebgm() {

	if (!titleplayflag) {
	
		ChangeVolumeSoundMem(200, titleaudio);
		PlaySoundMem(titleaudio, DX_PLAYTYPE_LOOP, true);
	}

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		PlaySoundMem(titlese, DX_PLAYTYPE_NORMAL, true);
		StopSoundMem(titleaudio);
	}
}

void Audio::stagebgm1() {

	if (!stagebgmplayflag) {

		ChangeVolumeSoundMem(100, stageaudio);
		PlaySoundMem(stageaudio, DX_PLAYTYPE_LOOP, true);
	}
}

void Audio::charaobjseplay2() {

	VECTOR point1;
	point1.x = eventpoint->charaobj2->pos_.x;
	point1.y = eventpoint->charaobj2->pos_.y;
	point1.z = eventpoint->charaobj2->pos_.z;

	if (!charaobj2seplayflag) {

		Set3DRadiusSoundMem(1.0f, chara2audio);
		Set3DPositionSoundMem(point1, chara2audio);
		PlaySoundMem(chara2audio, DX_PLAYTYPE_BACK, true);
	}
}