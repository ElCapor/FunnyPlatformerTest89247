#ifndef SCENE_HPP
#define SCENE_HPP
/*

Scene System rewrite attempt n°2

*/
class Scene {
public:
	virtual void OnEnter() = 0; // On scene enter
	virtual void OnUpdate() = 0; // On scene update
	virtual void OnDraw() = 0; // on scene draw
	virtual void OnExit() = 0; // on scene exit
};

#endif