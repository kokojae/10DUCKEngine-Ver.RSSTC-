#pragma once
#include "Weapon.h"
class Machinegun :
	public Weapon
{
public:
	void Init() override;

	void KeyInput() override;
	void PlaySFX() override;
};

