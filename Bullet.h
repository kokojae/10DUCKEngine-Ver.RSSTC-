#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	D3DXVECTOR2 direction;
	float speed;

	void Init() override;
	void Update() override;

	void SetBullet(D3DXVECTOR2 a_direction, float a_speed);
};

