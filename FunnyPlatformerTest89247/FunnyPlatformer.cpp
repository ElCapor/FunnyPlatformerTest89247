/*

MAP EDITOR REWRITE ATTEMPT n°89247

*/
#include <raylib.h>
#include "raylib-assert.h"

#include <string>
#include <ostream>
#include <sstream>


#include <memory>
#include <map>


#ifndef SYSLOG_HPP
#define SYSLOG_HPP
/*
Simple MACRO log system
*/

#define INFO(text, ...) TraceLog(LOG_INFO, text, __VA_ARGS__)
#define WARN(text, ...) TraceLog(LOG_WARNING, text, __VA_ARGS__)
#define ERROR(text, ...) TraceLog(LOG_ERROR, text, __VA_ARGS__)

#ifdef _DEBUG
#define DEBUG(text, ...) TraceLog(LOG_DEBUG, text, __VA_ARGS__)
#else
#define DEBUG(text, ...)
#endif // _DEBUG_


#endif // !SYSLOG_HPP


#ifndef SCENE_HPP
#define SCENE_HPP
/*

Scene System rewrite attempt n°2

*/
class Scene {
public:
	virtual void OnEnter() = 0; // On scene enter
	virtual void OnUpdate() = 0; // On scene update
	virtual void OnDraw() = 0; // on scene draw
	virtual void OnExit() = 0; // on scene exit
};

#endif

#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP
class GameScene : public Scene
{
public:
	// Hérité via Scene
	void OnEnter() override
	{
		INFO(__FUNCTION__);
	}
	void OnUpdate() override
	{
		INFO(__FUNCTION__);

	}
	void OnDraw() override
	{
		INFO(__FUNCTION__);

	}
	void OnExit() override
	{
		INFO(__FUNCTION__);

	}
};
#endif // !GAMESCENE_HPP


#ifndef GAME_HPP
/*

Rewrite of the Game System attempt n°2

*/
// Abstract game class
class Game {
public:
	int m_Width;
	int m_Height;
	const char* m_Name;
	Game(int w, int h, const char* n) : m_Width(w), m_Height(h), m_Name(n){}

	virtual void OnLoad() // on game load
	{
		InitWindow(m_Width, m_Height, m_Name);
		SetTargetFPS(60);
	}

	virtual void OnExit() // on exit
	{
		CloseWindow();
	}

	virtual void OnUpdate() // on update 
	{

	}

	virtual void OnDraw() // on draw
	{

	}

	virtual void Main() // main function
	{
		OnLoad();
		while (!WindowShouldClose())
		{
			OnUpdate();
			BeginDrawing();
			ClearBackground(RAYWHITE);
			OnDraw();
			EndDrawing();
		}
		OnExit();
	}
};
#endif // !GAME_HPP

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
/*

Scene Manager rewrite attempt n°2

*/

class SceneManager {
public:
	void AddScene(const std::string& name, std::unique_ptr<Scene> scene)
	{
		if (!IsSceneExist(name))
		{
			m_ScenesMap[name] = std::move(scene);
		}
		else {
			ERROR("%s , a scene under the same name already exists !", __FUNCTION__);
		}
	}

	void ChangeScene(const std::string& name)
	{	
		if (IsSceneExist(name))
		{
			if (m_CurrentScene != nullptr)
			{
				m_CurrentScene->OnExit();
			}
			m_CurrentScene = m_ScenesMap[name].get();
		}
		else {
			ERROR("%s , there is no scenes with the name %s !", __FUNCTION__, name.c_str());
		}
	}

	// check if a scene by this name exists
	bool IsSceneExist(const std::string& name)
	{
		return m_ScenesMap.find(name) != m_ScenesMap.end();
	}

	Scene* m_CurrentScene;
	std::map<std::string, std::unique_ptr<Scene>> m_ScenesMap;
};
#endif // !SCENEMANAGER_HPP


#ifndef PLATFORMERGAME_HPP
#define PLATFORMERGAME_HPP

class PlatformerGame : Game
{
public:
	PlatformerGame() : Game(800, 600, "Platformer Test") {}

	void OnLoad() override
	{
		INFO("Starting...");
		m_SceneManager = std::make_unique<SceneManager>();
		Assert(m_SceneManager != nullptr, "SceneManager was null");
		// base game stuff
		Game::OnLoad();
		Assert(IsWindowReady(), "Failed to create window !");

		m_SceneManager->AddScene("game", std::make_unique<GameScene>());
		Assert(m_SceneManager->m_ScenesMap.size() == 1, "Failed to add default scene");
		m_SceneManager->ChangeScene("game");
		Assert(m_SceneManager->m_CurrentScene != nullptr, "Failed to load default scene");
		// we can now safely assume that the scene exists
		m_SceneManager->m_CurrentScene->OnEnter();
		
	}

	void OnExit() override
	{
		INFO("Exiting...");
		// no asserts because the game wouldnt load at first if there was no scenes
		m_SceneManager->m_CurrentScene->OnExit();
		// base stuff
		Game::OnExit();
	}

	void OnUpdate() override
	{
		Game::OnUpdate();
		// add the scene system here
		m_SceneManager->m_CurrentScene->OnUpdate();
	}

	void OnDraw() override
	{
		Game::OnDraw();
		// add scene draw here
		m_SceneManager->m_CurrentScene->OnDraw();
	}

	void Main() override
	{
		Game::Main();
	}

private:
	std::unique_ptr<SceneManager> m_SceneManager;
};
#endif // !PLATFORMERGAME_HPP

PlatformerGame g_Game;

int main()
{
	g_Game.Main();
}