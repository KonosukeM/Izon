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

    // モーション変更
    int motionchange = 0;

    GmCamera* camera_ = nullptr;

    // プレイヤーアニメーション用
    AnimSprite3D* sprite_ = nullptr;

    // プレイシーンの背景
    dxe::Mesh* stage_plane = nullptr;

    // オブジェクト用
    dxe::Mesh* charaobj1 = nullptr;
    dxe::Mesh* charaobj2 = nullptr;
    //dxe::Mesh* charaobj3 = nullptr;

public:
    Character(dxe::Camera* camera) { billboard_target_ = camera; }
    // 初期化処理用
    void initialzie() override;
    void update(float delta_time) override;
    void render(dxe::Camera* camera) override;
};