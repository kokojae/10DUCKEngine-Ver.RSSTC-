#pragma once
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static enum class Scene
	{
		Title, Stage1
	};

	static Scene current_scene;

	static void LoadScene(Scene scene, bool camera_clear = true);
};

