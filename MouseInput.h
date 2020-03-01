#pragma once
class GameObject;

class MouseInput
{
public:
	enum class Key { Left, Right, Middle, Side1, Side2, AnyKey };

	static bool leftButton;
	static bool rightButton;
	static bool middleButton;
	static bool sideButton1;
	static bool sideButton2;
	static D3DXVECTOR2 pos;
};

