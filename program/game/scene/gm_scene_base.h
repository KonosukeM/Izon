#pragma once

// �g��������p�̊֐�
class SceneBase {
public :
	SceneBase(){}
	virtual ~SceneBase(){}

	// ���̊֐����p�����Ă���
	virtual void initialzie() = 0;
	virtual void update( float delta_time ) {}
	virtual void render(){}
	virtual void imagechange(float delta_time){}
	virtual void event(float delta_time){}
};

