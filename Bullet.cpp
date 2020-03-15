#include "DXUT.h"
#include "Bullet.h"

void Bullet::Init()
{
	SetTexture(L"resorce/player/weapon/bullet.png", { 6,2 }, { 5,5 });

	z = -5;
	collider.layer = Layer::BULLET;

	nowTime = 0;
}

void Bullet::Update()
{
	nowTime += DXUTGetElapsedTime();

	if (nowTime >= destroyTime)
	{
		destroy = true;
		destroy_me = true;
	}
	else
	{
		position += (direction * (speed * DXUTGetElapsedTime()));
	}
}

void Bullet::SetBullet(D3DXVECTOR2* a_direction, float a_speed, float a_time)
{
	direction = *a_direction;
	speed = a_speed;
	destroyTime = a_time;

	texture.rotation = D3DXToDegree(atan2(direction.y, direction.x));

	if (texture.rotation <= -90 && texture.rotation >= -180)
		texture.scale.y = -abs(texture.scale.y);
	if (texture.rotation >= 90 && texture.rotation <= 180)
		texture.scale.y = -abs(texture.scale.y);
	if (texture.rotation > -90 && texture.rotation < 90)
		texture.scale.y = abs(texture.scale.y);
}
