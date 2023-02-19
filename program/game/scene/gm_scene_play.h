#include "gm_scene_base.h"

class GmCamera;
class Character;
class SceneObject;
class Audio;
class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay();

	// ���Ԍo�ߊǗ��p
	float playtime = 0;
	float noisetime = 0;

	// �v���C�V�[���J����
	GmCamera* camera = nullptr;

	// �v���C���[
	Character* player = nullptr;

	// �V�[���I�u�W�F�N�g
	SceneObject* stageobj = nullptr;

	// �X�e�[�WBGM�ESE�p
	Audio* stagesound = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
	void event(float delta_time) override;
};

