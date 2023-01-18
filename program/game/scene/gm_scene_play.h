#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay();

	// ���[�V�����ύX�ϐ�
	int motionchange = 0;

	GmCamera* camera_ = nullptr;

	// �v���C���[�A�j���[�V�����p
	AnimSprite3D* sprite_ = nullptr;

	// �G�l�~�[�A�j���[�V�����p
	//AnimSprite3D* enemysprite_ = nullptr;

	// �I�u�W�F�N�g�p
	dxe::Mesh* charaobj1 = nullptr;
	dxe::Mesh* charaobj2 = nullptr;
	//dxe::Mesh* charaobj3 = nullptr;

	// �v���C�V�[���̔w�i
	dxe::Mesh* stage_plane = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
};

