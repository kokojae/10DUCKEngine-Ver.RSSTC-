#include "DXUT.h"
#include "SceneManager.h"
#include "10DUCKEngine.h"
#include <time.h>

SceneManager::Scene SceneManager::current_scene;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(Scene scene, bool camera_clear)
{
	srand(time(NULL));
	current_scene = scene;
	if (camera_clear)
	{
		Camera::position = { 0,0 };
		Camera::rotation = 0;
		Camera::scale = 1;
	}

	ObjectManager::Clear();

	switch (scene)
	{
	case SceneManager::Scene::Title:
		ObjectManager::Instantiate<TitleBG>();
		ObjectManager::Instantiate<TitleStartBtn>({ -650, -80 });
		ObjectManager::Instantiate<TitleOptionBtn>({ -600, 150 });
		break;
	case SceneManager::Scene::Stage1:
		ObjectManager::Instantiate<Text>({ 0,300 })->SetText(L"방향키 이동 WASD 카메라 조작\n씬이동 스페이스바", { 0.5,0.5 });
		ObjectManager::Instantiate<Text>({ 15,0 })->SetText(L"UI 텍스트 이렇게 쓰면됨", { 0.4,0.4 }, true);

		ObjectManager::Instantiate<Background>()->texture.camera_on = false;

		ObjectManager::Instantiate<Block>({ 0,100 });
		ObjectManager::Instantiate<Block>({ 1000,-100 });
		ObjectManager::Instantiate<Player>();
		break;
	case SceneManager::Scene::Option:
		ObjectManager::Instantiate<OptionBG>();
		ObjectManager::Instantiate<OptionRetBtn>({ 110 - SCREEN_WIDTH / 2,110 - SCREEN_HEIGHT / 2 });
		break;
	default:
		break;
	}
}
