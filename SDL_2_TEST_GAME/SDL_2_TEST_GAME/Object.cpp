#include "Object.h"

// This constructor loads a texture and makes position and texture size values.
Object::Object(SDL_Texture *texture, Point pos, Point texSize)
{
	m_texture = texture;
	m_pos = pos;
	m_texSize = texSize;
}

// This function renders the texture in its placement rectangle.
void Object::Render(SDL_Renderer *renderer) 
{
	SDL_Rect placementRect = { m_pos.x, m_pos.y, m_texSize.x, m_texSize.y };
	SDL_RenderCopy(renderer, m_texture, NULL, &placementRect);

	//printf("SDL Error: %s\n", SDL_GetError());
}

// This deconstructor frees the loaded image.
Object::~Object()
{
	SDL_DestroyTexture(m_texture);
	m_texture = NULL;
}