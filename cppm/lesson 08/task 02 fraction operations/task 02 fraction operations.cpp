#include <iostream>

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

	
};

int main()
{
	return 0;
}