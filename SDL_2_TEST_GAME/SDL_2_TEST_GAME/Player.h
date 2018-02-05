#include <SDL.h>
#include <string>
#include <cmath>
#include "Point.h"

//TODO: add player attacks to checkInput().

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

extern SDL_Event gInputHandler;

class Player {
public:
	Point position;  //position
	Point velocity;  //velocity
	double rotation = 0;

	int radius;

	int texWidth, texHeight;
	SDL_Texture *texture = NULL;

	void init(SDL_Renderer *renderer, std::string path, Point pos);
	void freeAssets();

	//for physics things.  //TODO: framerate independence.
	void update();
	void Player::collision(Point collsionOffset);

	void render(SDL_Renderer *renderer);
	void checkInput();  //this is a reference
};

