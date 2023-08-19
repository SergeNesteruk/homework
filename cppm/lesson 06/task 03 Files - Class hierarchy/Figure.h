#pragma once
#include <iostream>

class Figure
{
protected:
	std::string name;
	int sides_count;
public:
	Figure();
	virtual void print();
};
