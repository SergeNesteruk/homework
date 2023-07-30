#include <Windows.h>
#include <iostream>


class Triangle
{
protected:
	int a, b, c; //sides
	int A, B, C; //angles
	std::string name;
public:
	Triangle(int a, int b, int c, int A, int B, int C)
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
	void print()
	{
		std::cout << name<<"\nСтороны: " << a << " " << b << " " << c << "\nУглы: " << A << " " << B << " " << C << "\n";
	}
};
class Right_triangle: public Triangle
{
public:
	Right_triangle( int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, C)
	{
		name = "Прямоугольный треугольник";
		C = 90;
	}
};

class Isosceles_triangle : public Triangle
{
public:
	Isosceles_triangle (int a, int b, int A, int B) : Triangle(a, b, c, A, B, C)
	{
		name = "Равнобедренный треугольник";
		C = A;
		c = a;
	}
};

class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle (int a) : Triangle(a, b, c, A, B, C)
	{
		name = "Равносторонний треугольник";
		b = a;
		c = a;
		A = B = C = 60;
	}
};


class Quadrangle
{
protected:
	int a, b, c, d; //sides
	int A, B, C, D; //angles
	std::string name;
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
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
	void print()
	{
		std::cout << name << "\nСтороны: " << a << " " << b << " " << c <<" " <<d<< "\nУглы: " << A << " " << B << " " << C <<" "<<D<< "\n";
	}

};
class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D)
	{
		c = a;
		d = b;
		C = A;
		D = B;
		name = "Параллелограмм";
	}

};

class Rangle : public Parallelogram
{
public:
	Rangle (int a, int b) : Parallelogram (a,b,A,B)
	{
		c = a;
		d = b;
		A = B = C = D = 90;
		name = "Прямоугольник";
	}
};

class Square: public Rangle
{
public:
	Square(int a) : Rangle(a, b)
	{
		d = c = b = a;
		name = "Квадрат";
	}
};


class Rhombus : public Parallelogram
{
public:
	Rhombus(int a, int A, int B) : Parallelogram(a, b, A, B)
	{
		b = c = d = a;
		C = A; D = B;
		name = "Ромб";

	}
};

void print_info(Triangle* F)
{
	std::cout << F->get_name() << "\nСтороны: a=" << F->get_a() << " b=" << F->get_b() << " c=" << F->get_c() << "\nУглы: A=" << F->get_A() << " B=" << F->get_B() << " C=" << F->get_C() <<"\n";
}

void print_info(Quadrangle *F)
{
	std::cout << F->get_name() << "\nСтороны: a=" << F->get_a() << " b=" << F->get_b() << " c=" << F->get_c() << " d=" << F->get_d() << "\nУглы: A=" << F->get_A() << " B=" << F->get_B() << " C=" << F->get_C() << " D=" << F->get_D() << "\n";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Triangle ABC(10, 20, 30, 50, 60, 70);
	//ABC.print();

	Right_triangle rABC(10,20,30,50,60);
	//rABC.print();

	Isosceles_triangle iABC(10, 20, 50, 60);
	//iABC.print();

	Equilateral_triangle eABC(30);
	//eABC.print();

	Quadrangle ABCD(10, 20, 30, 40, 50, 60, 70, 80);
	//ABCD.print();

	Rangle rABCD(10, 20);
	//rABCD.print();

	Square sABCD (20);
	//sABCD.print();

	Parallelogram pABCD(20, 30, 30, 40);
	//pABCD.print();

	Rhombus rhABCD(30, 30, 40);
	//rhABCD.print();

	print_info(&ABC);
	std::cout << '\n';
	print_info(&rABC);
	std::cout << '\n';
	print_info(&iABC);
	std::cout << '\n';
	print_info(&eABC);
	std::cout << '\n';
	print_info(&ABCD);
	std::cout << '\n';
	print_info(&rABCD);
	std::cout << '\n';
	print_info(&sABCD);
	std::cout << '\n';
	print_info(&pABCD);
	std::cout << '\n';
	print_info(&rhABCD);
	std::cout << '\n';
}
