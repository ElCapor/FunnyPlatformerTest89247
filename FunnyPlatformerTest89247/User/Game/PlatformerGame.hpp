#ifndef PLATFORMERGAME_HPP
#define PLATFORMERGAME_HPP
/*
USER GAME CODE
*/
#include <Core/Game/Game.hpp>
#include <Core/Game/SceneManager.hpp>
#include <Core/Raylib/raylib-assert.h>
#include <User/Scenes/GameScene.hpp>
#include <User/Scenes/AnimationTestScene.hpp>

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