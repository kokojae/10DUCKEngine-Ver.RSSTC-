#pragma once
#include "GameObject.h"
class Sans :
	public GameObject
{
public:
	GameObject* target;

	void Init()override;
	void Update()override;
};

