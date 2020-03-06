#include "DXUT.h"
#include "MouseInput.h"
#include "10DUCKEngine.h"

bool MouseInput::leftButton = false;
bool MouseInput::rightButton = false;
bool MouseInput::middleButton = false;
D3DXVECTOR2 MouseInput::pos = { 0,0 };
RECT MouseInput::rc = { 0,0,0,0 };

RECT* MouseInput::GetRect()
{
	LONG x = static_cast<LONG>(pos.x);
	LONG y = static_cast<LONG>(pos.y);

	rc = { x - 1,y - 1,x + 1,y + 1 };

	return &rc;
}
