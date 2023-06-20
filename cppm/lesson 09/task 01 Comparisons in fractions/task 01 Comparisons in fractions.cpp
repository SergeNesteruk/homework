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
		int temp_num = numerator_;
		
		temp_num *= num.denominator_;
		
		num.numerator_ *= denominator_;
		
		return  temp_num == num.numerator_;
	}
	bool operator!=(Fraction num)
	{
		int temp_num = numerator_;
		
		temp_num *= num.denominator_;
		
		num.numerator_ *= denominator_;
		
		return  temp_num != num.numerator_;
	}
	bool operator<(Fraction num)
	{
		int temp_num = numerator_;
		
		temp_num *= num.denominator_;
		
		num.numerator_ *= denominator_;
		
		return temp_num < num.numerator_;
	}
	bool operator>(Fraction num)
	{
		int temp_num = numerator_;
				
		temp_num *= num.denominator_;
				
		num.numerator_ *= denominator_;
		
		return temp_num > num.numerator_;
	}
	bool operator<=(Fraction num)
	{
		int temp_num = numerator_;
		
		temp_num *= num.denominator_;
		
		num.numerator_ *= denominator_;
		
		return temp_num <= num.numerator_;
	}

	bool operator>=(Fraction num)
	{
		int temp_num = numerator_;
		
		temp_num *= num.denominator_;
		
		num.numerator_ *= denominator_;
		
		return temp_num >= num.numerator_;
	}
	//auto operator<=>(const Fraction&) const = default; 
};

int main()
{
	Fraction f1(1, 2);
	Fraction f2(4, 8);

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