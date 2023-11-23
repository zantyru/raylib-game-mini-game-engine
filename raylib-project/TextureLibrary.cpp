#include "raylib.h"
#include "TextureLibrary.hpp"


namespace Gamengi
{
	void TextureLibrary::Load()
	{
        _items[size_t(TextureType::VOID)]        = ::LoadTexture("textures/void.png");
        _items[size_t(TextureType::EMPTY_FLOOR)] = ::LoadTexture("textures/empty_floor.png");
        _items[size_t(TextureType::PLAYER)]      = ::LoadTexture("textures/player.png");
        _items[size_t(TextureType::WOODEN_BOX)]  = ::LoadTexture("textures/wooden_box.png");
	}


	void TextureLibrary::Unload()
	{
		::UnloadTexture(_items[size_t(TextureType::VOID)]);
		::UnloadTexture(_items[size_t(TextureType::EMPTY_FLOOR)]);
		::UnloadTexture(_items[size_t(TextureType::PLAYER)]);
		::UnloadTexture(_items[size_t(TextureType::WOODEN_BOX)]);
	}


	void TextureLibrary::Draw(TextureType id, int x, int y, ::Color color) const
	{
		::DrawTexture(
			_items[size_t(id)],
			x, y,
			color
		);
	}
}