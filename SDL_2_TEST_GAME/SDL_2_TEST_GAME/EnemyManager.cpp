#include "EnemyManager.h"

void EnemyManager::init(SDL_Renderer *renderer)
{
	// Initialize the enemy texture
	m_enemyTexture = loadTexture(renderer, "Images/aiTex.bmp");
}

void EnemyManager::spawnEnemy(Point pos, Point texSize, double rotation)
{
	// Loads the enemy texture
	//SDL_Texture *texture = loadTexture(renderer, "Images/aiTex.bmp");

	// The list id of the enemy, used for deleting the object.
	//int listIndex = m_enemyList.size();

	// Adds a new enemy object to the list.
	m_enemyList.push_back(new Enemy(m_enemyTexture, pos, texSize, rotation, &m_killList));
}

void EnemyManager::update()
{
	// Iterates over all child list objects and calls their render function.
	for (Enemy* enemyObj : m_enemyList) {
		enemyObj->update();
	}

	// Destroys all objects that need to be killed
	for (Enemy* enemyPtr : m_killList) {
		delete enemyPtr;  // Give the memory back before the item is removed from list.
		//m_enemyList.remove(enemyPtr);
	}

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
	// Delete all enemy classes in the deconstructor to avoid memory leaks
	for (Enemy* enemyObj : m_enemyList) {
		delete enemyObj;
	}

	// Delete Enemy Texture
	SDL_DestroyTexture(m_enemyTexture);
	m_enemyTexture = NULL;

	printf("DESTROYED");
}