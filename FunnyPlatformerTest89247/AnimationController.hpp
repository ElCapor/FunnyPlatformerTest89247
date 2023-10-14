#ifndef ANIMATIONCONTROLLER_HPP
#define ANIMATIONCONTROLLER_HPP
// Attempt at writing a controller that can be used with entities to render animations
// 500% sure i'm writing bad code but whatever

/*
ALL OF THIS NEEDS A REFACTORING AT SOME POINT
HOWEVER EVERYTHING WILL BE SHOWN IN THE DOCS.
*/
#include <raylib.h>
#include "AnimationClip.h"
#include "SysLog.hpp"
class AnimationController {
public:
	float frameCounter; // counting frames
	int cFrameIndex; // current frame index
	std::vector<AnimationClip> clips; // all the animation clips the user needs in a specific entity
	// todo : replace this with a pointer , because for some reasons it doesnt want to work when i use a pointer
	AnimationClip currentClip;
	bool isPLaying;
	bool isPaused;

	int cSpeedFactor = 5; // speed factor , by default 5
	AnimationController()
	{
		ResetFrameCounter();
		ResetFrameIndex();
		currentClip = {};
		clips = {};
	}

	void ResetFrameCounter()
	{
		this->frameCounter = 0;
	}
	void ResetFrameIndex()
	{
		this->cFrameIndex = 0;
	}

	void SetCurrentClip(std::string name)
	{
		for (auto clip : clips)
		{
			if (clip.name == name)
			{
				this->currentClip = clip;
				INFO("Found clip");
			}
		}
	}

	void SetAnimSpeed(int speedFactor)
	{
		this->cSpeedFactor = speedFactor;
	}

	// update the frameCounter
	void StepFrameCounterAndFrameIndex()
	{
		// we shouldnt need to check if it's paused or not because update already does that
		frameCounter += GetFrameTime() * cSpeedFactor;
		
		cFrameIndex = fmodf(round(frameCounter), currentClip.frames.size());
	}

	void Update()
	{
		if (currentClip.name != "")
		{
			if (!isPaused && isPLaying)
			{
				StepFrameCounterAndFrameIndex();
				INFO("STEP : %f , %d", frameCounter, cFrameIndex);
			}
		}
	}

	void Play()
	{
		this->isPLaying = true;
		INFO("Start playing anim...");
	}

	void Stop()
	{
		this->isPLaying = false;
	}

	void Pause()
	{
		this->isPaused = true;
	}
	void Resume()
	{
		this->isPaused = false;
	}


	void AddClip(AnimationClip clip)
	{
		for (auto cclip : clips)
		{
			if (cclip.name == clip.name)
			{
				ERROR("Can't add clip %s : An animation clip already exists under the same name", cclip.name);
				return;
			}
		}
		this->clips.push_back(clip);
		return;
	}

	void RemoveClip(std::string name)
	{
		for (int i = 0; i < clips.size(); i++)
		{
			if (clips[i].name == name) // normally there is no duplicates accordin to the definition of addclip
			{
				clips.erase(clips.begin() + i);
				return;
			}
		}
		ERROR("Failed to remove clip %s : Clip doesnt exist", name);
	}


	Texture2D GetCurrentTexture()
	{
		if (currentClip.name != "")
		{
			return currentClip.frames[cFrameIndex];
		}
		return {};
	}
};

#endif