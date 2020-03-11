#include "DXUT.h"
#include "Shotgun.h"
#include "10DUCKEngine.h"

void Shotgun::Init()
{
	SetTexture(L"resorce/player/Weapon/shotgun.png", { 56, 10 });
	texture.scale = { 2,2 };

	z = -10;
	collider.layer = Layer::WEAPON;
}

void Shotgun::Update()
{
	SetPosition();
	RotationToMouse();
}
