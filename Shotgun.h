#pragma once
#include "Weapon.h"
class Shotgun :
	public Weapon
{
public:
	void Init() override;
	void Update() override;
};

