#include "main.h"

void _checkLists::init(String n, String e)
{
	name=n;
	explanation=e;
	return;
}
void _checkLists::update(Vec2 pos)
{
	SimpleGUI::CheckBox(checked, U"", pos);
	pos.x += 50;
	FontAsset(U"text")(name).draw(pos);
	pos.x += 100;
	FontAsset(U"text")(explanation).draw(pos);
}