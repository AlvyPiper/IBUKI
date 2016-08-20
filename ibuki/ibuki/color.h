#pragma once
#include "ibuki.h"

class Color
{
public:
	unsigned char r, g, b, a;

	Color(int r = 0, int g = 0, int b = 0, int a = 0) 
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};