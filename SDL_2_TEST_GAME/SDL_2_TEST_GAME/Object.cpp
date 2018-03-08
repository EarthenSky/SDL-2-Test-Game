#include "Object.h"

// This constructor loads a texture and makes position and texture size values.
Object::Object(SDL_Texture *texture, Point pos, Point texSize, double rotation)
{
	m_texture = texture;
	m_pos = pos;
	m_texSize = texSize;
	m_rotation = rotation;
}

// This function renders the texture in its placement rectangle.
void Object::Render(SDL_Renderer *renderer) 
{
	if (hidden == false) {
		SDL_Rect placementRect = { m_pos.x, m_pos.y, m_texSize.x, m_texSize.y };
		SDL_RenderCopyEx(renderer, m_texture, NULL, &placementRect, 0, NULL, SDL_FLIP_NONE);
	}
	
	//printf("SDL Error: %s\n", SDL_GetError());
}

// This deconstructor frees the loaded image.
Object::~Object()
{
	SDL_DestroyTexture(m_texture);
	m_texture = NULL;
}