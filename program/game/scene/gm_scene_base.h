#pragma once

// 拡張させる用の関数
class SceneBase {
public :
	SceneBase(){}
	virtual ~SceneBase(){}

	// ↓の関数を継承している
	virtual void initialzie() = 0;
	virtual void update( float delta_time ) {}
	virtual void render(){}
	virtual void imagechange(float delta_time){}
	virtual void event(float delta_time){}
};

