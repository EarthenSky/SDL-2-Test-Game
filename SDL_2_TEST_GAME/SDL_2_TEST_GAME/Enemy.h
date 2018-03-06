#ifndef ENEMY
#define ENEMY

#include <SDL.h>
#include <string>
#include "Point.h"
#include <list>
#include <iostream>
#include <memory>
#include "Player.h"
#include <cmath>

extern Player gPlayer;
//#include "EnemyManager.h"

//TODO: add player attacks to checkInput().

//SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

//extern SDL_Event gInputHandler;

//class EnemyManager;

class Enemy {
public:
	Enemy(SDL_Texture *texture, Point position, Point texSize, double rotation, std::list<Enemy*> *killList);

	std::list<Enemy*> *m_killListPtr;

	Point m_position;  //position
	Point m_velocity;  //velocity
	double m_rotation = 0;

	int m_radius;

	Point m_texSize;  //width / height of the object
	SDL_Texture *m_texture = NULL;

	// For physics things.  //TODO: framerate independence.
	void update();
	void setCollision(Point collsionOffset);

	// Checks if the enemy is colliding with the player
	void checkCollision();

	void destroyEnemy();  //This function destroys this object and removes it from the list.

	void render(SDL_Renderer *renderer);

	~Enemy();
};

#endif