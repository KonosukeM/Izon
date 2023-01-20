#include "../../dxlib_ext/dxlib_ext.h"
#include "../model/gm_model.h"

class GmCamera;
class AnimSprite3D;
class Character : public Model {
public:
    Character(){}
    ~Character();

private:

    // ���[�V�����ύX�ϐ�
    int motionchange = 0;

    GmCamera* camera_ = nullptr;

    // �v���C���[�A�j���[�V�����p
    AnimSprite3D* sprite_ = nullptr;

    // �I�u�W�F�N�g�p
    dxe::Mesh* charaobj1 = nullptr;
    dxe::Mesh* charaobj2 = nullptr;
    dxe::Mesh* charaobj3 = nullptr;

public:
    // �����������p
    void initialzie() override;
    void update(float delta_time) override;
    void render(dxe::Camera* camera) override;
};