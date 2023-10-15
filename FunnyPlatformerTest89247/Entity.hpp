#ifndef ENTITY_HPP
#define ENTITY_HPP
/*
A simple (trash) implementation of an entity system

TODO :
Add functions like : IsCollidingWithOtherEntity

Maybe add something like a "tag" to entities ?
perhaps a number index or a name

or maybe it should be managed by something like entity manager ?
which handle gravity etc
*/
#include <raylib.h>


class Entity {
public:
	Vector2 position; // the position of our entity , origin will be at bottom left
	Vector2 size; // the size , width height
	Vector2 velocity; // the velocity (the speed at which it moves in the space)
public:
	Entity()
	{

	}

	virtual void OnCreate() // the function that will be called when our entity is created
	{
		
	}

	virtual void Update() // what should our entity do each frame
	{

	}

	virtual void Draw() // what should our entity look like
	{

	}

	virtual void OnDestroy() // what happens when our entity is destroyed (die ?)
	{

	}
};
#endif