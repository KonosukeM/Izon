#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class Audio;
class SceneTitle : public SceneBase {
public:
	SceneTitle() {}
	~SceneTitle();

	// タイトルテキスト用
	int titletext[2] = {0};

	// タイトル時間 / 経過時間
	float titletime = 0;
	float imagetime = 0;

	// タイトル描画用
	GmCamera* camera = nullptr;

	// ノイズアニメーション用
	AnimSprite3D* noise = nullptr;

	// タイトルイメージ用
	dxe::Mesh* titleimage1 = nullptr;
	dxe::Mesh* titleimage2 = nullptr;
	dxe::Mesh* titleimage3 = nullptr;
	dxe::Mesh* titleimage4 = nullptr;
	dxe::Mesh* titleimage5 = nullptr;

	// タイトルBGM用
	Audio* titlesound = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;

	// 時間経過でイメージが変わる関数
	void imagechange(float delta_time) override;
};
