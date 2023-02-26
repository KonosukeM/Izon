#include "../../dxlib_ext/dxlib_ext.h"
#include "../character/character.h"
#include "../character/object.h"
#include "audio.h"

Audio::~Audio() {
	delete eventpoint;
}

void Audio::initialzie(dxe::Camera* camera) {

	// オブジェクトのインスタンスと初期化
	eventpoint = new Object;
	eventpoint->initialzie(camera);

	if (!audioloadflag) {
		// タイトル
		titleaudio = LoadSoundMem("sound/water_01.wav");
		titlese = LoadSoundMem("sound/キャンセル8.mp3");
		
		// ステージ
		stageaudio = LoadSoundMem("sound/VSQSE_0545_traffic_city_01.mp3");
		stagese = LoadSoundMem("sound/pachinco.mp3");
		
		// ノイズ
		noiseaudio = LoadSoundMem("sound/tutu4.mp3");

		// オブジェクト
		chara1audio = LoadSoundMem("sound/ojisan.wav");
		chara2audio = LoadSoundMem("sound/horror_nakigoe6.mp3");
		
		// 一度だけ読み込むフラグ
		audioloadflag = true;
	}
}

// タイトルでの音楽再生用
void Audio::titlebgm() {

	if (!titleplayflag) {
	
		// ボリューム
		ChangeVolumeSoundMem(230, titleaudio);
		PlaySoundMem(titleaudio, DX_PLAYTYPE_LOOP, true);
		titleplayflag = true;
	}

	// エンター押したらクリック音とタイトル音停止
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {

		PlaySoundMem(titlese, DX_PLAYTYPE_NORMAL, true);
		StopSoundMem(titleaudio);
	}
}

// ステージ1での音楽再生用
void Audio::stagebgm1() {

	if (!stagebgmplayflag) {

		// ボリューム
		ChangeVolumeSoundMem(130, stageaudio);
		PlaySoundMem(stageaudio, DX_PLAYTYPE_LOOP, true);
		stagebgmplayflag = true;
	}
}

// ノイズ発生時
void Audio::noiseaudioplay() {

	if (!noiseplayflag) {

		// ボリューム
		ChangeVolumeSoundMem(200, noiseaudio);
		PlaySoundMem(noiseaudio, DX_PLAYTYPE_LOOP, true);
		noiseplayflag = true;
	}
}

// パチンコ店前
void Audio::pachincoseplay() {

	if (!stageseplayflag) {

		// ボリューム
		ChangeVolumeSoundMem(100, stagese);
		PlaySoundMem(stagese, DX_PLAYTYPE_LOOP, true);
		stageseplayflag = true;
	}
}

// オブジェクト1用
void Audio::charaobjseplay1() {

	// 背景オブジェクトの座標代入
	VECTOR point1;
	point1.x = eventpoint->charaobj1->pos_.x;
	point1.y = eventpoint->charaobj1->pos_.y;
	point1.z = eventpoint->charaobj1->pos_.z;

	if (!charaobj1seplayflag) {

		// ボリューム
		ChangeVolumeSoundMem(255, chara1audio);

		// 音声再生場所
		Set3DPositionSoundMem(point1, chara1audio);

		// 音声再生範囲
		Set3DRadiusSoundMem(1.0f, chara1audio);

		PlaySoundMem(chara1audio, DX_PLAYTYPE_BACK, true);
		charaobj1seplayflag = true;
	}
}

// オブジェクト2用
void Audio::charaobjseplay2() {

	// 背景オブジェクトの座標代入
	VECTOR point2;
	point2.x = eventpoint->charaobj2->pos_.x;
	point2.y = eventpoint->charaobj2->pos_.y;
	point2.z = eventpoint->charaobj2->pos_.z;

	if (!charaobj2seplayflag) {

		// ボリューム
		ChangeVolumeSoundMem(255, chara2audio);

		// 音声再生場所
		Set3DPositionSoundMem(point2, chara2audio);
		
		// 音声再生範囲
		Set3DRadiusSoundMem(1.0f, chara2audio);
		
		PlaySoundMem(chara2audio, DX_PLAYTYPE_BACK, true);
		charaobj2seplayflag = true;
	}
}