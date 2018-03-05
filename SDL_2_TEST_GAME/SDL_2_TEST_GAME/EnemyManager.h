#ifndef ENEMYMANAGER
#define ENEMYMANAGER

#include <SDL.h>
#include <string>
#include <cmath>
#include "Point.h"
#include <list>
#include "Enemy.h"
#include <memory>

//TODO: add player attacks to checkInput().

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

//extern SDL_Event gInputHandler;

class EnemyManager {
public:
	void init(SDL_Renderer *renderer);

	// Call this function to create an enemy object
	void spawnEnemy(Point pos, Point texSize, double rotation=0);

	std::list<std::unique_ptr<Enemy>> m_enemyList;  // Holds all of the enemy objects
	std::list<std::unique_ptr<Enemy>> m_killList;  // Holds the indexes to destroy

	SDL_Texture *m_enemyTexture = NULL;  // The texture for all the enemies

	//for physics things.  //TODO: framerate independence.
	void update();

	void render(SDL_Renderer *renderer);
	//void checkInput();  //this is a reference

	~EnemyManager();
};

#endif