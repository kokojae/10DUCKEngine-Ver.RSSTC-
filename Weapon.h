#pragma once
#include "GameObject.h"
class Weapon :
	public GameObject
{
public:

	D3DXVECTOR2* playerPos = nullptr;
	D3DXVECTOR2 diff = { 0,0 };

	float bulletSpeed = 0;
	float bulletDestroyTime = 0;
	int bulletCount = 0;
	int bulletSpread = 0;

	float fireBetTime = 0;
	float lastTime = 0;

	void Update() override;

	virtual void KeyInput() = 0;
	virtual void PlaySFX() = 0;

	void RotationToMouse();
	void Fire();
	void SetPosition();

	void SetTrans(D3DXVECTOR2* pos) { playerPos = pos; }
	void SetBullet(float speed, float desTime, float betTime, int count = 1, int spread = 0);
};

