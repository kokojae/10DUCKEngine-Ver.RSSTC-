#pragma once
#include "GameObject.h"
class Weapon :
	public GameObject
{
public:
	Weapon()
	{
		playerPos = nullptr;
		bulletCount = 0;
		bulletSpread = 0;
		fireBetTime = 0;
		lastTime = 0;
	}

	D3DXVECTOR2* playerPos;
	D3DXVECTOR2 diff;

	float bulletSpeed;
	float bulletDestroyTime;
	int bulletCount;
	int bulletSpread;

	float fireBetTime;
	float lastTime;

	virtual void Update() override;

	virtual void KeyInput() = 0;

	void RotationToMouse();
	void Fire();
	void SetPosition();

	void SetTrans(D3DXVECTOR2* pos) { playerPos = pos; }
	void SetBullet(float speed, float desTime, float betTime, int count = 1, int spread = 0);
};

