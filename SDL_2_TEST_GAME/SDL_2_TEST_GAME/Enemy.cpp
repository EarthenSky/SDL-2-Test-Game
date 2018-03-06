#include "Enemy.h"
int index = 0;

double findAngle(Point pOne, Point pTarget)
{
	double angle1 = std::atan2(20000 - pOne.y, 0);
	double angle2 = std::atan2(pTarget.y - pOne.y, pTarget.x - pOne.x);
	//printf("", (angle1 - angle2) * 180 / 3.141592, "|||");
	return -((angle1 - angle2) * 180 / 3.141592) + 180;
}

// This constructor loads a texture and makes position and texture size values.
Enemy::Enemy(SDL_Texture *texture, Point position, Point texSize, double rotation, std::list<Enemy*> *killList)
{
	printf("CREATE\n");
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
	SDL_RenderCopyEx(renderer, m_texture, NULL, &placementRect, m_rotation, NULL, SDL_FLIP_NONE);

	//printf("SDL Error: %s\n", SDL_GetError());
}

void Enemy::collision(Point collsionOffset)
{
	// This moves this object based on the collision offset. 
	m_position.x -= collsionOffset.x;
	m_position.y -= collsionOffset.y;
}

void Enemy::update() 
{
	printf("%d/n", gPlayer.m_position);
	m_rotation = findAngle(m_position, gPlayer.m_position);
}

void Enemy::destroyEnemy() 
{
	// Passes a reference froms this object to the kill list.
	m_killListPtr->push_back(this);
}

// This deconstructor frees the loaded image.
Enemy::~Enemy() { 
	printf("DED\n"); 
	//m_killListPtr = NULL;
	//m_texture = NULL;
}