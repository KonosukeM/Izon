#include "gm_scene_base.h"

class GmCamera;
class AnimSprite3D;
class ScenePlay : public SceneBase {
public :
	ScenePlay(){}
	~ScenePlay();

	// ���[�V�����ύX�ϐ�
	int motionchange = 0;

	// ���[�V�����t���O
	bool motionflag = false;
	bool motionrightflag = false;
	bool motionleftflag = false;

	GmCamera* camera_ = nullptr;
	AnimSprite3D* sprite_ = nullptr;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;
};

