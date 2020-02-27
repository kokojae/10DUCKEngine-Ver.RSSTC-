#pragma once
#include "GameObject.h"
class TitleBG :
	public GameObject
{
public:
	float betTime;

	void Init() override;
	void Update() override;

	void Animation();
};

