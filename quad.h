#pragma once
#ifndef _Quad
#define _Quad

#include "vektorrechnung.h"
// Zeichnet ein Viereck

class glQuad
{
public:

	Vector3 pos;
	float r,g,b;
	void draw();
	glQuad(): pos(Vector3(0,0,-40)),r(1),g(1),b(1){}
};
#endif
