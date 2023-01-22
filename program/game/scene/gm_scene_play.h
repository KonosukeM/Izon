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

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
};

