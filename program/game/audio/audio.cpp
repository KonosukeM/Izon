#include "../../dxlib_ext/dxlib_ext.h"
#include "audio.h"

Audio::~Audio() {

	//delete titleaudio;
}

void Audio::initialzie() {

	titleaudio = LoadSoundMem("water_01.wav");
	titlese = LoadSoundMem("ƒLƒƒƒ“ƒZƒ‹8.mp3");
}

void Audio::update(float delta_time) {

	// 340~670 men 800~1700 pacinco 1950~2300 women

	titlebgm();

}

void Audio::render() {

}

void Audio::titlebgm() {

	PlaySoundMem(titleaudio, DX_PLAYTYPE_LOOP, true);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		PlaySoundMem(titlese, DX_PLAYTYPE_NORMAL, true);
	}
}