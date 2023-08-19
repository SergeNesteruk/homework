#include "Rangle.h"

Rangle::Rangle(int a, int b) : Parallelogram(a, b, 90, 90)
{
	c = a;
	d = b;
	name = "Прямоугольник";
}