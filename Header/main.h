#pragma once

constexpr int WINDOW_WIDTH  = 600;
constexpr int WINDOW_HEIGHT = 400;
constexpr int SCENE_MAX     = 3;

#include <Siv3D.hpp>
#include "Button.h"

extern void drawExplanation(String, String);
extern void drawString(String, Vec2, bool);

class _pages
{
	private:
		int scene = 0;
		Button next;
		Button back;
		////////////////////
		// Function
		void welcome()
		{
			drawExplanation(
				U"Welcome to Programing Starter",
				U"This Wizard will setup programing enviroment\nto your computer.");
		}
		void selectLanguage()
		{
		}
		void selectEditor()
		{
		}
		//void (*page[SCENE_MAX])()=
		//{
		//	welcome,
		//	selectLanguage,
		//	selectEditor
		//};
	public:
		_pages()
		{
			next = Button(U"Next", 20, Point(WINDOW_WIDTH -  35, WINDOW_HEIGHT - 15), 70, 30);
			back = Button(U"Back", 20, Point(WINDOW_WIDTH - 120, WINDOW_HEIGHT - 15), 70, 30);
		}
		void update()
		{
			//page[scene]();
			if (next.update())
				scene++;
			if(back.update()) scene--;
		}
};