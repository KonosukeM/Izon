#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay();

	// モーション変更変数
	int motionchange = 0;

	GmCamera* camera_ = nullptr;

	// プレイヤーアニメーション用
	AnimSprite3D* sprite_ = nullptr;

	// エネミーアニメーション用
	//AnimSprite3D* enemysprite_ = nullptr;

	// オブジェクト用
	dxe::Mesh* charaobj1 = nullptr;
	dxe::Mesh* charaobj2 = nullptr;
	//dxe::Mesh* charaobj3 = nullptr;

	// プレイシーンの背景
	dxe::Mesh* stage_plane = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
};

