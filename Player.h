#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	static Player* me;

	float vspeed = 0;
	float hspeed = 0;
	float betTime;

	LPDIRECT3DTEXTURE9 tex_idle;
	LPDIRECT3DTEXTURE9 tex_move;
	LPDIRECT3DTEXTURE9 tex_jump;
	LPDIRECT3DTEXTURE9 tex_atk;

	D3DXVECTOR2 camera_position;

	void Init();
	void Update();
	void LateUpdate();

	void GetKey();
	void Hspeed();
	void Gravity();
	void Animation();
	void CameraMove();
};

