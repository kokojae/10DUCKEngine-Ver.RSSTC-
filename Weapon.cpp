#include "DXUT.h"
#include "Weapon.h"
#include "10DUCKEngine.h"

void Weapon::RotationToMouse()
{
	auto diff = MouseInput::pos - position;

	texture.rotation = D3DXToDegree(atan2(diff.y, diff.x));

	printf("Mouse  Pos : { %f,%f }\n", MouseInput::pos.x, MouseInput::pos.y);
	printf("Weapon Pos : { %f,%f }\n", position.x, position.y);
	printf("diff   Pos : { %f,%f }\n", diff.x, diff.y);
	printf("Degree : %f\n", texture.rotation);

	if (texture.rotation <= -90 && texture.rotation >= -180)
		texture.scale.y = -abs(texture.scale.y);
	if (texture.rotation >= 90 && texture.rotation <= 180)
		texture.scale.y = -abs(texture.scale.y);
	if (texture.rotation > -90 && texture.rotation < 90)
		texture.scale.y = abs(texture.scale.y);
}

void Weapon::SetPosition()
{
	position = *(playerPos);
}
