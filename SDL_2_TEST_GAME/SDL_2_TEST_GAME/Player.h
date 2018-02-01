#include <SDL.h>
#include <string>

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

extern SDL_Event gInputHandler;

class Player {
public:
	int xPos, yPos;  //position
	int xVel, yVel;  //velocity
	double rotation;

	SDL_Texture *texture = NULL;

	void init(SDL_Renderer *renderer, std::string path, int xPosition, int yPosition);
	void freeAssets();
	void update();  //for physics things.  //TODO: framerate independence.
	void render(SDL_Renderer *renderer);
	void checkInput();  //this is a reference
};