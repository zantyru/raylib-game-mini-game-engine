#include "raylib.h"
#include "GameApplication.hpp"


namespace Gamengi
{
	GameApplication::GameApplication(Application<GameApplication>::_Token token)
	{ }

	void GameApplication::AcquireResources()
	{
		::InitWindow(640, 480, "Main Window");
		_textureLibrary.Load();
	}

	void GameApplication::StartMainLoop()
	{
		while (!::WindowShouldClose())
		{
			::BeginDrawing();
			_textureLibrary.Draw(Gamengi::TextureType::PLAYER, 100, 120);
			::EndDrawing();

			//...

			//...
		}
	}

	void GameApplication::ReleaseResources()
	{
		_textureLibrary.Unload();
		::CloseWindow();
	}
}