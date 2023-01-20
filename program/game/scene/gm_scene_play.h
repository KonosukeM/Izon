#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class Character;
class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay();

	GmCamera* camera_ = nullptr;

	Character* player_ = nullptr;

	// プレイシーンの背景
	dxe::Mesh* stage_plane = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
};

