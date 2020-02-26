#include "DXUT.h"
#include "Title.h"
#include "10DUCKEngine.h"

Title::Title()
{
}

Title::~Title()
{
}

void Title::Init()
{
	SetTexture(L"resorce/background/scene/mainmenu/mainmenu.png", { 192,108 });
	texture.scale = { 10,10 };

	main = TextureManager::LoadTexture(L"resorce/background/scene/mainmenu/mainmenu.png");
	startBtn = TextureManager::LoadTexture(L"resorce/background/scene/mainmenu/start_b.png");
	optionBtn = TextureManager::LoadTexture(L"resorce/background/scene/mainmenu/option_b.png");

	anitime = 0;
}

void Title::Update()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		SoundManager::EndSFX();
		SceneManager::LoadScene(SceneManager::Scene::Stage1);
	}
}

void Title::Render()
{
	GameObject::Render();

	//anitime += DXUTGetElapsedTime();
	//if (anitime >= 0.2f)
	//{
	//	anitime = 0;
	//	idx++;

	//	if (idx >= 13)
	//		idx = 0;
	//}

	//texture.texture = main;
	//texture.size = { 192,108 };
	//texture.center = texture.size / 2;
	//texture.scale = { 10,10 };
	//texture.index = idx;
	//GraphicManager::TextureRender(texture, { 0,0 });
}
