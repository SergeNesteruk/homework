#include "Isosceles_triangle.h"

Isosceles_triangle::Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, c, A, B, C)
{
	name = "Равнобедренный треугольник";
	C = A;
	c = a;
}