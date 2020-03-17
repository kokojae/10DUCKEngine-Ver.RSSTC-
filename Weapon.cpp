#include "DXUT.h"
#include "Weapon.h"
#include "10DUCKEngine.h"
#include <time.h>

void Weapon::Update()
{
	SetPosition();
	RotationToMouse();
	KeyInput();
	lastTime += DXUTGetElapsedTime();
}

void Weapon::RotationToMouse()
{
	diff = MouseInput::pos - position;

	texture.rotation = D3DXToDegree(atan2(diff.y, diff.x));

	if (texture.rotation <= -90 && texture.rotation >= -180)
		texture.scale.y = -abs(texture.scale.y);
	if (texture.rotation >= 90 && texture.rotation <= 180)
		texture.scale.y = -abs(texture.scale.y);
	if (texture.rotation > -90 && texture.rotation < 90)
		texture.scale.y = abs(texture.scale.y);
}

void Weapon::Fire()
{
	if (lastTime >= fireBetTime)
	{
		lastTime = 0;

		for (int i = 0; i < bulletCount; i++)
		{
			float x = 0;
			float y = 0;
			if (bulletSpread)
			{
				x = rand() % bulletSpread;
				if (rand() % 2)
					x = -x;
				y = rand() % bulletSpread;
				if (rand() % 2)
					y = -y;
			}
			auto vec = diff + D3DXVECTOR2(x, y);
			ObjectManager::Instantiate<Bullet>(position)->SetBullet(D3DXVec2Normalize(&D3DXVECTOR2(), &vec), bulletSpeed, bulletDestroyTime);
			PlaySFX();
		}
	}
}

void Weapon::SetPosition()
{
	position = *(playerPos);
}

void Weapon::SetBullet(float speed, float desTime, float betTime, int count, int spread)
{
	bulletSpeed = speed;
	bulletDestroyTime = desTime;
	bulletCount = count;
	bulletSpread = spread;
	fireBetTime = betTime;
}
