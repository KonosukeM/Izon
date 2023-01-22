#include "../scene/gm_scene_base.h"

class Audio : public SceneBase {
public:
	Audio() {}
	~Audio();

	int titleaudio = 0;
	int titlese = 0;

	void initialzie() override;
	void update(float delta_time) override;
	void render() override;

	void titlebgm();
};