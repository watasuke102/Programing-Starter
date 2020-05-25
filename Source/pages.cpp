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
		case 0: welcome();         break;
		case 1: selectLanguage();  break;
		case 2: selectEditor();    break;
		case 3: showInstallList(); break;
		case 4: finishWizard();    break;
	}
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
		checklist[i].init(
			obj[U"name"].getString(),
			obj[U"description"].getString(),
			obj[U"command"].getString()
		);
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
	if (next.update()) {scene++; loadList();}
}
void _pages::selectLanguage()
{
	drawExplanation(
		U"Select Programing Language",
		U"Check your favorite programing language. "
	);
	for(auto i:step(checklist.size()))
		checklist[i].update(Vec2(50, 150+ 30*i));

	if (next.update())
	{
		//コマンドリストなどを初期化しておく
		installList.clear(); command.clear();

		for (auto i : step(checklist.size()))
		{
			if(checklist[i].check())
			{
				//チェックが入っている項目をインストールリストに追加
				installList += checklist[i].getName() + U", ";
					command += checklist[i].getCommand() + U' ';
			}
		}
		scene++; loadList();
	}
	if (back.update()) {scene--; loadList();}
}
void _pages::selectEditor()
{
	drawExplanation(
		U"Select Text Editor",
		U"Check your favorite text editor. "
	);
	for(auto i:step(checklist.size()))
		checklist[i].update(Vec2(50, 150+ 30*i));

	if (next.update())
	{
		for(auto i:step(checklist.size()))
		{
			if(checklist[i].check())
			{
				//チェックが入っている項目をインストールリストに追加
				installList += checklist[i].getName() + U", ";
					command += checklist[i].getCommand() + U' ';
			}
			//最後なら","を削除する
			if(i == checklist.size()-1)
				installList[installList.size() - 2]=U' ';
		}
		scene++; loadList();
	}
	if (back.update()) {scene--; loadList();}
}

void _pages::showInstallList()
{
	drawExplanation(
		U"Check Your Choice",
		U"This wizard will install these softwares."
	);
	FontAsset(U"text")(U"{}\n(package: {})"_fmt(installList, command))
		.draw(Rect(20, 100, 450));
	if (next.update())
	{
		String tmp = U"yay -Syu --noconfirm; yay -S {} --noconfirm"_fmt(command);
		Print << U"\n\n\n\n\n" << tmp;
		std::string run = tmp.narrow();
		//system(run.c_str());
		scene++; loadList();
	}
	if (back.update()) {scene--; loadList();}
}
void _pages::finishWizard()
{
	drawExplanation(
		U"Finish Installing",
		U"This wizard finish installing softwares your selected one.\nPlease press Next to finish this wizard."
	);
	if (next.update()) { System::Exit(); }
}