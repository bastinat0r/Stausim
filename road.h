#pragma once
#ifndef _road
#define _road

#include "quad.h"
#include "vektorrechnung.h"
#include "stoppwatch.h"
#include <iostream>
#include <stdlib.h>
#include "car.h"

class road
{
private:
	stopwatch timer;

public:
	car* first_car;		// unbedingt mit "NULL" initialisieren
	car* current_car;

	road(){srand(timer.randomize()); timer.start(); first_car = NULL; current_car = NULL;}
	~road(){if(first_car) first_car->~car();}
		
	void draw();		// genauso einzeln...
	void move();		// einzeln, freigeben, wenns über den Tellerand fällt...

};
	
#endif
