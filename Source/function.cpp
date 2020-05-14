#include "main.h"

void _pages::drawExplanation(String title, String explanation)
{
	FontAsset(U"big") (title).draw(20, 10);
	FontAsset(U"text")(explanation).draw(20, 50);
}

///////////////////
// Page
//

_pages::_pages()
{
		next = Button(U"Next", 20, Point(WINDOW_WIDTH -  35, WINDOW_HEIGHT - 15), 70, 30);
		back = Button(U"Back", 20, Point(WINDOW_WIDTH - 120, WINDOW_HEIGHT - 15), 70, 30);
}
void _pages::update()
{
		//page[scene]();
		if (next.update())
		scene++;
		if(back.update()) scene--;
}