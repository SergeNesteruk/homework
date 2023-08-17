#include "Counter.h"
#include <iostream>

Counter::Counter()
{
	x = 1;
}

Counter::Counter(double num)
{
	x = num;
}

double Counter::inc()
{
	return x++;
}

double Counter::dec()
{
    return x--;
}
void Counter::view()
{
    std::cout << x << std::endl;
}
