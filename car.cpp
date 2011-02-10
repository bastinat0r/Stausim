#include "car.h"
#include "quad.h"
#include "vektorrechnung.h"
#include <stdlib.h>



car::car(int _speed, car* next) : oldposition(0),	position(0),	speed(_speed), max_speed(10),	next_car(next)
	{
		int x = rand();
		if(x < 0.1*RAND_MAX)		// -> 10%
		{
			p = 0.8;
			image_animated.r = 1;
			image_animated.g = 0;
			image_animated.b = 0;
		}
		else if (x < 0.7*RAND_MAX)	// -> 70%
		{
			p = 0.5;
			image_animated.r = 0.9;
			image_animated.g = 1;
			image_animated.b = 0;
		}
		else						// -> 20%
		{
			p = 0.2;
			image_animated.r = 0;
			image_animated.g = 1;
			image_animated.b = 0;
		}
	}

void car::move()
{
	oldposition = position;
	int r = distance();
	if (r > max_speed) speed++;
	else 
		if (speed < r-1) speed++;
		else speed = r-1;
	if (speed > max_speed) speed = max_speed;
	if (rand() < RAND_MAX*p && (speed > 0)) speed--;
	position += speed;
};

void car::draw()	// Unanimated Cars drive offroad ;)
{
	image.pos = Vector3(-1*_road_lenght/2 - 2  + position,-2,_car_zVal);
	image.draw();
};

void car::draw_animated(stopwatch & timer)
{
	timer.stop();
	image_animated.pos=Vector3(-1*_road_lenght/2 - 20 + oldposition + (position - oldposition)*timer.gettime()/_car_mspmove,0,_car_zVal);
	image_animated.draw();
};
