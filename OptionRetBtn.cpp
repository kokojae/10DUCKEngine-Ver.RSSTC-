#include "DXUT.h"
#include "OptionRetBtn.h"
#include "10DUCKEngine.h"

void OptionRetBtn::Init()
{
	SetTexture(L"resorce/background/scene/option/backmainmenu.png", { 200,200 });
	SetCollider({ 200,200 });
}

void OptionRetBtn::Update()
{
	if (isClicked(MouseInput::Key::Left))
	{
		SceneManager::LoadScene(SceneManager::Scene::Title);
	}
}
