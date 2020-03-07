#include "DXUT.h"
#include "TitleBG.h"
#include "10DUCKEngine.h"

void TitleBG::Init()
{
	SetTexture(L"resorce/background/scene/mainmenu/mainmenu.png", { 192,108 });
	texture.scale = { 10,10 };

	z = 10;

	betTime = 0;

	SoundManager::PlaySFX(L"resorce/sound/scene/mainmenu.wav", true);
}

void TitleBG::Update()
{
	Animation();
}

void TitleBG::Animation()
{
	betTime += DXUTGetElapsedTime();

	if (betTime >= 0.2f)
	{
		betTime = 0;
		texture.index++;

		if (texture.index >= 13)
		{
			texture.index = 0;
		}
	}
}
