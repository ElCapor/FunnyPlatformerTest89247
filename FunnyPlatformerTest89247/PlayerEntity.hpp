#ifndef PLAYERENTITY_HPP
#define PLAYERENTITY_HPP
/*
Simple implementation of a player using the entity class
*/
#include "Entity.hpp"
#include "AnimationController.hpp"
class PlayerEntity : public Entity
{
public:
	AnimationController controller;
public:

	void OnCreate() override
	{
		
	}


	void Update() override
	{

	}

	void Draw() override
	{

	}

	void OnDestroy() override
	{

	}
	

};

#endif // !PLAYERENTITY_HPP
