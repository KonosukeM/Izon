#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "gm_scene_object.h"

SceneObject::~SceneObject() {
	delete camera_;
	delete noise_;
	delete stage_plane1;
	delete stage_plane2;
	delete charaobj1;
	delete charaobj2;
}

void SceneObject::initialzie() {

	camera_ = new GmCamera();
	camera_->pos_ = { 0, 150, -300 };

	noise_ = new AnimSprite3D(camera_);

	// �m�C�Y�A�j���[�V����
	noise_->regist(1536, 1152, "noise_anim", "graphics/titleimageanim.jpg", tnl::SeekUnit::ePlayMode::REPEAT, 1.0f, 4, 768, 0);
	noise_->pos_ = { 0, 0, 0 };
	noise_->setCurrentAnim("noise_anim");

	// �w�i�̐ݒ�
	stage_plane1 = dxe::Mesh::CreatePlane({ 4400, 1900, 0 });
	stage_plane1->setTexture(dxe::Texture::CreateFromFile("graphics/map1.png"));
	stage_plane1->pos_ = { 1200, 200, 2 };

	stage_plane2 = dxe::Mesh::CreatePlane({ 6600, 1900, 0 });
	stage_plane2->setTexture(dxe::Texture::CreateFromFile("graphics/map2.png"));
	stage_plane2->pos_ = { 6800, 200, 2 };

	// �I�u�W�F�N�g�̐ݒ�
	charaobj1 = dxe::Mesh::CreatePlane({ 256, 480, 0 });
	charaobj1->setTexture(dxe::Texture::CreateFromFile("graphics/object1.png"));
	charaobj1->pos_ = { 2144, 100, 1 };

	charaobj2 = dxe::Mesh::CreatePlane({ 213, 400, 0 });
	charaobj2->setTexture(dxe::Texture::CreateFromFile("graphics/object2.png"));
	charaobj2->pos_ = { 515, 100, 1 };
}

// �t���[��
void SceneObject::update(float delta_time)
{
	if (noiseflag) {

		noise_->update(delta_time);
		noise_->pos_.z = -1;
	}
}

// �v���C���[�摜�̕`��
void SceneObject::render()
{
	camera_->update();

	// �m�C�Y�A�j���[�V�������J�����ɕ`��
	if (noiseflag) {
	
		noise_->render(camera_);
	}

	// �X�e�[�W1�̔w�i�ƃI�u�W�F�N�g�̕`��
	if(!stage1flag) {
		// �w�i�̕`��
		stage_plane1->render(camera_);

		// �I�u�W�F�N�g�̕`��
		charaobj1->render(camera_);
		charaobj2->render(camera_);
	}


	// �X�e�[�W2�̔w�i�ƃI�u�W�F�N�g�̕`��
	if (!stage2flag) {
		// �w�i�̕`��
		stage_plane2->render(camera_);

	}
}