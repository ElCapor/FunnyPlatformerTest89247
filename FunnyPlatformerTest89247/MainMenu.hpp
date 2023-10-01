#ifndef MAINMENU_HPP
#define MAINMENU_HPP
/*
Drawing a main menu with the flexbox idk ?
*/
#include <raylib.h>
#include "FlexRect.hpp"
#include "raygui.h"
#include "cyber.h"
#include "SysLog.hpp"

// flex rects
FlexRect parentFlex;
FlexRect* logoRect;
FlexRect* buttonsRect;
// button flex
FlexRect* playBtnRect;
FlexRect* optionsBtnRect;
FlexRect* editorBtnRect;
FlexRect* quitBtnRec;
// textures
Texture2D logoImg;
Texture2D bg;


void InitMainMenu()
{
	Rectangle parentRect = {
		0,
		0,
		800,
		600
	};
	parentFlex = FlexRect(parentRect, 0, 0, 1, 1, 10, 10, 10, 10, 300, 100);
	// funny logo loading
	logoImg = LoadTexture("assets/logo.png");
	logoRect = parentFlex.CreateChild(0, 0, 1, 0, 10, 10, 10, 10, logoImg.width, logoImg.height);
	bg = LoadTexture("assets/professional_edit.png");
	// buttons
	buttonsRect = parentFlex.CreateChild(0.25, 0.25, 0.25, 0, 10, 10, 10, 10, 400, 400);
	playBtnRect = buttonsRect->CreateChild(0, 0, 1, 0.2, 30, 15, 30, 15, 40, 40);
	optionsBtnRect = buttonsRect->CreateChild(0, 0.2, 1, 0.3, 30, 30, 30, 30, 40, 40);
	editorBtnRect = buttonsRect->CreateChild(0, 0.5, 1, 0.5, 30, 15, 30, 30, 40, 40);
	quitBtnRec = buttonsRect->CreateChild(0, 0.75, 1, 1, 30, 15, 30, 15, 40, 40);
	GuiLoadStyleCyber();
	GuiSetStyle(DEFAULT, TEXT_SIZE, 32);
	// to do : find a fix to make the tools icon bigger

}

void DrawMainMenu()
{
	DrawTextureEx(bg, { 0,0 }, 0, 1.6, WHITE);
	/*
	parentFlex.DrawBorder();
	logoRect->DrawBorder();
	buttonsRect->DrawBorder();
	playBtnRect->DrawBorder();
	optionsBtnRect->DrawBorder();
	editorBtnRect->DrawBorder();
	quitBtnRec->DrawBorder();
	*/
	// math time bruh
	// centered x = logoRect->GetRect().x + (logoRect->GetRect().width - logoImg.width)/2
	DrawTexture(logoImg, logoRect->GetRect().x + (logoRect->GetRect().width - logoImg.width) / 2, logoRect->GetRect().y, WHITE);

	if (GuiButton(playBtnRect->GetRect(), "Play !"))
	{
		INFO("Let's play !");
	}


	if (GuiButton(optionsBtnRect->GetRect(), GuiIconText(ICON_TOOLS, " Options")))
	{
		INFO("Go to options please !");
	}

	if (GuiButton(editorBtnRect->GetRect(), "Editor"))
	{
		INFO("Level Editor please !");
	}

	if (GuiButton(quitBtnRec->GetRect(), "Quit"))
	{
		INFO("Quit");
	}
}

#endif