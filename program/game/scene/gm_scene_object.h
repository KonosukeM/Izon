#include "../../dxlib_ext/dxlib_ext_mesh.h"
#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class SceneObject : public SceneBase {
public:
	SceneObject() {}
	~SceneObject();

	bool noiseflag = false;
	bool firstenemyflag = false;
	bool stage1_1flag = false;
	bool stage1_2flag = false;

	GmCamera* camera = nullptr;

	// �Q�[�����Ŏg�p����m�C�Y�A�j���[�V�����p
	AnimSprite3D* noise = nullptr;

	// �ŏ��ɓo�ꂷ��G�̃A�j���[�V����
	AnimSprite3D* firstenemy = nullptr;

	// �v���C�V�[���̔w�i
	dxe::Mesh* stage_plane1_1 = nullptr;
	dxe::Mesh* stage_plane1_2 = nullptr;

	// �I�u�W�F�N�g�p
	dxe::Mesh* charaobj1 = nullptr;
	dxe::Mesh* charaobj2 = nullptr;
	dxe::Mesh* charaobj3 = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
	void imagechange(float delta_time) override;
};