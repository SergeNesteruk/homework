#include "Rhombus.h"

Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, b, A, B)
{
	b = c = d = a;
	C = A; D = B;
	name = "Ромб";
}