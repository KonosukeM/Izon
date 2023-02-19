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

	// ゲーム内で使用するノイズアニメーション用
	AnimSprite3D* noise = nullptr;

	// プレイシーンの背景
	dxe::Mesh* stage_plane1 = nullptr;
	dxe::Mesh* stage_plane2 = nullptr;

	// オブジェクト用
	dxe::Mesh* charaobj1 = nullptr;
	dxe::Mesh* charaobj2 = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
	void imagechange(float delta_time) override;
};