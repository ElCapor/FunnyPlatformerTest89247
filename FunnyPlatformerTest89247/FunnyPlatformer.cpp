/*

MAP EDITOR REWRITE ATTEMPT n°89247

*/
#include <raylib.h>
#include "raylib-assert.h"

#include <string>
#include <ostream>
#include <sstream>


#include <memory>
#include <map>


#ifndef SYSLOG_HPP
#define SYSLOG_HPP
/*
Simple MACRO log system
*/

#define INFO(text, ...) TraceLog(LOG_INFO, text, __VA_ARGS__)
#define WARN(text, ...) TraceLog(LOG_WARNING, text, __VA_ARGS__)
#define ERROR(text, ...) TraceLog(LOG_ERROR, text, __VA_ARGS__)

#ifdef _DEBUG
#define DEBUG(text, ...) TraceLog(LOG_DEBUG, text, __VA_ARGS__)
#else
#define DEBUG(text, ...)
#endif // _DEBUG_


#endif // !SYSLOG_HPP

#ifndef FLEXRECT_HPP
/*
An attempt at writing a flex rect system for the ui stuff
https://github.com/nezvers/GameSystemsInC/blob/master/FlexRect/flexrect.h
*/


#include <raylib.h>

class FlexRect {
public:
	FlexRect()
	{
		// empty constructor
	}
	FlexRect(Rectangle rect, float al, float at, float ar, float ab, int ml, int mt, int mr, int mb, int minw, int minh)
		: rect(rect), al(al), at(at), ar(ar), ab(ab), ml(ml), mt(mt), mr(mr), mb(mb), minw(minw), minh(minh), childCount(0), children(nullptr), parent(nullptr) {}

	~FlexRect() {
		for (int i = 0; i < childCount; i++) {
			delete children[i];
		}
		delete[] children;
	}

	FlexRect* CreateChild(float al, float at, float ar, float ab, int ml, int mt, int mr, int mb, int minw, int minh) {
		FlexRect* newChild = new FlexRect(FlexRectGetRect(rect, al, at, ar, ab, ml, mt, mr, mb, minw, minh), al, at, ar, ab, ml, mt, mr, mb, minw, minh);
		newChild->parent = this;

		FlexRect** old = children;
		children = new FlexRect * [childCount + 1];

		for (int i = 0; i < childCount; i++) {
			children[i] = old[i];
		}

		children[childCount] = newChild;

		if (childCount > 0) {
			delete[] old;
		}

		childCount++;

		return newChild;
	}

	void RemoveChild(FlexRect* child) {
		if (childCount < 1) {
			return;
		}
		else if (childCount == 1) {
			delete[] children;
			childCount = 0;
			children = nullptr;
			return;
		}

		FlexRect** old = children;
		children = new FlexRect * [childCount - 1];

		for (int i = 0, j = 0; i < childCount; i++) {
			if (old[i] != child) {
				children[j++] = old[i];
			}
		}

		delete[] old;
		childCount--;
	}

	void Resize(Rectangle newRect) {
		rect = FlexRectGetRect(newRect, al, at, ar, ab, ml, mt, mr, mb, minw, minh);
		for (int i = 0; i < childCount; i++) {
			children[i]->Resize(rect);
		}
	}

	void DrawBorder()
	{
		DrawRectangleLines(rect.x, rect.y, rect.width, rect.height, RED);
	}

	Rectangle GetRect()
	{
		return rect;
	}

private:
	Rectangle rect;
	float al, at, ar, ab;
	int ml, mt, mr, mb;
	int minw, minh;
	int childCount;
	FlexRect** children;
	FlexRect* parent;

	Rectangle FlexRectGetRect(Rectangle rect, float al, float at, float ar, float ab, int ml, int mt, int mr, int mb, int minw, int minh) {
		int x = static_cast<int>(rect.x + (rect.width * al) + ml);
		int y = static_cast<int>(rect.y + (rect.height * at) + mt);
		int w = static_cast<int>((rect.width - (rect.width * al) - ml - mr) * ar);
		int h = static_cast<int>((rect.height - (rect.height * at) - mt - mb) * ab);

		if (w < minw) {
			w = minw;
		}
		if (h < minh) {
			h = minh;
		}

		return { static_cast<float>(x), static_cast<float>(y), static_cast<float>(w), static_cast<float>(h) };
	}
};


#endif // !FLEXRECT_HPP


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

