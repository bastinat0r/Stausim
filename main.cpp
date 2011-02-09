#include <iostream>
#include <GL/glut.h>
#include "quad.h"
#include "road.h"
#include <vector>
////////////////////////////////////////////////////////////// Hier ist Stausimulation {
using namespace basti;
road funkyroad;
road funkyroad2;
road funkyroad3;
road funkyroad4;
road funkyroad5;
road funkyroad6;
////////////////////////////////////////////////////////////// }

class road_x
{
public:
	road_x* p;	
	road* r;
		
	road_x* get_next()
	{
		return p;
	}
	
	road_x(): p(NULL), r(NULL)
	{
		r = new road;
	}
	road_x(road_x* next): p(next), r()
	{
		r = new road;
	}
	~road_x()
	{
		if(r) delete(r);
		if(p) delete(p);
	}	

	void draw()
	{
		std::cout<<r<<std::endl;
		//r->draw();
	}
	
	void move()
	{	
		r->move();
	}	
};

class roads
{
public:
	
	road_x* head;
	
	roads()
	{
		head = NULL;
		head = new road_x(head);
		std::cout<<head->r<<std::endl;
		std::cout<<__roadptr<<std::endl;
		//head->r = &funkyroad;	
	}
	

	void add_road(road* road_p)
	{
		head = new road_x(head);
		head->r = road_p;
	}
	void draw()
	{
		glPushMatrix();
		road_x* p = head;
		while(p)
		{
			glTranslatef(0,-3,0);
			p->draw();
			p = p->get_next();
		}
		glPopMatrix();
	}
	
	void move()
	{
		road_x* p = head;		
		while(p)
		{
			p->move();
			p = p->get_next();
		}
	}
	
	~roads()
	{		
		if(head)
			delete(head);
	}
};

stopwatch timer_g;
roads* _roads;

void render(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_roads->draw();
//	glRotatef(0.01,0,0,1);
/*
	glPushMatrix();
		glTranslatef(0,-3,0);
		funkyroad.draw();
	glPopMatrix();	
	glPushMatrix();
		glTranslatef(0,-9,0);
		funkyroad3.draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,-15,0);
		funkyroad5.draw();
	glPopMatrix();

	
	glPushMatrix();
		glRotatef(180,0,0,1);
	glPushMatrix();
		glTranslatef(0,-3,0);
		funkyroad2.draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,-9,0);
		funkyroad3.draw();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,-15,0);
		funkyroad4.draw();
	glPopMatrix();
	glPopMatrix();
*/	
	glutSwapBuffers();
}

void idle(void)
{
	
	/*timer_g.stop();
	if(timer_g.gettime() < 20)
	{
		usleep(3000);
	}
	timer_g.start();
	*/
	/*funkyroad.move();
	funkyroad2.move();
	funkyroad3.move();
	funkyroad4.move();
	funkyroad5.move();
*/
	_roads->move();
	render();
}

void Resize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	float ratio = 1.0* w / h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0, 
		      0.0,0.0,-1.0,
			  0.0f,1.0f,0.0f);


}
void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27) 
		exit(0);
}

int main(int argc, char **argv) 
{	
	/* Initialize Glut and Create Window */
	_roads = new roads();
	
	std::cout<<"blub"<<std::endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,500);
	glutCreateWindow("Road!");
	
	//glutFullScreen();				// Fulllscreenmode if wanted...
	glEnable(GL_DEPTH_TEST);


	glutDisplayFunc(render);
	glutIdleFunc(idle);
	glutReshapeFunc(Resize);		// nötig?

	glutKeyboardFunc(processNormalKeys);	// Exit(0) when ESC is pressed
	
	glutMainLoop();
	return -1; 
}
