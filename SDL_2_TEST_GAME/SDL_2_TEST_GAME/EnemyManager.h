#include <SDL.h>
#include <string>
#include <cmath>
#include "Point.h"
#include <vector>
#include "Enemy.h"

//TODO: add player attacks to checkInput().

//SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

//extern SDL_Event gInputHandler;

class EnemyManager {
public:
	void init();

	// Call this function to create an enemy object
	void spawnEnemy(SDL_Texture *texture, Point pos, Point texSize, double rotation=0);

	std::vector<Enemy*> m_enemyList;  // Holds all of the enemy objects

	//for physics things.  //TODO: framerate independence.
	void update();

	void render(SDL_Renderer *renderer);
	//void checkInput();  //this is a reference

	~EnemyManager();
};

