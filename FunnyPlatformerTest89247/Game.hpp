#ifndef GAME_HPP
/*

Rewrite of the Game System attempt n°2

*/
#include <raylib.h>

// Abstract game class
class Game {
public:
	int m_Width;
	int m_Height;
	const char* m_Name;
	Game(int w, int h, const char* n) : m_Width(w), m_Height(h), m_Name(n) {}

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