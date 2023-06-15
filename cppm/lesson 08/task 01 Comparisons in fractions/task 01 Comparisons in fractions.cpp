#include <iostream>
#include <concepts>

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
	/*void print() 
	{
		std::cout << numerator_ << " " << denominator_ << std::endl;
	}*/

	bool operator==(Fraction num)
	{
		return numerator_ == num.numerator_ && denominator_ == num.denominator_;
	}
	bool operator!=(Fraction num)
	{
		return numerator_ != num.numerator_ || denominator_ != num.denominator_;
	}
	bool operator<(Fraction num)
	{
		int temp_num= numerator_;
		int temp_den = denominator_;
		temp_num *= num.denominator_;
		temp_den *= num.denominator_;

		num.numerator_ *= denominator_;
		num.denominator_ *= denominator_;

		return temp_num < num.numerator_;
	}
	bool operator>(Fraction num)
	{
		int temp_num = numerator_;
		int temp_den = denominator_;
		
		temp_num *= num.denominator_;
		temp_den *= num.denominator_;
		
		num.numerator_ *= denominator_;
		num.denominator_ *= denominator_;

		return temp_num > num.numerator_;
	}
	bool operator<=(Fraction num)
	{
		int temp_num = numerator_;
		int temp_den = denominator_;

		temp_num *= num.denominator_;
		temp_den *= num.denominator_;

		num.numerator_ *= denominator_;
		num.denominator_ *= denominator_;
		return temp_num <= num.numerator_;
	}

	bool operator>=(Fraction num)
	{
		int temp_num = numerator_;
		int temp_den = denominator_;

		temp_num *= num.denominator_;
		temp_den *= num.denominator_;

		num.numerator_ *= denominator_;
		num.denominator_ *= denominator_;
		return temp_num >= num.numerator_;
	}
	//auto operator<=>(const Fraction&) const = default; 
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	std::cout << '\n';
	/*f1.print();
	f2.print();*/
	return 0;
}