#include "LOpenGL.h"

//Screen Constants

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

bool initGL();
void update();	// does per frame logic
void render();	// renders scene
