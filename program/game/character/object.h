#include "../model/gm_model.h"

class AnimSprite3D;
class Object : public Model {
public:
	Object() {}
	~Object();

	bool noiseflag = false;
	bool firstenemyflag = false;
	bool stage1_1flag = false;
	bool stage1_2flag = false;

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

	void initialzie(dxe::Camera* camera);
	void update(float delta_time) override;
	void render(dxe::Camera* camera) override;
};