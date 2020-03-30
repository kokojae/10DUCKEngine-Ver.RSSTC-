#include "DXUT.h"
#include "Sans.h"
#include "10DUCKEngine.h"

void Sans::Init()
{
	SetTexture(L"resorce/UI/hp.png", { 150,150 });
}

void Sans::Update()
{
	target = ObjectManager::SearchObject(L"player");

	if (target != nullptr)
	{
		auto diff = target->position - position;
		D3DXVec2Normalize(&diff, &diff);
		position += diff;
	}
	else
	{
		auto diff = MouseInput::pos - position;
		D3DXVec2Normalize(&diff, &diff);
		position += diff;
	}
}
