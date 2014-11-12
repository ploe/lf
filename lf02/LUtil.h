#include "LOpenGL.h"

//Screen Constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

//Color modes
const int COLOR_MODE_CYAN = 0;
const int COLOR_MODE_MULTI = 1;

bool initGL();
void update();	// does per frame logic
void render();	// renders scene
void handleKeys(unsigned char key, int x, int y);	// key handling callbaclk
