#include <iostream>
#include <Windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	
	void print()
	{
		std::cout << numerator_ <<"/"<< denominator_ << std::endl;
	}
	Fraction& reduce()
	{
		int sumnod, nod_n=numerator_, nod_d=denominator_;
		while (nod_n != 0 && nod_d != 0)
		{
			if (nod_n > nod_d)
			{
				nod_n = nod_n % nod_d;
			}
			else
			{
				nod_d = nod_d % nod_n;
			}
		}
		sumnod = nod_n + nod_d;
		numerator_ = numerator_ / sumnod;
		denominator_ = denominator_ / sumnod;
		return *this;
	}
	Fraction operator+(Fraction num)
	{
		int temp_num = numerator_;
		int temp_den = denominator_;

		temp_num *= num.denominator_;
		temp_den *= num.denominator_;

		num.numerator_ *= denominator_;
		
		return Fraction(temp_num + num.numerator_, temp_den);

	}
	Fraction operator-(Fraction num)
	{
		int temp_num = numerator_;
		int temp_den = denominator_;

		temp_num *= num.denominator_;
		temp_den *= num.denominator_;

		num.numerator_ *= denominator_;

		return Fraction(temp_num - num.numerator_, temp_den);
	}
	Fraction operator*(Fraction num)
	{
		return Fraction(numerator_ * num.numerator_, denominator_ * num.denominator_);
	}
	Fraction operator/(Fraction num)
	{
		return Fraction(numerator_ * num.denominator_, denominator_ * num.numerator_);
	}
	Fraction operator-()
	{
		return Fraction(-numerator_, denominator_);

	}
	Fraction& operator++()
	{
		numerator_ = numerator_ + denominator_;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction& operator--()
	{
		numerator_ = numerator_ - denominator_;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	friend std::ostream& operator<< (std::ostream& out, const Fraction right);
};

std::ostream& operator<<(std::ostream& out, const Fraction right)
{
	out << right.numerator_ << "/" << right.denominator_;
	return out;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int un1, un2, ud1, ud2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> un1;

	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> ud1;

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> un2;

	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> ud2;

	Fraction f1(un1, ud1);
	Fraction f2(un2, ud2);

	f1.print();
	f2.print();
	
	std::cout << f1 << " + " << f2 << " = " << (f1 + f2).reduce() << "\n";
	std::cout << f1 << " - " << f2 << " = " << (f1 - f2).reduce() << "\n";
	std::cout << f1 << " * " << f2 << " = " << (f1 * f2).reduce() << "\n";
	std::cout << f1 << " / " << f2 << " = " << (f1 / f2).reduce() << "\n";
	std::cout << "(++)"<< f1 << " * " << f2 << " = " << (++f1 * f2).reduce() << "\n";
	std::cout << "значение дроби 1 = " << f1 << "\n";
	std::cout << f1<<"(--)" << " * " << f2 << " = " << (f1-- * f2).reduce() << "\n";
	std::cout << "значение дроби 1 = " << f1 << "\n";
	std::cout << -f1 << " + " << f2 << " = " << (-f1 + f2).reduce() << "\n";

	return 0;
}