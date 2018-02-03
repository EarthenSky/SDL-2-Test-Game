#include <SDL.h>
#include <string>
#include <cmath>
#include "Point.h"

//TODO: include player attacks to checkInput().

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

extern SDL_Event gInputHandler;

class Player {
public:
	int xPos, yPos;  //position
	int xVel, yVel;  //velocity
	double rotation = 0;

	int radius;
	//Point *ptPush;

	int texWidth, texHeight;
	SDL_Texture *texture = NULL;

	void init(SDL_Renderer *renderer, std::string path, int xPosition, int yPosition);
	void freeAssets();
	void update(Point *ptPush);  //for physics things.  //TODO: framerate independence.
	void render(SDL_Renderer *renderer);
	void checkInput();  //this is a reference
};