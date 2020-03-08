#include "DXUT.h"
#include "Background.h"
#include "10DUCKEngine.h"

void Background::Init()
{
	SetTexture(L"resorce/background/stage/stage1/stage1.png", { 1920,1080 });
	texture.center = { 0,0 };

	z = 10;
}
