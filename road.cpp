#include "quad.h"
#include "vektorrechnung.h"
#include <stdlib.h>
#include "road.h"
#include "stoppwatch.h"
#include <iostream>
#include "car.h"

using namespace basti;
void road::draw()
{
	current_car=first_car;
	while(current_car)
	{
		//current_car->draw();
		current_car->draw_animated(timer);
		current_car = current_car->next_car;
	}
};

void road::move()
{	
	timer.stop();
	if (timer.gettime() > _car_mspmove)
	{
		timer.start();
		if(!(first_car)) first_car = new car(2,first_car);
		if (first_car->position > 2) 
		{
			if(rand()>RAND_MAX/3)
			{
				first_car = new car(2,first_car);
			}
		}
		current_car = first_car;
		while(current_car)
		{
			current_car->move();
			if(current_car->next_car)
			{
				if (current_car->next_car->position > (_road_lenght))
				{	
					current_car->next_car->~car();
					current_car->next_car = NULL;
				}
			}
			current_car = current_car->next_car;
		}
	}
};

