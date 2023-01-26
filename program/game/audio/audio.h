#include "../../dxlib_ext/dxlib_ext.h"

class Audio {
public:
	Audio() {}
	~Audio();

	int titleaudio = 0;
	int titlese = 0;
	bool titleloadflag = false;
	bool titleplayflag = false;

	void initialzie();
	void update(float delta_time);
	void render();

	void titlebgm();
};