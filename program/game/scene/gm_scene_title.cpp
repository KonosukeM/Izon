#include "../gm_manager.h"
#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "gm_scene_title.h"
#include "gm_scene_play.h"

SceneTitle::~SceneTitle(){
	delete camera_;
	delete noise_;
	delete titleimage1;
	delete titleimage2;
	delete titleimage3;
	delete titleimage4;
	delete titleimage5;
}

void SceneTitle::initialzie() {

	camera_ = new GmCamera();
	camera_->pos_ = { 0, 0, 0 };

	noise_ = new AnimSprite3D(camera_);

	// タイトルテキストの設定
	titletext[0] = LoadGraph("graphics/Titlename.png");
	titletext[1] = LoadGraph("graphics/Start.png");

	// タイトルイメージの設定
	titleimage1 = dxe::Mesh::CreatePlane({ 1536, 1152, 0 });
	titleimage1->setTexture(dxe::Texture::CreateFromFile("graphics/titleimage1.jpg"));
	titleimage1->pos_ = { 0, 0, 0 };

	titleimage2 = dxe::Mesh::CreatePlane({ 1536, 1152, 0 });
	titleimage2->setTexture(dxe::Texture::CreateFromFile("graphics/titleimage2.jpg"));
	titleimage2->pos_ = { 2048, 0, 0 };

	titleimage3 = dxe::Mesh::CreatePlane({ 1536, 1152, 0 });
	titleimage3->setTexture(dxe::Texture::CreateFromFile("graphics/titleimage3.jpg"));
	titleimage3->pos_ = { 2048, 0, 0 };

	titleimage4 = dxe::Mesh::CreatePlane({ 1536, 1152, 0 });
	titleimage4->setTexture(dxe::Texture::CreateFromFile("graphics/titleimage4.jpg"));
	titleimage4->pos_ = { 2048, 0, 0 };

	titleimage5 = dxe::Mesh::CreatePlane({ 1536, 1152, 0 });
	titleimage5->setTexture(dxe::Texture::CreateFromFile("graphics/titleimage5.jpg"));
	titleimage5->pos_ = { 2048, 0, 0 };

	// ノイズアニメーション
	noise_->regist(1536, 1152, "noise_anim", "graphics/titleimageanim.jpg", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 768, 0);
	noise_->pos_ = { 2048, 0, 0 };
	noise_->setCurrentAnim("noise_anim");
}

void SceneTitle::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();

	imagechange(delta_time);

	noise_->update(delta_time);
	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene( new ScenePlay() );
	}
}

void SceneTitle::render()
{
	camera_->update();

	noise_->render(camera_);

	// タイトルイメージの描画
	titleimage1->render(camera_);
	titleimage2->render(camera_);
	titleimage3->render(camera_);
	titleimage4->render(camera_);
	titleimage5->render(camera_);

	//DrawStringEx(50, 50, -1, "scene title");
	
	// タイトルテキスト描画
	DrawRotaGraph(500, 220, 1, 0.0, titletext[0], true);
	DrawRotaGraph(500, 550, 0.3, 0.0, titletext[1], true);
}

// タイトル画像の描画順
void SceneTitle::imagechange(float delta_time)
{
	titletime = delta_time;
	imagetime += titletime;

	if (imagetime >= 0 && imagetime <= 2) {

		titleimage1->pos_.x = 0;
		noise_->pos_.x = 2048;
	}
	else { titleimage1->pos_.x = 2048; noise_->pos_.x = 0; }

	if (imagetime >= 4 && imagetime <= 6) {

		titleimage2->pos_.x = 0;
		noise_->pos_.x = 2048;
	}
	else { titleimage2->pos_.x = 2048; noise_->pos_.x = 0; }

	if (imagetime >= 8 && imagetime <= 10) {

		titleimage3->pos_.x = 0;
		noise_->pos_.x = 2048;
	}
	else { titleimage3->pos_.x = 2048; noise_->pos_.x = 0; }

	if (imagetime >= 12 && imagetime <= 14) {

		titleimage4->pos_.x = 0;
		noise_->pos_.x = 2048;
	}
	else { titleimage4->pos_.x = 2048; noise_->pos_.x = 0; }

	if (imagetime >= 16 && imagetime <= 18) {

		titleimage5->pos_.x = 0;
		noise_->pos_.x = 2048;
	}
	else { titleimage5->pos_.x = 2048; noise_->pos_.x = 0; }

	if (imagetime >= 20 && imagetime <= 22) {

		imagetime = 0;
	}
}