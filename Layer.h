#pragma once
class Layer
{
public:
	Layer();
	~Layer();

	const static int DEFAULT = 1 << 1;
	const static int BLOCK = 1 << 2;
	const static int PLAYER = 1 << 3;
	const static int WEAPON = 1 << 4;
	const static int BULLET = 1 << 5;
};

