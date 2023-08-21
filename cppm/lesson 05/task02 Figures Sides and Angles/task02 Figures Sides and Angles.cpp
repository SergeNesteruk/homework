#include <Windows.h>
#include <iostream>

class Figure
{
protected:
	std::string name;
	int sides_count;
public:
	Figure()
	{
		name = "Фигура";
		sides_count = 0;
	}
	virtual void print()
	{
		std::cout << name << "\n";
	}
};


class Triangle: public Figure
{
protected:
	int a, b, c; //sides
	int A, B, C; //angles
public:
	Triangle(int a, int b, int c, int A, int B, int C): Figure()
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		name = "Треугольник";
	}
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	std::string get_name() { return name; }
	void print() override
	{
		Figure::print();
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n";
	}
};
class Right_triangle: public Triangle
{
public:
	Right_triangle( int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
	{
		name = "Прямоугольный треугольник";
	}
};

class Isosceles_triangle : public Triangle
{
public:
	Isosceles_triangle (int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
	{
		name = "Равнобедренный треугольник";
	}
};

class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle (int a) : Triangle(a, a, a, 60, 60, 60)
	{
		name = "Равносторонний треугольник";
	}
};


class Quadrangle: public Figure
{
protected:
	int a, b, c, d; //sides
	int A, B, C, D; //angles
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D): Figure ()
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		name = "Четырехугольник";
	}
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }
	std::string get_name() { return name; }
	
	void print() override
	{
		Figure::print();
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c <<" d=" <<d<< "\nУглы: A=" << A << " B=" << B << " C=" << C <<" D="<<D<< "\n";
	}

};
class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
	{
		name = "Параллелограмм";
	}

};

class Rangle : public Parallelogram
{
public:
	Rangle (int a, int b) : Parallelogram (a,b,90,90)
	{
		name = "Прямоугольник";
	}
};

class Square: public Rangle
{
public:
	Square(int a) : Rangle(a, a)
	{
		name = "Квадрат";
	}
};


class Rhombus : public Parallelogram
{
public:
	Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B)
	{
		name = "Ромб";

	}
};

void print_info(Figure *F)
{
	F->print();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Triangle ABC(10, 20, 30, 50, 60, 70);
	print_info(&ABC);
	std::cout << '\n';

	Right_triangle rABC(10,20,30,50,60);
	print_info(&rABC);
	std::cout << '\n';

	Isosceles_triangle iABC(10, 20, 50, 60);
	print_info(&iABC);
	std::cout << '\n';

	Equilateral_triangle eABC(30);
	print_info(&eABC);
	std::cout << '\n';

	Quadrangle ABCD(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&ABCD);
	std::cout << '\n';

	Rangle rABCD(10, 20);
	print_info(&rABCD);
	std::cout << '\n';

	Square sABCD (20);
	print_info(&sABCD);
	std::cout << '\n';

	Parallelogram pABCD(20, 30, 30, 40);
	print_info(&pABCD);
	std::cout << '\n';

	Rhombus rhABCD(30, 30, 40);
	print_info(&rhABCD);
	std::cout << '\n';
}
