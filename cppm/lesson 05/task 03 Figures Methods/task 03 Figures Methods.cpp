#include <Windows.h>
#include <iostream>

class Figure
{
protected:
	std::string name;
	std::string correctness;
	int sides_count;
	
public:
	Figure()
	{
		name = "Фигура";
		sides_count = 0;
	}

	virtual void check_correct()
	{
		if (sides_count == 0)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}
	virtual void print()
	{
		check_correct();
		std::cout << name << ":\n" << correctness << "\n" << "Количество сторон: " << sides_count<<std::endl;
	}
};

class Triangle : public Figure
{
protected:
	int a, b, c; //sides
	int A, B, C; //angles

public:
	Triangle(int a, int b, int c, int A, int B, int C) : Figure()
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		sides_count = 3;
		name = "Треугольник";
	}

	void check_correct() override
	{
		if (sides_count == 3 && A + B + C == 180)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}
	void print() override
	{
		Figure::print();
		std::cout <<"Стороны: a=" << a << " b=" << b << " c=" << c << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n";
	}
};

class Right_triangle : public Triangle
{
public:
	Right_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
	{
		name = "Прямоугольный треугольник";
	}
	void check_correct() override
	{
		Triangle::check_correct();
		if (correctness == "Правильная" && C == 90)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}
};

class Isosceles_triangle : public Triangle
{
public:
	Isosceles_triangle (int a, int b, int A, int B) : Triangle(a, b, c, A, B, C)
	{
		name = "Равнобедренный треугольник";
		c = a;
		C = A;
	}
	void check_correct() override
	{
		Triangle::check_correct();
		if (correctness == "Правильная" && A == C && a==c)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}
};

class Equilateral_triangle : public Triangle
{
public:
	Equilateral_triangle (int a) : Triangle(a, b, c, 60, 60, 60)
	{
		name = "Равносторонний треугольник";
		b = c = a;
	}
	void check_correct() override
	{
		Triangle::check_correct();
		if (correctness == "Правильная" && a==b && a==c && b==c && A==60 && B==60 && C==60)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}

};

class Quadrangle : public Figure
{
protected:
	int a, b, c, d; //sides
	int A, B, C, D; //angles
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure ()
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		sides_count = 4;
		name = "Четырехугольник";
	}
	void check_correct() override
	{
		if (sides_count == 4 && A + B + C + D == 360)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}
	void print() override
	{
		Figure::print();
		std::cout <<"Стороны: a=" << a << " b=" << b << " c=" << c <<" d="<< d <<"\nУглы: A=" << A << " B=" << B << " C=" << C <<" D="<< D << "\n";
	}

};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D)
	{
		name = "Параллелограмм";
		c = a; d = b;
		C = A; D = B; 
	}
	void check_correct() override
	{
		Quadrangle::check_correct();
		if (correctness == "Правильная" && a==c && b==d && A==C && B==D)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}

};

class Rangle : public Parallelogram
{
public:
	Rangle(int a, int b) : Parallelogram(a, b, 90, 90)
	{
		name = "Прямоугольник";
		c = a; d = b;
	}
	void check_correct() override
	{
		Parallelogram::check_correct();
		if (correctness == "Правильная" && A==90 && B == 90 && C == 90 && D == 90)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}

};

class Square : public Rangle
{
public:
	Square(int a) : Rangle(a, b)
	{
		name = "Квадрат";
		d = c = b = a;
	}
	void check_correct() override
	{
		Rangle::check_correct();
		if (correctness == "Правильная" && a == b && a == c && a == d && b == c && b == d && c == d)
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}
};


class Rhombus : public Parallelogram
{
public:
	Rhombus(int a, int A, int B) : Parallelogram(a, b, A, B)
	{
		name = "Ромб";
		d = c = b = a;
	}
	void check_correct() override
	{
		Parallelogram::check_correct();
		if (correctness == "Правильная" && a == b && a == d && b == c && c == d) 
		{
			correctness = "Правильная";
		}
		else
		{
			correctness = "Неправильная";
		}
	}

};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	Figure F;
	F.print();
	std::cout << "\n";

	Triangle ABC(10, 20, 30, 50, 60, 70);
	Figure* ABC_ptr = &ABC;

	ABC_ptr->print();
	std::cout << "\n";

	Right_triangle rABC(10, 20, 30, 50, 60);
	Figure* rABC_ptr = &rABC;

	rABC_ptr->print();
	std::cout << "\n";

	Right_triangle rABC1(10, 20, 30, 50, 40);
	Figure* rABC_ptr1 = &rABC1;

	rABC_ptr1->print();
	std::cout << "\n";

	Isosceles_triangle iABC(10, 20, 50, 60);
	Figure* iABC_ptr = &iABC;

	iABC_ptr->print();
	std::cout << "\n";

	Equilateral_triangle eABC(30);
	Figure* eABC_ptr = &eABC;

	eABC_ptr->print();
	std::cout << "\n";

	Quadrangle ABCD(10, 20, 30, 40, 50, 60, 70, 80);
	Figure* ABCD_ptr = &ABCD;

	ABCD_ptr->print();
	std::cout << "\n";

	Rangle rABCD(10, 20);
	Figure* rABCD_ptr = &rABCD;

	rABCD_ptr->print();
	std::cout << "\n";

	Square sABCD(20);
	Figure* sABCD_ptr = &sABCD;

	sABCD_ptr->print();
	std::cout << "\n";

	Parallelogram pABCD(20, 30, 30, 40);
	Figure* pABCD_ptr = &pABCD;

	pABCD_ptr->print();
	std::cout << "\n";

	Rhombus rhABCD(30, 30, 40);
	Figure* rhABCD_ptr = &rhABCD;

	rhABCD_ptr->print();
}

