#include "quad.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void glQuad::draw()
{
	glPushMatrix();
	// Perform a rotation around the y axis (0,1,0) 
	// by the amount of degrees defined in the variable angle
	glTranslatef(3*pos.x,3*pos.y,pos.z);
	glBegin(GL_QUADS);
		glColor3f(r,g,b);
		glVertex3f(-1.1f, -1.1f,  1.1f);	// Bottom Left Of The Texture and Quad
		glVertex3f( 1.1f, -1.1f,  1.1f);	// Bottom Right Of The Texture and Quad
		glVertex3f( 1.1f,  1.1f,  1.1f);	// Top Right Of The Texture and Quad
		glVertex3f(-1.1f,  1.1f,  1.1f);	// Top Left Of The Texture and Quad
		// Back Face
	glEnd();
	
	// discard the modelling transformations
	// after this the matrix will have only the camera settings.
	glPopMatrix();

}
