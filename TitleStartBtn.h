#pragma once
#include "GameObject.h"
class TitleStartBtn :
	public GameObject
{
public:
	float betTime;

	void Init() override;
	void Update() override;
};

