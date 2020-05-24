#include "main.h"

void _checkLists::init(String n, String e, String c)
{
	checked = false;
	name=n; explanation=e; command=c;
}
void _checkLists::update(Vec2 pos)
{
	Rect a(pos.x, pos.y, 20);
	a.draw(ColorF(checked ? 1 : 0)).drawFrame(0, 2, Palette::White);
	if(a.leftClicked())
		checked = !checked;
	pos.x += 50;
	FontAsset(U"text")(name).draw(pos);
	pos.x += 100;
	FontAsset(U"text")(explanation).draw(pos);
}