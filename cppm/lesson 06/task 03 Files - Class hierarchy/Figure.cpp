#include "Figure.h"


Figure::Figure()
	{
		name = "Фигура";
		sides_count = 0;
	}
void Figure::print()
	{
		std::cout << name << "\n";
	}
