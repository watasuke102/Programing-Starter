#include "main.h"

void _pages::drawExplanation(String title, String explanation)
{
	FontAsset(U"big") (title).draw(20, 10);
	FontAsset(U"text")(explanation).draw(20, 60);
}


_pages::_pages()
{
	next = Button(U"Next", 20, Point(WINDOW_WIDTH -  35, WINDOW_HEIGHT - 15), 70, 30);
	back = Button(U"Back", 20, Point(WINDOW_WIDTH - 120, WINDOW_HEIGHT - 15), 70, 30);
}
void _pages::update()
{
	switch(scene)
	{
		case 0: welcome();        break;
		case 1: selectLanguage(); break;
		case 2: selectEditor();   break;
	}
	if (next.update()) scene++;
	if (back.update()) scene--;
}

////////////////////////
// pages
//

void _pages::welcome()
{
	drawExplanation(
		U"Welcome to Programing Starter",
		U"This Wizard will setup programing enviroment\nto your computer."
	);
}
void _pages::selectLanguage()
{
}
void _pages::selectEditor()
{
}