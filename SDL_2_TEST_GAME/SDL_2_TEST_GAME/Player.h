#include <SDL.h>
#include <string>

class Player {
	int xPos, yPos;  //position
	int xVel, yVel;  //velocity
	SDL_Texture *texture;

	void init(std::string path);
	void render(SDL_Renderer *renderer);
};