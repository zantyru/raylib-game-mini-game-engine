#pragma once
#ifndef __GAME_APPLICATION_HPP__
#define __GAME_APPLICATION_HPP__


#include "Application.hpp"
#include "TextureLibrary.hpp"


namespace Gamengi
{
	class GameApplication final : public Application<GameApplication>
	{
	public:
		GameApplication(Application<GameApplication>::_Token token);

		virtual void AcquireResources() override;
		virtual void StartMainLoop() override;
		virtual void ReleaseResources() override;

	private:
		TextureLibrary _textureLibrary;
	};
}
#endif //  __GAME_APPLICATION_HPP__