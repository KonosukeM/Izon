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

	// ゲーム内で使用するノイズアニメーション用
	AnimSprite3D* noise = nullptr;

	// 最初に登場する敵のアニメーション
	AnimSprite3D* firstenemy = nullptr;

	// プレイシーンの背景
	dxe::Mesh* stage_plane1_1 = nullptr;
	dxe::Mesh* stage_plane1_2 = nullptr;

	// オブジェクト用
	dxe::Mesh* charaobj1 = nullptr;
	dxe::Mesh* charaobj2 = nullptr;
	dxe::Mesh* charaobj3 = nullptr;

	void initialzie(dxe::Camera* camera);
	void update(float delta_time) override;
	void render(dxe::Camera* camera) override;
};