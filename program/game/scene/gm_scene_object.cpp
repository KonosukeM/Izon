#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "gm_scene_object.h"

SceneObject::~SceneObject() {
	delete camera;
	delete noise;
	delete firstenemy;
	delete stage_plane1_1;
	delete stage_plane1_2;
	delete charaobj1;
	delete charaobj2;
	delete charaobj3;
}

void SceneObject::initialzie() {

	camera = new GmCamera();
	camera->pos_ = { 0, 150, -300 };

	// ノイズアニメーション
	noise = new AnimSprite3D(camera);
	noise->regist(1536, 1152, "noise_anim", "graphics/titleimageanim.jpg", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 768, 0);
	noise->pos_ = { 0, 0, -1 };
	noise->setCurrentAnim("noise_anim");

	// 最初の敵のアニメーション
	//firstenemy = new AnimSprite3D(camera);
	//firstenemy->regist(256, 480, "firstenemy_anim", "graphics/object3.png", tnl::SeekUnit::ePlayMode::REPEAT, 2.5f, 4, 480, 0);
	//firstenemy->pos_ = { 200, 80, -1 };
	//firstenemy->setCurrentAnim("firstenemy_anim");


	// 背景の設定
	stage_plane1_1 = dxe::Mesh::CreatePlane({ 4400, 1900, 0 });
	stage_plane1_1->setTexture(dxe::Texture::CreateFromFile("graphics/map1.png"));
	stage_plane1_1->pos_ = { 1200, 200, 2 };

	stage_plane1_2 = dxe::Mesh::CreatePlane({ 5800, 1700, 0 });
	stage_plane1_2->setTexture(dxe::Texture::CreateFromFile("graphics/map2.png"));
	stage_plane1_2->pos_ = { 6400, 153, 2 };

	// オブジェクトの設定
	charaobj1 = dxe::Mesh::CreatePlane({ 213, 400, 0 });
	charaobj1->setTexture(dxe::Texture::CreateFromFile("graphics/object1.png"));
	charaobj1->pos_ = { 515, 100, 1 };

	charaobj2 = dxe::Mesh::CreatePlane({ 256, 480, 0 });
	charaobj2->setTexture(dxe::Texture::CreateFromFile("graphics/object2.png"));
	charaobj2->pos_ = { 2144, 100, 1 };

	charaobj3 = dxe::Mesh::CreatePlane({ 256, 480, 0 });
	charaobj3->setTexture(dxe::Texture::CreateFromFile("graphics/object3.png"));
	charaobj3->pos_ = { 200, 100, 1 };
}

// フレーム
void SceneObject::update(float delta_time)
{
	imagechange(delta_time);
}

void SceneObject::render()
{
	camera->update();

	// ノイズをカメラに描画
	if (noiseflag) {

		noise->render(camera);
	}
	/*
	// 最初の敵をカメラに描画
	if (firstenemyflag) {

		firstenemy->render(camera);
	}*/

	// ステージ1の背景とオブジェクトの描画
	if(!stage1_1flag) {
		// 背景の描画
		stage_plane1_1->render(camera);

		// オブジェクトの描画
		charaobj1->render(camera);
		charaobj2->render(camera);
	}

	// ステージ2の背景とオブジェクトの描画
	if (!stage1_2flag) {
		// 背景の描画
		stage_plane1_2->render(camera);

	}
}

void SceneObject::imagechange(float delta_time) {

	// ノイズアニメーションをカメラに描画
	if (noiseflag) {

		noise->update(delta_time);
	}
	/*
	// 最初の敵アニメーションをカメラに描画
	if (firstenemyflag) {

		firstenemy->update(delta_time);
	}*/
}