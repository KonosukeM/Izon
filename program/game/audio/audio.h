#include "../../dxlib_ext/dxlib_ext.h"

class Character;
class SceneObject;
class Audio {
public:
	Audio() {}
	~Audio();

	// �I�[�f�B�I����p
	int titleaudio = 0;
	int titlese = 0;
	int stageaudio = 0;
	int stagese = 0;
	int noiseaudio = 0;
	int chara1audio = 0;
	int chara2audio = 0;

	// �I�[�f�B�I�ǂݍ��ݗp
	bool audioloadflag = false;

	// �I�[�f�B�I�Đ��p�t���O
	bool titleplayflag = false;
	bool stagebgmplayflag = false;
	bool stageseplayflag = false;
	bool noiseplayflag = false;
	bool charaobj1seplayflag = false;
	bool charaobj2seplayflag = false;

	// �v���C���[�̍��W�p
	Character* playerpos = nullptr;

	// �I�u�W�F�N�g�̍��W�p
	SceneObject* eventpoint = nullptr;

	void initialzie();
	void update(float delta_time);
	void render();

	// �^�C�g��BGM�Đ�
	void titlebgm();

	// �X�e�[�WBGM�Đ�
	void stagebgm1();

	// �m�C�Y�������Đ�
	void noiseaudioplay();

	// �X�e�[�WSE�Đ�
	void pachincoseplay();

	// �X�e�[�W�I�u�W�F�N�g1�Đ�
	void charaobjseplay1();

	// �X�e�[�W�I�u�W�F�N�g2�Đ�
	void charaobjseplay2();

};