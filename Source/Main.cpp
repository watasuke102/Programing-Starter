#include "main.h"

void Main()
{
	Scene::SetBackground(Palette::Black);
	Window::Resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	Window::Centering();

	FontAsset::Register(U"big", 30);
	FontAsset::Register(U"text", 15);

	_pages pages;
	while (System::Update())
	{
		pages.update();
	}
}