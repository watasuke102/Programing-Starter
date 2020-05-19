#pragma once

constexpr int WINDOW_WIDTH  = 600;
constexpr int WINDOW_HEIGHT = 400;
constexpr int SCENE_MAX     = 3;

#include <iostream>
#include <Siv3D.hpp>
#include "Button.h"

class _pages
{
	private:
		int scene = 0;
		Button next;
		Button back;
		CSVData languageList, editorList;
		////////////////////
		// Function
		void drawExplanation(String, String);
		void welcome();
		void selectLanguage();
		void selectEditor();

	public:
		_pages();
		void update();
};