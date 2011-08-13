#include <iostream>
#include <GL/glut.h>
#include "quad.h"
#include "road.h"
#include <vector>
#include <time.h>

const int num_roads = 1;

class road_x    // (wrapping) class to link roads to a list
{
public:
	road_x* p;  // pointer to next road_x	
	road* r;    // pointer to road-object from road.h
		
	road_x* get_next()
	{
		return p;
	}
	
	road_x(): p(NULL), r(NULL)
	{
		r = new road();
	}
	road_x(road_x* next): p(next), r()
	{
		r = new road();
		//r->first_car=NULL;
	}

	~road_x()
	{
		if(r) delete(r);    // free road
		if(p) delete(p);    // free tail of the list
	}	

	void draw()
	{
        glTranslatef(0,-3,0);
		r->draw();          // draw the road
        if(p)
            p->draw();          // draw tail
	}
	
	void move()
	{	
		r->move();		// move all cars on the road
		if(p)
			p->move();	// move all cars on the next roads in the list
	}	
};

class roads // List of all roads
{
public:
	
	road_x* head;
	
	roads()		// filling the list
	{
		head = NULL;
		for(int i = 0; i<num_roads; i++)
			head = new road_x(head);
	}
	

	void add_road(road* road_p)
	{
		head = new road_x(head);
		head->r = road_p;
	}

	void draw()
	{
		glPushMatrix();
			if(head) 
				head->draw();
		glPopMatrix();
	}
	
	void move()
	{
		if(head)
			head->move();
	}
	
	~roads()
	{		
		if(head)
			delete(head);
	}
};

stopwatch timer_g;
roads* _roads;

void render(void)		// OGL-Render-function. Renders everithing. 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	glRotatef(24,0,1,0);
	glTranslatef(_road_lenght / 2 ,num_roads * 1.5, 0);
	_roads->draw();
	glPopMatrix();	
	glutSwapBuffers();
}

void idle(void)		// OGL-Idle-funtion
{
/*	timer_g.stop();
	float x = timer_g.gettime();
	timer_g.start();
	
	if(x < 20)
	{
		timespec t;
		t.tv_sec = 0;
		t.tv_nsec = 100*1000*(20-x);
//		nanosleep(&t, NULL);	// damn dosn't work :-(
	} */
	
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
	
	glutFullScreen();				// Fulllscreenmode if wanted...
	glEnable(GL_DEPTH_TEST);


	glutDisplayFunc(render);
	glutIdleFunc(idle);
	glutReshapeFunc(Resize);		// nötig?

	glutKeyboardFunc(processNormalKeys);	// Exit(0) when ESC is pressed
	
	glutMainLoop();
	return -1; 
}
