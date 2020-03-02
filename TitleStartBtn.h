#pragma once
#include "GameObject.h"
class TitleStartBtn :
	public GameObject
{
public:
	void Init() override;
	void Update() override;
	void Render() override;
};

