#ifndef ANIMATIONCLIP_H
#define ANIMATIONCLIP_H
/*
Attempt at writing an animation system.
I'm 200% sure this is the worst way to make an animation system
*/
#include <raylib.h>
#include <string>
#include <vector>
class AnimationClip
{
public:
	std::string name; // name of the animation
	std::vector<Texture2D> frames; // all the frames of the animation

	AnimationClip()
	{
		name = "";
		frames = {};
	}

	AnimationClip(std::string name, std::vector<Texture2D> frames)
	{
		this->name = name;
		this->frames = frames;
	}
};
#endif