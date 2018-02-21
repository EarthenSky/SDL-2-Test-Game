#include "Scene.h"

void Scene::init(SDL_Renderer *renderer, std::string path)
{
	xPos = 300;
	yPos = 75/2;
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

int sceneTop = 0;
int sceneLeft = 0;
int sceneBottom = 600;
int sceneRight = 600;
Point Scene::checkArenaCollision(Point pos, int radius)
{
	//TODO: this
	Point out = {0, 0};

	if (pos.x + 2 * radius > sceneRight + xPos) {
		printf("R");
		out.x = (pos.x + 2 * radius) - (sceneRight + xPos);
	}
	else if (pos.x < sceneLeft + xPos) {
		printf("L");
		out.x = pos.x - (sceneLeft + xPos);
	}
	
	if (pos.y + 2 * radius> sceneBottom + yPos) {
		printf("B");
		out.y = (pos.y + 2 * radius) - (sceneBottom + yPos);
	}
	else if (pos.y < sceneTop + yPos) {
		printf("T");
		out.y = pos.y - (sceneTop + yPos);
	}

	return out;
}

Scene::~Scene() 
{
	//Free loaded image
	SDL_DestroyTexture(texture);
	texture = NULL;
}