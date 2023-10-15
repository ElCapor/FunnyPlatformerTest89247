#ifndef ANIMATIONTESTSCENE_HPP
#define ANIMATIONTESTSCENE_HPP
/*
A simple demo scene to showcase the Animation System

Press space to pause the animation
Press Key UP and Key DOWN to Increase/Decrease animation speed

TODO:
Make a ui with raygui & ability to test other animations
*/
#include "Scene.hpp"
#include "SysLog.hpp"
#include "AnimationController.hpp"
#include "AnimationSheet.hpp"

std::vector<Texture2D> LoadGarfieldTextures()
{
	std::string baseName;
	baseName = "assets/garfield_idle_";
	std::vector<Texture2D> result;
	for (int i = 0; i < 6; i++)
	{
		baseName += std::to_string(i) + ".png";
		result.push_back(LoadTexture(baseName.c_str()));
		baseName = "assets/garfield_idle_";
	}
	return result;
}
class AnimationTestScene : public Scene
{
	AnimationController controller;
	AnimationClip garfield;
	int speedFactor = 5;

	AnimationSheet sheet;
public:
	// Hérité via Scene
	void OnEnter() override
	{
		//InitMainMenu(); -> this will be moved to MainMenuScene
		this->sheet.FromXml("assets/walk.xml");
		garfield = AnimationClip("idle", LoadGarfieldTextures());
		controller.AddClip(garfield);
		controller.SetCurrentClip("idle");
		controller.Play();
		controller.SetAnimSpeed(speedFactor);
	}
	void OnUpdate() override
	{
		switch (GetKeyPressed())
		{
		case KEY_SPACE:
			controller.isPaused = !controller.isPaused;
			break;
		case KEY_UP:
			++speedFactor;
			controller.SetAnimSpeed(speedFactor);
			break;
		case KEY_DOWN:
			--speedFactor;
			controller.SetAnimSpeed(speedFactor);
			break;

		default:break;

		}

		controller.Update();

	}
	void OnDraw() override
	{
		//DrawMainMenu(); -> this will be moved to main menu scene
		DrawTexture(controller.GetCurrentTexture(), 400, 200, WHITE);

	}
	void OnExit() override
	{

	}
};
#endif // !GAMESCENE_HPP