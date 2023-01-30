#include "../../dxlib_ext/dxlib_ext.h"
#include "audio.h"

Audio::~Audio() {

}

void Audio::initialzie() {

	if (!titleloadflag) {
		titleaudio = LoadSoundMem("sound/water_01.wav");
		titlese = LoadSoundMem("sound/ƒLƒƒƒ“ƒZƒ‹8.mp3");
		titleloadflag = true;
	}
}

void Audio::update(float delta_time) {

	// 340~670 men 800~1700 pacinco 1950~2300 women

}

void Audio::render() {

}

void Audio::titlebgm() {

	if (!titleplayflag) {
	
		PlaySoundMem(titleaudio, DX_PLAYTYPE_LOOP, true);

		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

			PlaySoundMem(titlese, DX_PLAYTYPE_NORMAL, true);
		}
	}
}