#pragma once
#include "GameObject.h"

class Title : public GameObject
{
public:
	Title();
	~Title();

	LPDIRECT3DTEXTURE9 main;
	LPDIRECT3DTEXTURE9 startBtn;
	LPDIRECT3DTEXTURE9 optionBtn;

	float anitime;
	int idx;

	void Init() override;
	void Update() override;
	void Render() override;
};

