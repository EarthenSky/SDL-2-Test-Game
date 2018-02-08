#include "Scene.h"

void Scene::init(SDL_Renderer *renderer, std::string path)
{
	xPos = 20;
	yPos = 20;
	texture = loadTexture(renderer, path);
	texWidth = 600;
	texHeight = 600;
}

void Scene::render(SDL_Renderer *renderer) 
{
	//Places the texture in placementRect
	SDL_Rect placementRect = { xPos, yPos, texWidth, texHeight };
	SDL_RenderCopy(renderer, texture, NULL, &placementRect);
}

int sceneTop = 20;
int sceneLeft = 20;
int sceneBottom = 620;
int sceneRight = 620;
Point Scene::checkArenaCollision(Point pos, int radius)
{
	//TODO: this
	Point out = {0, 0};

	if (pos.x + 2 * radius > sceneRight) {
		printf("R");
		out.x = (pos.x + 2 * radius) - sceneRight;
	}
	else if (pos.x < sceneLeft) {
		printf("L");
		out.x = pos.x - sceneLeft;
	}
	
	if (pos.y + 2 * radius> sceneBottom) {
		printf("B");
		out.y = (pos.y + 2 * radius) - sceneBottom;
	}
	else if (pos.y < sceneTop) {
		printf("T");
		out.y = pos.y - sceneTop;
	}

	return out;
}

Scene::~Scene() 
{
	//Free loaded image
	SDL_DestroyTexture(texture);
	texture = NULL;
}