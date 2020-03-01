#include "DXUT.h"
#include "TitleStartBtn.h"
#include "10DUCKEngine.h"

void TitleStartBtn::Init()
{
	SetTexture(L"resorce/background/scene/mainmenu/start_b.png", { 50,11 });
	texture.scale = { 10,10 };

	z = 3;
}

void TitleStartBtn::Update()
{
	if (isClicked(MouseInput::Key::Left))
		SceneManager::LoadScene(SceneManager::Scene::Stage1);
}
