#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class Character;
class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay();

	// プレイシーンカメラ
	GmCamera* camera_ = nullptr;

	// プレイヤー
	Character* player_ = nullptr;

	// プレイシーンの背景
	Character* stage_1 = nullptr;

	// オブジェクト
	Character* object_1 = nullptr;
	Character* object_2 = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
};

