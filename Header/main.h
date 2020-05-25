#pragma once

constexpr int WINDOW_WIDTH  = 600;
constexpr int WINDOW_HEIGHT = 400;
constexpr int SCENE_MAX     = 5;

#include <iostream>
#include <Siv3D.hpp>
#include "Button.h"

class _checkLists
{
	private:
		bool checked;
		String name, explanation, command;
	public:
		_checkLists() { checked = false; }
		void init(String, String, String);
		void update(Vec2);
		bool check() { return checked; }
		String getCommand() { return command; }
		String getName() { return name; }
};

class _pages
{
	private:
		int scene = 0;
		bool initialized = false;
		String installList, command;//yay -S (command) --noconfirm
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
		void showInstallList();
		void finishWizard();

	public:
		_pages();
		void update();
};