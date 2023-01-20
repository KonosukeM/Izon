#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class Character;
class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay();

	// �v���C�V�[���J����
	GmCamera* camera_ = nullptr;

	// �v���C���[
	Character* player_ = nullptr;

	// �v���C�V�[���̔w�i
	Character* stage_1 = nullptr;

	// �I�u�W�F�N�g
	Character* object_1 = nullptr;
	Character* object_2 = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
};

