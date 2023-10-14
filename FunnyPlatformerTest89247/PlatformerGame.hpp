#ifndef PLATFORMERGAME_HPP
#define PLATFORMERGAME_HPP
/*
USER GAME CODE
*/
#include "Game.hpp"
#include "SceneManager.hpp"
#include "raylib-assert.h"
#include "GameScene.hpp"
#include "AnimationTestScene.hpp"

class PlatformerGame : Game
{
public:
	PlatformerGame() : Game(800, 600, "Platformer Test") {}

	void OnLoad() override
	{
		INFO("Starting...");
		// base game stuff
		Game::OnLoad();
		MakeDefaultScene<AnimationTestScene>("game");
	}

	void OnExit() override
	{
		INFO("Exiting...");
		// base stuff
		Game::OnExit();
	}

	void OnUpdate() override
	{
		Game::OnUpdate();
		
	}

	void OnDraw() override
	{
		Game::OnDraw();
		
	}

	void Main() override
	{
		Game::Main();
	}

private:
	std::unique_ptr<SceneManager> m_SceneManager;
};
#endif // !PLATFORMERGAME_HPP