#include "main.h"

void Main()
{
	Scene::SetBackground(Palette::Black);
	Window::Resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	Window::Centering();

	FontAsset::Register(U"big", 30);
	FontAsset::Register(U"text", 20);

	Button next(U"Next", 20, Point(WINDOW_WIDTH -  35, WINDOW_HEIGHT - 15), 70, 30);
	Button back(U"Back", 20, Point(WINDOW_WIDTH - 120, WINDOW_HEIGHT - 15), 70, 30);
	int scene=0;
	void (*wizard[])()=
	{
		welcome,
		selectLanguage,
		selectEditor
	};
	while (System::Update())
	{
		wizard[scene]();
		if(next.update()) scene++;
		if(back.update()) scene--;
	}
}

void welcome()
{
	drawExplanation(
		U"Welcome to Programing Starter",
		U"This Wizard will setup programing enviroment\nto your computer."
	);
}
void selectLanguage()
{
}
void selectEditor()
{
}