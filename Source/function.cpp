#include "main.h"

void drawExplanation(String title, String explanation)
{
	FontAsset(U"big")(title).draw(20, 10);
	FontAsset(U"text")(explanation).draw(20, 50);
}

void drawString(String s, Vec2 pos, bool useBigFont=false)
{
	FontAsset(useBigFont ? U"big" : U"text")(s).draw(pos);
}