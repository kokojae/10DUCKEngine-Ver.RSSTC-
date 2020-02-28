#include "DXUT.h"
#include "TitleStartBtn.h"

void TitleStartBtn::Init()
{
	SetTexture(L"resorce/background/scene/mainmenu/start_b.png", { 50,11 });
	texture.scale = { 10,10 };

	z = 3;
}

void TitleStartBtn::Update()
{
}
