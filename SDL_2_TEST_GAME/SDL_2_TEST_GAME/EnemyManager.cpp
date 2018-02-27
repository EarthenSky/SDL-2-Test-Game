#include "EnemyManager.h"

void EnemyManager::init()
{

}

void EnemyManager::spawnEnemy(SDL_Texture *texture, Point pos, Point texSize, double rotation)
{
	// Adds an enemy object to the list.
	m_enemyList.push_back(new Enemy(texture, pos, texSize, rotation, m_enemyList.size, this));
}

void EnemyManager::render(SDL_Renderer *renderer)
{
	// Iterates over all child list objects and calls their render function.
	for (Enemy* enemyObj : m_enemyList) {
		enemyObj->render(renderer);
	}
}

EnemyManager::~EnemyManager()
{
	//delete all enemy classes in the deconstructor to avoid memory leaks
	for (Enemy* enemyObj : m_enemyList) {
		delete enemyObj;
	}
}