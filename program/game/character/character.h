#include "../model/gm_model.h"

class AnimSprite3D;
class Character : public Model {
public:
    Character(){}
    ~Character();
    
public:

    // ���[�V�����ύX
    int motionchange = 0;
    bool movechange = false;

    // �v���C���[�A�j���[�V�����p
    AnimSprite3D* sprite_ = nullptr;

public:
    // �����������p
    void initialzie(dxe::Camera* camera);
    void update(float delta_time) override;
    void render(dxe::Camera* camera) override;
};