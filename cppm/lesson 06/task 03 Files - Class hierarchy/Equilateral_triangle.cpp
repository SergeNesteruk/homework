#include "Equilateral_triangle.h"

Equilateral_triangle::Equilateral_triangle(int a) : Triangle(a, b, c, 60, 60, 60)
{
	name = "Равносторонний треугольник";
	b = a;
	c = a;
}