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
Point Scene::checkArenaCollision(Point pos, int radius)
{
	//TODO: this
	Point out = {0, 0};

	if (pos.x + radius > sceneRight) {
		printf("R");
	}
	else if (pos.x - radius < sceneLeft) {
		printf("L");
	}
	else if (pos.y + radius > sceneBottom) {
		printf("B");
	}
	else if (pos.y - radius < sceneTop) {
		printf("T");
	}

	return out;
}