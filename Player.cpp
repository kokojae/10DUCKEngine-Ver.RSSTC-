#include "DXUT.h"
#include "Player.h"
#include "10DUCKEngine.h"

Player* Player::me = nullptr;

Player::Player()
{
	betTime = 0.0f;

	tex_idle = nullptr;
	tex_move = nullptr;
	tex_jump = nullptr;
	tex_atk = nullptr;

	isJump = false;
}

Player::~Player()
{
}

void Player::Init()
{
	me = this;

	SetTexture(L"resorce/player/idle.png", { 100,100 });
	SetCollider({ 80,80 });

	tex_idle = TextureManager::LoadTexture(L"resorce/player/idle.png");
	tex_move = TextureManager::LoadTexture(L"resorce/player/move.png");
	tex_jump = TextureManager::LoadTexture(L"resorce/player/jump.png");
	tex_atk = TextureManager::LoadTexture(L"resorce/player/attack.png");

	z = -10;
	collider.layer = Layer::PLAYER;

	betTime = 0.0f;

	camera_position = position;

	ObjectManager::Instantiate<Shotgun>(position)->SetTrans(&position);
}

void Player::Update()
{
	GetKey();
	Hspeed();
	Gravity();
	Animation();
}

void Player::LateUpdate()
{
	CameraMove();
}

void Player::GetKey()
{
	if (GetAsyncKeyState('A'))
	{
		if (PlaceMeeting({ 0,10 }, Layer::BLOCK))
		{
			if (texture.texture != tex_move && !isJump)
			{
				texture.index = 0;
				texture.texture = tex_move;
			}
		}

		texture.scale.x = 1;

		if (hspeed > -5)
			hspeed -= 0.5f;
	}
	if (GetAsyncKeyState('D'))
	{
		if (texture.texture != tex_move && !isJump)
		{
			texture.index = 0;
			texture.texture = tex_move;
		}

		texture.scale.x = -1;

		if (hspeed < 5)
			hspeed += 0.5f;
	}
	if (!GetAsyncKeyState('A') && !GetAsyncKeyState('D'))
	{
		if (PlaceMeeting({ 0,10 }, Layer::BLOCK))
		{
			if (texture.texture != tex_idle)
			{
				texture.index = 0;
				texture.texture = tex_idle;
			}
		}

		hspeed -= hspeed / 20;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (PlaceMeeting({ 0,10 }, Layer::BLOCK))
		{
			if (texture.texture != tex_jump)
			{
				texture.index = 0;
				texture.texture = tex_jump;
				isJump = true;
			}

			vspeed = -15;
		}
	}
}

void Player::Hspeed()
{
	if (PlaceMeeting({ hspeed,0 }, Layer::BLOCK) != nullptr)
	{
		hspeed = 0;
	}
	else
	{
		position.x += hspeed;
	}
}

void Player::Gravity()
{
	vspeed += 0.5f;

	if (PlaceMeeting({ 0,vspeed }, Layer::BLOCK) != nullptr)
	{
		vspeed = 0;
	}
	else
	{
		position.y += vspeed;
	}
}

void Player::Animation()
{
	betTime += DXUTGetElapsedTime();

	if (betTime >= 0.2f)
	{
		betTime = 0;
		texture.index++;

		if (texture.texture == tex_idle)
		{
			if (texture.index >= 1)
			{
				texture.index = 0;
			}
		}
		if (texture.texture == tex_move)
		{
			if (texture.index >= 10)
			{
				texture.index = 0;
			}
		}
		if (texture.texture == tex_jump)
		{
			if (texture.index >= 5)
			{
				texture.index = 0;
				isJump = false;
			}
		}
		if (texture.texture == tex_atk)
		{
			if (texture.index >= 5)
			{
				texture.index = 0;
			}
		}
	}
}

void Player::CameraMove()
{
	camera_position += (position - camera_position) / 30;

	Camera::position = camera_position + D3DXVECTOR2((rand() % (int)Camera::shake.x - (int)Camera::shake.x / 2), (rand() % (int)Camera::shake.y - (int)Camera::shake.y / 2));

	Camera::scale += (1 - Camera::scale) / 10;
}
