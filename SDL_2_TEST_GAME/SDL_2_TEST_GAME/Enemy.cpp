#include "Enemy.h"

// This constructor loads a texture and makes position and texture size values.
Enemy::Enemy(SDL_Texture *texture, Point position, Point texSize, double rotation, int listIndex, EnemyManager* enemyPtr)
{
	m_listIndex = listIndex;
	m_texture = texture;
	m_position = position;
	m_texSize = texSize;
	m_rotation = rotation;

	m_enemyPtr = enemyPtr;
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
}

void Enemy::collision(Point collsionOffset)
{
	//kill ai.
}

void Enemy::destroyEnemy() 
{
	//should destroy the enemy
	m_enemyPtr->m_enemyList.erase(m_enemyPtr->m_enemyList.begin() + (m_listIndex - 1));
}

// This deconstructor frees the loaded image.
Enemy::~Enemy()
{
	SDL_DestroyTexture(m_texture);
	m_texture = NULL;
}