#pragma once

constexpr int WINDOW_WIDTH  = 600;
constexpr int WINDOW_HEIGHT = 400;
constexpr int SCENE_MAX     = 3;

#include <Siv3D.hpp>
#include "Button.h"

class _pages
{
	private:
		int scene = 0;
		Button next;
		Button back;
		////////////////////
		// Function
		void drawExplanation(String, String);
		void welcome();
		void selectLanguage();
		void selectEditor();
		//std::function<void()> page[SCENE_MAX] =
		//{
		//	welcome,
		//	selectLanguage,
		//	selectEditor
		//};

	public:
		_pages();
		void update();
};