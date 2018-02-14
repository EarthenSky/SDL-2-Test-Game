#include "UIElement.h"

UIElement::UIElement(SDL_Renderer *renderer, std::string path, Point pos)
{
	m_position = pos;
	m_texture = loadTexture(renderer, path);
	m_texWidth = 80;
	m_texHeight = 80;
}

void UIElement::render(SDL_Renderer *renderer)
{
	//Places the texture in placementRect
	SDL_Rect placementRect = { m_position.x, m_position.y, m_texWidth, m_texHeight };
	SDL_RenderCopy(renderer, m_texture, NULL, &placementRect);
}

void UIElement::update()
{
	//Do Nothing
}