#include <SDL.h>
#include <string>
#include <cmath>
#include "Point.h"

//TODO: add player attacks to checkInput().

SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

extern SDL_Event gInputHandler;

class Player {
public:
	Point m_position;  //position
	Point m_velocity;  //velocity
	double m_rotation = 0;

	int m_radius;

	int m_texWidth, m_texHeight;
	SDL_Texture *m_texture = NULL;

	void init(SDL_Renderer *renderer, std::string path, Point pos);

	//for physics things.  //TODO: framerate independence.
	void update();
	void Player::collision(Point collsionOffset);

	void render(SDL_Renderer *renderer);
	void checkInput();  //this is a reference

	~Player();
};

