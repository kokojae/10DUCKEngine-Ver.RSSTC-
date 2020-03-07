#include "DXUT.h"
#include "TitleOptionBtn.h"
#include "10DUCKEngine.h"

void TitleOptionBtn::Init()
{
	SetTexture(L"resorce/background/scene/mainmenu/option_b.png", { 59, 11 });
	texture.scale = { 10,10 };
	SetCollider({ 590,110 });

	z = 3;
}

void TitleOptionBtn::Update()
{
	if (isClicked(MouseInput::Key::Left))
	{
		SceneManager::LoadScene(SceneManager::Scene::Option);
	}
}
