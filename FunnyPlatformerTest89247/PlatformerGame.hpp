#ifndef PLATFORMERGAME_HPP
#define PLATFORMERGAME_HPP
/*
USER GAME CODE
*/
#include "Game.hpp"
#include "SceneManager.hpp"
#include "raylib-assert.h"
#include "GameScene.hpp"

/*
TODO : IMPLEMENT SCENE MANAGER INSIDE THE BASE GAME CLASS , THE USER SHOULD ONLY NEED TO LOAD HIS OWN SCENE
*/
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