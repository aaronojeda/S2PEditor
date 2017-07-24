#include "S2PEditor.h"
#include <QtWidgets/QApplication>
#include "Game.h"
#include "EditorParser.h"

#undef main

int editorMode(int argc, char *argv[]);
int playMode();

int main(int argc, char *argv[])
{
	return editorMode(argc, argv);
	return playMode();
}

int editorMode(int argc, char *argv[])
{
	QApplication a(argc, argv);
	S2PEditor w;
	w.show();
	return a.exec();
}

int playMode()
{
	int width, height;
	EditorParser parser;
	if (parser.parseWindowSize(TheGame::Instance().getSettingsFile(), width, height) != tinyxml2::XML_SUCCESS)
	{
		// Couldn't parse window size. Set default values
		width = 640;
		height = 480;
	}
	TheGame::Instance().setWindowSize(width, height);
	if (TheGame::Instance().init(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height))
	{
		// Game loop
		while (TheGame::Instance().running())
		{
			TheGame::Instance().iterate();
		}
	}
	return 0;
}