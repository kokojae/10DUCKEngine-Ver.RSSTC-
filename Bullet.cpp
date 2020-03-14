#include "DXUT.h"
#include "Bullet.h"

void Bullet::Init()
{
	SetTexture(L"resorce/player/bullet.png", { 6,2 }, { 10,10 });
}

void Bullet::Update()
{

}

void Bullet::SetBullet(D3DXVECTOR2 a_direction, float a_speed)
{
}
