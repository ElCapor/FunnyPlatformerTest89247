/*

MAP EDITOR REWRITE ATTEMPT n°89247

*/
#pragma warning(disable:4996)
#include "cyber.h"

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include "raylib-assert.h"
#include "raygui.h"

#include <string>
#include <ostream>
#include <sstream>


#include <memory>
#include <map>

/*
Custom Modules
*/
#include "PlatformerGame.hpp"

PlatformerGame g_Game;

int main()
{
	g_Game.Main();
}