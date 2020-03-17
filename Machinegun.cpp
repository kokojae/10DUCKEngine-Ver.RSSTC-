#include "DXUT.h"
#include "Machinegun.h"
#include "10DUCKEngine.h"

void Machinegun::Init()
{
	SetTexture(L"resorce/player/Weapon/shotgun.png", { 56, 10 }, { 2,2 });

	z = -10;
	collider.layer = Layer::WEAPON;

	SetBullet(1700, 1, 0.1, 1, 10);
}

void Machinegun::KeyInput()
{
	if (MouseInput::leftButton)
	{
		Fire();
	}
}

void Machinegun::PlaySFX()
{
	SoundManager::PlaySFX(L"resorce/sound/player/shoot.wav");
}
