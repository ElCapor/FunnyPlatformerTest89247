#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP
#include "Scene.hpp"

class GameScene : public Scene
{
public:
	// Hérité via Scene
	void OnEnter() override
	{
		//InitMainMenu(); -> this will be moved to MainMenuScene

	}
	void OnUpdate() override
	{

	}
	void OnDraw() override
	{
		//DrawMainMenu(); -> this will be moved to main menu scene

	}
	void OnExit() override
	{

	}
};
#endif // !GAMESCENE_HPP