#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP
FlexRect flexRect1;
FlexRect* flexRectChild;
class GameScene : public Scene
{
public:
	// Hérité via Scene
	void OnEnter() override
	{
		Rectangle rect = {
			0,
			0,
			800,
			600
		};
		flexRect1 = FlexRect(rect, 0, 0, 1, 1, 10, 10, 10, 10, 0, 0);
		flexRectChild = flexRect1.CreateChild(0.0f, 0.0f, 1.0f, 0.5f, 10, 10, 10, 0, 300, 100);

	}
	void OnUpdate() override
	{

	}
	void OnDraw() override
	{
		flexRect1.DrawBorder();
		flexRectChild->DrawBorder();
	}
	void OnExit() override
	{

	}
};
#endif // !GAMESCENE_HPP


#ifndef GAME_HPP
/*

Rewrite of the Game System attempt n°2

*/
// Abstract game class
class Game {
public:
	int m_Width;
	int m_Height;
	const char* m_Name;
	Game(int w, int h, const char* n) : m_Width(w), m_Height(h), m_Name(n){}

	virtual void OnLoad() // on game load
	{
		InitWindow(m_Width, m_Height, m_Name);
		SetTargetFPS(60);
	}

	virtual void OnExit() // on exit
	{
		CloseWindow();
	}

	virtual void OnUpdate() // on update 
	{

	}

	virtual void OnDraw() // on draw
	{

	}

	virtual void Main() // main function
	{
		OnLoad();
		while (!WindowShouldClose())
		{
			OnUpdate();
			BeginDrawing();
			ClearBackground(RAYWHITE);
			OnDraw();
			EndDrawing();
		}
		OnExit();
	}
};
#endif // !GAME_HPP

#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP
/*

Scene Manager rewrite attempt n°2

*/

class SceneManager {
public:
	void AddScene(const std::string& name, std::unique_ptr<Scene> scene)
	{
		if (!IsSceneExist(name))
		{
			m_ScenesMap[name] = std::move(scene);
		}
		else {
			ERROR("%s , a scene under the same name already exists !", __FUNCTION__);
		}
	}

	void ChangeScene(const std::string& name)
	{	
		if (IsSceneExist(name))
		{
			if (m_CurrentScene != nullptr)
			{
				m_CurrentScene->OnExit();
			}
			m_CurrentScene = m_ScenesMap[name].get();
		}
		else {
			ERROR("%s , there is no scenes with the name %s !", __FUNCTION__, name.c_str());
		}
	}

	// check if a scene by this name exists
	bool IsSceneExist(const std::string& name)
	{
		return m_ScenesMap.find(name) != m_ScenesMap.end();
	}

	Scene* m_CurrentScene;
	std::map<std::string, std::unique_ptr<Scene>> m_ScenesMap;
};
#endif // !SCENEMANAGER_HPP


#ifndef PLATFORMERGAME_HPP
#define PLATFORMERGAME_HPP


class PlatformerGame : Game
{
public:
	PlatformerGame() : Game(800, 600, "Platformer Test") {}

	void OnLoad() override
	{
		INFO("Starting...");
		m_SceneManager = std::make_unique<SceneManager>();
		Assert(m_SceneManager != nullptr, "SceneManager was null");
		// base game stuff
		Game::OnLoad();
		Assert(IsWindowReady(), "Failed to create window !");

		m_SceneManager->AddScene("game", std::make_unique<GameScene>());
		Assert(m_SceneManager->m_ScenesMap.size() == 1, "Failed to add default scene");
		m_SceneManager->ChangeScene("game");
		Assert(m_SceneManager->m_CurrentScene != nullptr, "Failed to load default scene");
		// we can now safely assume that the scene exists
		m_SceneManager->m_CurrentScene->OnEnter();

		
		
	}

	void OnExit() override
	{
		INFO("Exiting...");
		// no asserts because the game wouldnt load at first if there was no scenes
		m_SceneManager->m_CurrentScene->OnExit();
		// base stuff
		Game::OnExit();
	}

	void OnUpdate() override
	{
		Game::OnUpdate();
		// add the scene system here
		m_SceneManager->m_CurrentScene->OnUpdate();
	}

	void OnDraw() override
	{
		Game::OnDraw();
		// add scene draw here
		m_SceneManager->m_CurrentScene->OnDraw();
	}

	void Main() override
	{
		Game::Main();
	}

private:
	std::unique_ptr<SceneManager> m_SceneManager;
};
#endif // !PLATFORMERGAME_HPP

PlatformerGame g_Game;

int main()
{
	g_Game.Main();
}