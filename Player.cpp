#include "DXUT.h"
#include "Player.h"
#include "10DUCKEngine.h"

Player* Player::me = nullptr;

Player::Player()
{
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

	camera_position = position;
}

void Player::Update()
{
	GetKey();
	Hspeed();
	Gravity();
}

void Player::LateUpdate()
{
	CameraMove();
}

void Player::GetKey()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		SceneManager::LoadScene(SceneManager::Scene::InGame);
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (hspeed > -5)
			hspeed -= 0.5f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (hspeed < 5)
			hspeed += 0.5f;
	}
	if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
	{
		hspeed -= hspeed / 20;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		if (PlaceMeeting({ 0,10 }, Layer::BLOCK))
		{
			vspeed = -15;
		}
	}

	if (GetAsyncKeyState('W'))
		Camera::scale -= Camera::scale * 0.2;
	if (GetAsyncKeyState('S'))
		Camera::scale += Camera::scale * 0.2;
	if (GetAsyncKeyState('D'))
		Camera::rotation += 5;
	if (GetAsyncKeyState('A'))
		Camera::rotation -= 5;
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

void Player::CameraMove()
{
	camera_position += (position - camera_position) / 30;

	Camera::position = camera_position + D3DXVECTOR2((rand() % (int)Camera::shake.x - (int)Camera::shake.x / 2), (rand() % (int)Camera::shake.y - (int)Camera::shake.y / 2));

	Camera::scale += (1 - Camera::scale) / 10;
}
