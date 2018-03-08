#include "Enemy.h"

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
	//printf("CREATE\n");
	m_texture = texture;
	m_position = position;
	m_texSize = texSize;
	m_rotation = rotation;

	// Half the texture size is radius
	m_radius = texSize.x / 2;

	m_killListPtr = killList;
}

// This function renders the texture in its placement rectangle.
void Enemy::render(SDL_Renderer *renderer)
{
	SDL_Rect placementRect = { m_position.x, m_position.y, m_texSize.x, m_texSize.y };
	SDL_RenderCopyEx(renderer, m_texture, NULL, &placementRect, m_rotation, NULL, SDL_FLIP_NONE);

	//printf("SDL Error: %s\n", SDL_GetError());
}

void Enemy::setCollision(Point collsionOffset)
{
	// This moves this object based on the collision offset. 
	m_position.x -= collsionOffset.x;
	m_position.y -= collsionOffset.y;
}

// Finds the distance between two things
double distanceBetweenTwoPoints(double x, double y, double x2, double y2) {
	return std::sqrt(std::pow(x - x2, 2) + std::pow(y - y2, 2));
}

void Enemy::checkCollision() 
{
	// If objects are colliding then look what to do
	if (distanceBetweenTwoPoints(m_position.x, m_position.y, gPlayer.m_position.x, gPlayer.m_position.y) < (m_radius + gPlayer.m_radius)) {
		// If the player is not attacking then it takes damage.
		if (gPlayer.attackOn == false) {  
			gPlayer.decrementHP();  //check for death and update up value
			gHP.setHPSize(gPlayer.hp);  //update the health ui
		}

		destroyEnemy();  // If the ai collides with the player then it dies.
	}
}

void Enemy::destroyEnemy()
{
	// Passes a reference froms this object to the kill list.
	m_killListPtr->push_back(this);
}

void Enemy::update() 
{
	// Set look direction
	m_rotation = findAngle(m_position, gPlayer.m_position);
	
	double rot = std::atan2(gPlayer.m_position.y - m_position.y, gPlayer.m_position.x - m_position.x);

	// set move in that direction
	double cos = std::cos(rot);
	double sin = std::sin(rot);

	m_position = { m_position.x + (1.5 * cos), m_position.y + (1.5 * sin) };
}

// This deconstructor frees the loaded image.
Enemy::~Enemy() { 
	printf("DED\n"); 
	//m_killListPtr = NULL;
	//m_texture = NULL;
}