#pragma once
#include "../dxlib_ext/dxlib_ext_camera.h"

class GmCamera : public dxe::Camera {
public :
	GmCamera() : dxe::Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT) {}
	~GmCamera(){}

	// プレイ画面のカメラの角度
	tnl::Vector3 free_look_angle_xy_ = { tnl::ToRadian(10), 0, 0 };

	// プレイ画面のカメラの距離
	float target_distance_ = 1000;

	void update();
};

