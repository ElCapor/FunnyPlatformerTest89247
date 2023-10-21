#ifndef ECSTESTSCENE_HPP
#define ECSTESTSCENE_HPP
#include <Core/Game/Scene.hpp>
/*

A simple scene to test ecs

*/
#include <Core/Sys/SysLog.hpp>
#include <Core/ECS/ecs.h>

ECS myECS;

class ECSTestScene : public Scene
{
public:
	// H�rit� via Scene
	void OnEnter() override
	{
		

	}
	void OnUpdate() override
	{

	}
	void OnDraw() override
	{
		

	}
	void OnExit() override
	{

	}
};
#endif // !GAMESCENE_HPP