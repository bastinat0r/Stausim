#pragma once
#ifndef _car		// include-guard
#define _car

#include "quad.h"
#include "vektorrechnung.h"
#include "stoppwatch.h"


const int _car_mspmove = 250;
const int _road_lenght = 300;
const float _car_zVal = -500;

class car
{
public:
	/* Variablen: position, geschwindigkeit, vordermann */
	int oldposition,position,speed,max_speed;
	float p;
	car* next_car;
	glQuad image;
	glQuad image_animated;

	/* Konstruktoren & Destruktoren - Default... bestimmt */
	car(int _speed, car* next);
	~car(){if(next_car) next_car->~car();};				// nächsten Destruktor auslösen
	
	/* Funktionen eines Autos: nächsten Zug berechnen, Zeichnen, Animieren */
	int distance() {if (next_car) return next_car->position-position; else return 5;}
	void move();		
	void draw();
	void draw_animated(stopwatch & timer);
};

#endif
