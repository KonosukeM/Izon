#include "../model/gm_model.h"

class GmCamera;
class AnimSprite3D;
class Character : public Model {
public:
    Character(){}
    ~Character();
    
private:

    // ���[�V�����ύX
    int motionchange = 0;

    GmCamera* camera_ = nullptr;
    // �v���C���[�A�j���[�V�����p
    AnimSprite3D* sprite_ = nullptr;

public:
    // �����������p
    void initialzie() override;
    void update(float delta_time) override;
    void render(dxe::Camera* camera) override;
};