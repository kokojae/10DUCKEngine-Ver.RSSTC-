#pragma once
#include "GameObject.h"
class Weapon :
	public GameObject
{
public:
	D3DXVECTOR2* playerPos;
	float fireBetTime;
	   
	void RotationToMouse();

	void SetPosition();
	void SetTrans(D3DXVECTOR2* pos) { playerPos = pos; }
};

