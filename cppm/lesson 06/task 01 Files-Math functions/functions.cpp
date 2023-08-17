#include "functions.h"

int sum(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int multiplication(int a, int b)
{
	return a * b;
}
double division(int a, int b)
{
	double res = static_cast<double>(a) / b;
	return res;
}

int power(int a, int b)
{
	int a_powered = a;
	for (int i = 1; i < b; i++)
	{
		a_powered *= a;
	}
	return a_powered;
}