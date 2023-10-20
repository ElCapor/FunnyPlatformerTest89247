#ifndef PLAYERENTITY_HPP
#define PLAYERENTITY_HPP
/*
Simple implementation of a player using the entity class
*/
#include "Entity.hpp"
#include "AnimationController.hpp"
#include "AnimationSheet.hpp"
class PlayerEntity : public Entity
{
public:
	AnimationController controller;

	enum {
		PLAYER_IDLE,
		PLAYER_WALK
	} PlayerState;
private:
	void LoadAnimations()
	{
		AnimationSheet walkSheet;
		walkSheet.FromXml("assets/walk.xml");
		AnimationClip walkClip = AnimationClip("walk", walkSheet.GetTextures());
		controller.AddClip(walkClip);

		AnimationClip idleClip = AnimationClip("idle", { LoadTexture("assets/stand.png") });
		controller.AddClip(idleClip);

		controller.SetAnimSpeed(10);
	}

	void UpdateAnimations()
	{
		switch (PlayerState)
		{
		case PLAYER_IDLE:
			controller.SetCurrentClip("idle");
			break;
		case PLAYER_WALK:
			controller.SetCurrentClip("walk");
			break;
		default:break;
		}
	}

	void HandleKeys()
	{
		if (IsKeyDown(KEY_LEFT))
		{
			this->velocity.x = -1;
		}
		else if (IsKeyDown(KEY_RIGHT)){
			this->velocity.x = 1;
		}
		else {
			this->velocity.x = 0;
		}
	}

	void UpdateState()
	{
		if (abs(velocity.x) > 0)
		{
			PlayerState = PLAYER_WALK;
		}
		else {
			PlayerState = PLAYER_IDLE;
		}
	}

	void UpdatePos()
	{
		this->position.x += this->velocity.x;
	}

	void DrawSprite()
	{
		// draw our player + flip quickfix
		Texture2D current = controller.GetCurrentTexture();
		Rectangle source = { 0,0, current.height, current.width };
		if (velocity.x < 0)
		{
			source.x = current.width;
			source.width = -current.width;
		}
		else if (velocity.x > 0){
			source.x = current.width;
			source.width = current.width;
		}

		DrawTextureRec(current, source, this->position, WHITE);

	}
public:

	void OnCreate() override
	{
		LoadAnimations();
		PlayerState = PLAYER_IDLE;
		controller.Play();
		this->position.x = 400;
		this->position.y = 200;
	}


	void Update() override
	{
		HandleKeys();
		UpdateState();
		UpdatePos();
		UpdateAnimations();
		controller.Update();
	}

	void Draw() override
	{
		DrawSprite();
	}

	void OnDestroy() override
	{

	}
	

};

#endif // !PLAYERENTITY_HPP
