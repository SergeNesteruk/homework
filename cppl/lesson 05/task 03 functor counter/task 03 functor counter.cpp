#include <iostream>
#include <vector>
#include <algorithm>

class divided_by3 {
private:
	std::vector<int> a;
	int sum;
	int count;
public:
	divided_by3(std::vector<int> a) { this->a = a; }
	int get_sum() { return sum; }
	int get_count() { return count; }
	void operator()() 
	{
		std::for_each(a.begin(), a.end(),
			[&](int n) {
				if (n % 3 == 0)
				{
					sum += n;
					count++;
				}});
	}
};

int main() {
	std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };
	
	divided_by3 A(vec);
	//get_count count;

	std::cout << "[IN]: ";
	for (auto n : vec)
	{
		std::cout << n << ' ';
	}
	A();
	std::cout << "\n[OUT]: get_sum() = " << A.get_sum();
	std::cout << "\n[OUT]: get_count() = " << A.get_count();


}

