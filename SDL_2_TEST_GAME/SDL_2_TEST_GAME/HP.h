#ifndef HPS
#define HPS

#include <SDL.h>
#include "UIElement.h"

class HPR : public UIElement {
public:
	// The render objects are created here.
	void init(SDL_Renderer *renderer);

	void update();  //This is the math function

	void render(SDL_Renderer *renderer);  //This is the math function

	void setHPSize(int newhpValue);
}

#endif