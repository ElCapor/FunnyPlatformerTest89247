#ifndef PLAYERFUNNYSCENE_HPP
#define PLAYERFUNNYSCENE_HPP
#include "Scene.hpp"
/*
Demo of a entity player with animations
*/
#include "PlayerEntity.hpp"

class PlayerFunnyScene : public Scene
{
	PlayerEntity player;
public:

	void OnEnter() override
	{
		player.OnCreate();

	}
	void OnUpdate() override
	{
		player.Update();
	}
	void OnDraw() override
	{
		
		player.Draw();
	}
	void OnExit() override
	{
		player.OnDestroy();
	}
};
#endif // !GAMESCENE_HPP