#include "main.h"


_pages::_pages()
{
	next = Button(U"Next", 20, Point(WINDOW_WIDTH -  35, WINDOW_HEIGHT - 15), 70, 30);
	back = Button(U"Back", 20, Point(WINDOW_WIDTH - 120, WINDOW_HEIGHT - 15), 70, 30);
}
void _pages::update()
{
	switch (scene)
	{
		case 0: welcome();        break;
		case 1: selectLanguage(); break;
		case 2: selectEditor();   break;
	}
	if (next.update()) {scene++; loadList();}
	if (back.update()) {scene--; loadList();}
	scene = Clamp(scene, 0, SCENE_MAX-1);
}
void _pages::drawExplanation(String title, String explanation)
{
	FontAsset(U"big") (title).draw(20, 10);
	FontAsset(U"text")(explanation).draw(20, 60);
}
void _pages::loadList()
{
	JSONReader json;
	switch (scene)
	{
		case  1: json.open(U"Data/languageList.json"); break;
		case  2: json.open(U"Data/editorList.json");   break;
		default: return;
	}
	if(json.isEmpty()) return;
	int i = 0;
	checklist.resize(json[U"Items"].arrayCount());
	for (const auto &obj : json[U"Items"].arrayView())
	{
		checklist[i].init(obj[U"name"].getString(), obj[U"description"].getString());
		i++;
	}
}

////////////////////////
// pages
//

void _pages::welcome()
{
	drawExplanation(
		U"Welcome to Programing Starter",
		U"This wizard will setup programing enviroment\nto your computer."
	);
}
void _pages::selectLanguage()
{
	drawExplanation(
		U"Select Programing Language",
		U"Check your favorite programing language. "
	);
	for(auto i:step(checklist.size()))
		checklist[i].update(Vec2(50, 150+ 30*i));
}
void _pages::selectEditor()
{
	drawExplanation(
		U"Select Text Editor",
		U"Check your favorite text editor. "
	);
	for(auto i:step(checklist.size()))
		checklist[i].update(Vec2(50, 150+ 30*i));
}