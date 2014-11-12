#include "LUtil.h"

int gColorMode = COLOR_MODE_CYAN;

GLfloat gProjectionScale = 1.f;

bool initGL() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.f, 0.f, 0.f, 1.f);

	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		printf("Error initialzing OpenGL: %s\n", gluErrorString(error));
		return false;
	}

	return true;
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f);

	if (gColorMode == COLOR_MODE_CYAN) {
		glBegin(GL_QUADS);
			glColor3f( 0.f, 1.f, 1.f );
			glVertex2f( -50.f, -50.f );
            glVertex2f(  50.f, -50.f );
            glVertex2f(  50.f,  50.f );
            glVertex2f( -50.f,  50.f );
		glEnd();
	}
	else {
		glBegin( GL_QUADS );
            glColor3f( 1.f, 0.f, 0.f ); glVertex2f( -50.f, -50.f );
            glColor3f( 1.f, 1.f, 0.f ); glVertex2f(  50.f, -50.f );
            glColor3f( 0.f, 1.f, 0.f ); glVertex2f(  50.f,  50.f );
            glColor3f( 0.f, 0.f, 1.f ); glVertex2f( -50.f,  50.f );
        glEnd();
	}

	glutSwapBuffers();
}

void handleKeys(unsigned char key, int x, int y) {
	if (key == 'q') {
		gColorMode = (gColorMode == COLOR_MODE_CYAN) ? COLOR_MODE_MULTI : COLOR_MODE_CYAN;
	}
	else if (key == 'e') {
		if (gProjectionScale == 1.f) gProjectionScale = 2.f;
		else if (gProjectionScale == 2.f) gProjectionScale = 0.5f;
		else if (gProjectionScale == 0.5f) gProjectionScale = 1.f;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, SCREEN_WIDTH * gProjectionScale, SCREEN_HEIGHT * gProjectionScale, 0.0, 1.0, -1.0);
	}
}

void update()
{

}

