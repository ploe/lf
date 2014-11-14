#include "LUtil.h"

int gViewportMode = VIEWPORT_MODE_FULL;

bool initGL() {
	glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);

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

	if (gViewportMode == VIEWPORT_MODE_FULL) {
		glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);

		// red quad
		glBegin(GL_QUADS);
			glColor3f( 1.f, 0.f, 0.f );
			glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
			glVertex2f(  SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
			glVertex2f(  SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
			glVertex2f( -SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
		 glEnd();	
	}
	else if (gViewportMode == VIEWPORT_MODE_HALF_CENTER) {
		glViewport(SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);
		glBegin(GL_QUADS);
			glColor3f( 0.f, 1.f, 0.f );
			glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
			glVertex2f(  SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
			glVertex2f(  SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
			glVertex2f( -SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
		glEnd();
	}
	else if (gViewportMode == VIEWPORT_MODE_HALF_TOP) {
		glViewport(SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f);

		glBegin( GL_QUADS );
			glColor3f( 0.f, 0.f, 1.f );
			glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
			glVertex2f(  SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
			glVertex2f(  SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
			glVertex2f( -SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
		glEnd();
	}
	else if (gViewportMode == VIEWPORT_MODE_QUAD) {
		glViewport( 0.f, 0.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
		glBegin( GL_QUADS );
			glColor3f( 1.f, 0.f, 0.f );
			glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
			glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
			glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
			glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
		glEnd();

		glViewport( SCREEN_WIDTH / 2.f, 0.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
		glBegin( GL_QUADS );
			glColor3f( 0.f, 1.f, 0.f );
			glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
			glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
			glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
			glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
		glEnd();

		glViewport( 0.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
		glBegin( GL_QUADS );
			glColor3f( 0.f, 0.f, 1.f );
			glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
			glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
			glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
			glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
		glEnd();

		glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
		glBegin( GL_QUADS );
			glColor3f( 1.f, 1.f, 0.f );
			glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
			glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
			glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
			glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
		glEnd();

	}
	else if (gViewportMode == VIEWPORT_MODE_RADAR) {
		glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);
		glBegin(GL_QUADS);
			glColor3f( 1.f, 1.f, 1.f );
			glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
			glVertex2f(  SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
			glVertex2f(  SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
			glVertex2f( -SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
			glColor3f( 0.f, 0.f, 0.f );
			glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
			glVertex2f(  SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
			glVertex2f(  SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
			glVertex2f( -SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
		glEnd();

		glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
		glBegin( GL_QUADS );
			glColor3f( 1.f, 1.f, 1.f );
			glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
			glVertex2f(  SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
			glVertex2f(  SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
			glVertex2f( -SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
			glColor3f( 0.f, 0.f, 0.f );
			glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
			glVertex2f(  SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
			glVertex2f(  SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
			glVertex2f( -SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
		glEnd();
	}
	glutSwapBuffers();
}
void handleKeys(unsigned char key, int x, int y) {
	if( key == 'q' ) {
		gViewportMode++;
		if( gViewportMode > VIEWPORT_MODE_RADAR )
		{
			gViewportMode = VIEWPORT_MODE_FULL;
		}
	}
}

void update()
{

}

