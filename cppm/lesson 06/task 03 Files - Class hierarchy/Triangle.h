#pragma once
#include "Figure.h"
class Triangle :
    public Figure
{
protected:
	int a, b, c; //sides
	int A, B, C; //angles
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	int get_a();
	int get_b();
	int get_c();
	int get_A();
	int get_B();
	int get_C();
	std::string get_name();
	void print() override;
};

