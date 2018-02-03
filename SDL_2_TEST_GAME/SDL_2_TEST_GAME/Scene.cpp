#include "Scene.h"

void Scene::init(SDL_Renderer *renderer, std::string path)
{
	xPos = 20;
	yPos = 20;
	texture = loadTexture(renderer, path);
	texWidth = 600;
	texHeight = 600;
}

void Scene::freeAssets() 
{
	//Free loaded image
	SDL_DestroyTexture(texture);
	texture = NULL;
}

void Scene::render(SDL_Renderer *renderer) 
{
	//Places the texture in placementRect
	SDL_Rect placementRect = { xPos, yPos, texWidth, texHeight };
	SDL_RenderCopy(renderer, texture, NULL, &placementRect);
}

int sceneTop = 20;
int sceneLeft = 620;
int sceneBottom = 620;
int sceneRight = 20;
Point Scene::checkArenaCollision(int x, int y, int radius)
{
	//Point out;

	if (x + radius > sceneRight) {
		printf("R");
	}
	else if (x - radius < sceneLeft) {
		printf("L");
	}
	else if (y + radius > sceneBottom) {
		printf("B");
	}
	else if (y - radius < sceneTop) {
		printf("T");
	}

	return 0;
}