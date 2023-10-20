/*

MAP EDITOR REWRITE ATTEMPT n°89247

*/
#pragma warning(disable:4996)
#include <Core/Raylib/cyber.h>

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <Core/Raylib/raylib-assert.h>
#include <Core/Raylib/raygui.h>

#include <string>
#include <ostream>
#include <sstream>


#include <memory>
#include <map>

/*
Custom Modules
*/
#include <User/Game/PlatformerGame.hpp>

PlatformerGame g_Game;

int main()
{
	g_Game.Main();
}