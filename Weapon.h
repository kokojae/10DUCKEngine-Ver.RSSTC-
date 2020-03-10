#pragma once
#include "GameObject.h"
class Weapon :
	public GameObject
{
public:
	D3DXVECTOR2* playerPos;
	D3DXVECTOR2* playerSca;
	float fireBetTime;

	void SetPosition();
	void SetTrans(D3DXVECTOR2* pos, D3DXVECTOR2* sca) { playerPos = pos; playerSca = sca; }
};

