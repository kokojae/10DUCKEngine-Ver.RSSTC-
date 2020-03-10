#include "DXUT.h"
#include "Weapon.h"

void Weapon::SetPosition()
{
	position = *(playerPos);
	texture.scale = *(playerSca);
}
