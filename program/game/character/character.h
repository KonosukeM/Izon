#include "../model/gm_model.h"

class AnimSprite3D;
class Character : public Model {
public:
    Character(){}
    ~Character();
    
public:

    // モーション変更
    int motionchange = 0;
    bool movechange = false;

    // プレイヤーアニメーション用
    AnimSprite3D* sprite_ = nullptr;

public:
    // 初期化処理用
    void initialzie(dxe::Camera* camera);
    void update(float delta_time) override;
    void render(dxe::Camera* camera) override;
};