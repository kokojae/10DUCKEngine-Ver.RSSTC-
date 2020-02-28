#include "DXUT.h"
#include "TitleOptionBtn.h"

void TitleOptionBtn::Init()
{
	SetTexture(L"resorce/background/scene/mainmenu/option_b.png", { 59, 11 });
	texture.scale = { 10,10 };

	z = 3;
}

void TitleOptionBtn::Update()
{
}
