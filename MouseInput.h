#pragma once
class GameObject;

class MouseInput
{
public:
	enum class Key { Left, Right, Middle, AnyKey };

	static bool leftButton;
	static bool rightButton;
	static bool middleButton;
	static D3DXVECTOR2 pos;
	static RECT rc;

	static RECT* GetRect();
};

