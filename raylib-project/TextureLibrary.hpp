#pragma once
#ifndef __TEXTURE_LIBRARY_HPP__
#define __TEXTURE_LIBRARY_HPP__


#include "raylib.h"
#include "Library.hpp"


namespace Gamengi
{
	enum class TextureType : std::size_t
	{
		VOID,
		EMPTY_FLOOR,
		PLAYER,
		WOODEN_BOX,
		_COUNT
	};

	// А не сделать ли класс static или вообще singleton 
	class TextureLibrary final : public Library<::Texture2D, std::size_t(TextureType::_COUNT)>
	{
	public:
		void Load() override;
		void Unload() override;
		void Draw(TextureType id, int x, int y, ::Color color = ::WHITE) const;
	};
}
#endif // __TEXTURE_LIBRARY_HPP__