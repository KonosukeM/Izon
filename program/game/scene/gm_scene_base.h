#pragma once

// Šg’£‚³‚¹‚é—p‚ÌŠÖ”
class SceneBase {
public :
	SceneBase(){}
	virtual ~SceneBase(){}

	// «‚ÌŠÖ”‚ğŒp³‚µ‚Ä‚¢‚é
	virtual void initialzie() = 0;
	virtual void update( float delta_time ) {}
	virtual void render(){}
	virtual void imagechange(float delta_time){}
	virtual void event(float delta_time){}
};

