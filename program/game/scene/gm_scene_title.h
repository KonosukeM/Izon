#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class SceneTitle : public SceneBase {
public:
	SceneTitle() {}
	~SceneTitle();

	// �^�C�g���e�L�X�g�p
	int titletext[2] = {0};

	// �^�C�g������ / �o�ߎ���
	float titletime = 0;
	float imagetime = 0;

	// �^�C�g���`��p
	GmCamera* camera_ = nullptr;

	// �m�C�Y�A�j���[�V�����p
	AnimSprite3D* noise_ = nullptr;

	// �^�C�g���C���[�W�p
	dxe::Mesh* titleimage1 = nullptr;
	dxe::Mesh* titleimage2 = nullptr;
	dxe::Mesh* titleimage3 = nullptr;
	dxe::Mesh* titleimage4 = nullptr;
	dxe::Mesh* titleimage5 = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;

	// ���Ԍo�߂ŃC���[�W���ς��֐�
	void imagechange(float delta_time) override;
};
