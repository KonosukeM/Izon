#include "gm_scene_base.h"

class GmCamera;
class Character;
class SceneObject;
class Audio;
class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay();

	// 時間経過管理用
	float playtime = 0;
	float noisetime = 0;

	// プレイシーンカメラ
	GmCamera* camera = nullptr;

	// プレイヤー
	Character* player = nullptr;

	// シーンオブジェクト
	SceneObject* stageobj = nullptr;

	// ステージBGM・SE用
	Audio* stagesound = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
	void event(float delta_time) override;
};

