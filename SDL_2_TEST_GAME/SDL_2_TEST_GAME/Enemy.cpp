#include "Enemy.h"
int index = 0;
// This constructor loads a texture and makes position and texture size values.
Enemy::Enemy(SDL_Texture *texture, Point position, Point texSize, double rotation, std::list<Enemy*> *killList)
{
	m_texture = texture;
	m_position = position;
	m_texSize = texSize;
	m_rotation = rotation;

	m_killListPtr = killList;
}

// This function renders the texture in its placement rectangle.
void Enemy::render(SDL_Renderer *renderer)
{
	SDL_Rect placementRect = { m_position.x, m_position.y, m_texSize.x, m_texSize.y };
	SDL_RenderCopyEx(renderer, m_texture, NULL, &placementRect, 0, NULL, SDL_FLIP_NONE);

	//printf("SDL Error: %s\n", SDL_GetError());
}

void Enemy::update() 
{
	//move ai
	//std::cout << index << " ";

	if (++index > 300) {
		Enemy::destroyEnemy();
	}
}

void Enemy::collision(Point collsionOffset)
{
	//kill ai.
}

void Enemy::destroyEnemy() 
{
	//should destroy the enemy x + (m_listIndex)
	m_killListPtr->push_back(this);
}

// This deconstructor frees the loaded image.
Enemy::~Enemy()
{
}