#pragma once
#ifndef _road
#define _road

#include "quad.h"
#include "vektorrechnung.h"
#include "stoppwatch.h"
#include <iostream>
#include "car.h"

namespace basti
{
	void* __roadptr;
	class road
	{
	private:
		stopwatch timer;
	
	public:
		road(){srand(timer.randomize()); timer.start();__roadptr=this;}
		~road(){if(first_car) first_car->~car();}
			
		void draw();		// genauso einzeln...
		void move();		// einzeln, freigeben, wenns über den Tellerand fällt...
	
		car* first_car;		// unbedingt mit "NULL" initialisieren
		car* current_car;
	};
}	
#endif
