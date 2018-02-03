#include <SDL.h>
#include <string>
#include "Point.h"

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

class Scene {
public:
	int xPos, yPos;  //position

	int texWidth, texHeight;
	SDL_Texture *texture = NULL;

	void init(SDL_Renderer *renderer, std::string path);
	void freeAssets();
	void render(SDL_Renderer *renderer);

	Point checkArenaCollision(int x, int y, int radius);
};