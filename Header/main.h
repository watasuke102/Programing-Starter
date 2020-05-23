#pragma once

constexpr int WINDOW_WIDTH  = 600;
constexpr int WINDOW_HEIGHT = 400;
constexpr int SCENE_MAX     = 3;

#include <iostream>
#include <Siv3D.hpp>
#include "Button.h"

class _checkLists
{
	private:
		bool checked;
		String name, explanation;
	public:
		_checkLists() { checked = false; }
		void init(String, String);
		void update(Vec2);
};

class _pages
{
	private:
		int scene = 0;
		bool initialized = false;
		Button next;
		Button back;
		Array<_checkLists> checklist;
		////////////////////
		// Function
		void drawExplanation(String, String);
		void loadList();

		void welcome();
		void selectLanguage();
		void selectEditor();

	public:
		_pages();
		void update();
};