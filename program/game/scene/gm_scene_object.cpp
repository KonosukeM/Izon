#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "gm_scene_object.h"

SceneObject::~SceneObject() {
	delete camera;
	delete noise;
	delete stage_plane1;
	delete stage_plane2;
	delete charaobj1;
	delete charaobj2;
}

void SceneObject::initialzie() {

	camera = new GmCamera();
	camera->pos_ = { 0, 150, -300 };

	noise = new AnimSprite3D(camera);

	// ノイズアニメーション
	noise->regist(1536, 1152, "noise_anim", "graphics/titleimageanim.jpg", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 768, 0);
	noise->pos_ = { 0, 0, 0 };
	noise->setCurrentAnim("noise_anim");

	// 背景の設定
	stage_plane1 = dxe::Mesh::CreatePlane({ 4400, 1900, 0 });
	stage_plane1->setTexture(dxe::Texture::CreateFromFile("graphics/map1.png"));
	stage_plane1->pos_ = { 1200, 200, 2 };

	stage_plane2 = dxe::Mesh::CreatePlane({ 6600, 1900, 0 });
	stage_plane2->setTexture(dxe::Texture::CreateFromFile("graphics/map2.png"));
	stage_plane2->pos_ = { 6800, 200, 2 };

	// オブジェクトの設定
	charaobj1 = dxe::Mesh::CreatePlane({ 256, 480, 0 });
	charaobj1->setTexture(dxe::Texture::CreateFromFile("graphics/object1.png"));
	charaobj1->pos_ = { 2144, 100, 1 };

	charaobj2 = dxe::Mesh::CreatePlane({ 213, 400, 0 });
	charaobj2->setTexture(dxe::Texture::CreateFromFile("graphics/object2.png"));
	charaobj2->pos_ = { 515, 100, 1 };
}

// フレーム
void SceneObject::update(float delta_time)
{
	if (noiseflag) {

		noise->update(delta_time);
		noise->pos_.z = -1;
	}
}

// プレイヤー画像の描画
void SceneObject::render()
{
	camera->update();

	// ノイズアニメーションをカメラに描画
	if (noiseflag) {
	
		noise->render(camera);
	}

	// ステージ1の背景とオブジェクトの描画
	if(!stage1flag) {
		// 背景の描画
		stage_plane1->render(camera);

		// オブジェクトの描画
		charaobj1->render(camera);
		charaobj2->render(camera);
	}


	// ステージ2の背景とオブジェクトの描画
	if (!stage2flag) {
		// 背景の描画
		stage_plane2->render(camera);

	}
}