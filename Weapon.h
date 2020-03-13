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
	int bulletCount;
	float bulletSpread;
	float fireBetTime;	   
	float lastTime;

	virtual void Update() override;

	virtual void KeyInput() = 0;

	void RotationToMouse();
	void Fire();

	void SetPosition();
	void SetTrans(D3DXVECTOR2* pos) { playerPos = pos; }
	void SetBullet(float betTime, int count = 1, float spread = 0)
	{ bulletCount = count; bulletSpread = spread; fireBetTime = betTime; }
};

