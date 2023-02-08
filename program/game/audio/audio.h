#include "../../dxlib_ext/dxlib_ext.h"

class SceneObject;
class Audio {
public:
	Audio() {}
	~Audio();

	// オーディオ代入用
	int titleaudio = 0;
	int titlese = 0;
	int stageaudio = 0;
	int stagese = 0;
	int chara1audio = 0;
	int chara2audio = 0;

	// オーディオ読み込み用
	bool audioloadflag = false;

	// オーディオ再生用フラグ
	bool titleplayflag = false;
	bool stagebgmplayflag = false;
	bool stageseplayflag = false;
	bool charaobj1seplayflag = false;
	bool charaobj2seplayflag = false;

	SceneObject* eventpoint = nullptr;

	void initialzie();
	void update(float delta_time);
	void render();

	// タイトルBGM再生
	void titlebgm();

	// ステージBGM再生
	void stagebgm1();

	// ステージSE再生
	void stageseplay();

	// ステージオブジェクト1再生
	void charaobjseplay1();

	// ステージオブジェクト2再生
	void charaobjseplay2();

};