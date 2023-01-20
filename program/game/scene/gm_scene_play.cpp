#include "../gm_manager.h"
#include "../gm_camera.h"
#include "../model/gm_anim_sprite3d.h"
#include "../character/character.h"
#include "gm_scene_play.h"
#include "gm_scene_result.h"

tnl::Quaternion	fix_rot;

ScenePlay::~ScenePlay() {
	delete camera_;
	delete stage_plane;
}

// �摜�̓o�^ ������
void ScenePlay::initialzie() {

	camera_ = new GmCamera();
	camera_->pos_ = { 0, 150, -300 };

	player_ = new Character();
	player_->initialzie();

	// �w�i�̐ݒ�
	stage_plane = dxe::Mesh::CreatePlane({4400, 1900, 0});
	stage_plane->setTexture(dxe::Texture::CreateFromFile("graphics/map1.png"));
	stage_plane->pos_ = { 1200, 200, 2 };

}

// �t���[��
void ScenePlay::update(float delta_time)
{
	GameManager* mgr = GameManager::GetInstance();
	
	player_->update(delta_time);
	
	// �J��������
	tnl::Vector3 rot[4] = {
		{ 0, tnl::ToRadian(1.0f), 0 },
		{ 0, -tnl::ToRadian(1.0f), 0 },
		{ tnl::ToRadian(1.0f), 0, 0 },
		{ -tnl::ToRadian(1.0f), 0, 0 } };

	/*// ���[���h��ł̃J�����̑���
	tnl::Input::RunIndexKeyDown([&](uint32_t idx) {
		camera_->free_look_angle_xy_ += rot[idx];
	}, eKeys::KB_A, eKeys::KB_D, eKeys::KB_W, eKeys::KB_S);

	if (tnl::Input::IsKeyDown(eKeys::KB_Z)) {
		camera_->target_distance_ += 1.0f;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_X)) {
		camera_->target_distance_ -= 1.0f;
	}
	*/

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		mgr->chengeScene(new SceneResult());
	}
}

// �v���C���[�摜�̕`��
void ScenePlay::render()
{
	camera_->update();
	player_->render(camera_);

	// ���[���h�O���b�h���̕\��
	//DrawGridGround(camera_, 50, 50);

	// �w�i�̕`��
	stage_plane->render(camera_);

	/*/ �I�u�W�F�N�g�̕`��
	charaobj1->render(camera_);
	charaobj2->render(camera_);

	// �v���C���[���J�����ɕ`��
	sprite_->render(camera_);



	//DrawOBB(camera_, sprite_->pos_, sprite_->rot_, { 32, 48, 32 });

	DrawStringEx(50, 50, -1, "%f", sprite_->pos_.x); // �v���C���[���W
	//DrawStringEx(50, 50, -1, "scene play");
	//DrawStringEx(50, 70, -1, "camera [ �� : A ] [ �� : W ] [ �� : D ] [ �� : S ]");
	//DrawStringEx(50, 90, -1, "camera [ �� : Z ] [ �� : X ] ");
	//DrawStringEx(50, 120, -1, "character [ �� : �� ] [ �� : �� ] [ �E : �� ] [ ��O : �� ] ");
	*/
}
