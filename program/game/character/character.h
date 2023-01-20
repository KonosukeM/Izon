#include "../../dxlib_ext/dxlib_ext.h"
#include "../model/gm_model.h"

class GmCamera;
class AnimSprite3D;
class Character : public Model {
public:
    Character(){}
    ~Character();

private:
    dxe::Camera* billboard_target_ = nullptr;

    // ���[�V�����ύX
    int motionchange = 0;

    GmCamera* camera_ = nullptr;

    // �v���C���[�A�j���[�V�����p
    AnimSprite3D* sprite_ = nullptr;

    // �v���C�V�[���̔w�i
    dxe::Mesh* stage_plane = nullptr;

    // �I�u�W�F�N�g�p
    dxe::Mesh* charaobj1 = nullptr;
    dxe::Mesh* charaobj2 = nullptr;
    //dxe::Mesh* charaobj3 = nullptr;

public:
    Character(dxe::Camera* camera) { billboard_target_ = camera; }
    // �����������p
    void initialzie() override;
    void update(float delta_time) override;
    void render(dxe::Camera* camera) override;
};