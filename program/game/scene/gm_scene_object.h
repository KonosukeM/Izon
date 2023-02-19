#include "../../dxlib_ext/dxlib_ext_mesh.h"
#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class SceneObject : public SceneBase {
public:
	SceneObject() {}
	~SceneObject();

	bool noiseflag = false;
	bool stage1flag = false;
	bool stage2flag = false;

	GmCamera* camera = nullptr;

	// �Q�[�����Ŏg�p����m�C�Y�A�j���[�V�����p
	AnimSprite3D* noise = nullptr;

	// �v���C�V�[���̔w�i
	dxe::Mesh* stage_plane1 = nullptr;
	dxe::Mesh* stage_plane2 = nullptr;

	// �I�u�W�F�N�g�p
	dxe::Mesh* charaobj1 = nullptr;
	dxe::Mesh* charaobj2 = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
	void imagechange(float delta_time) override;
};