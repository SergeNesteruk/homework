#include <thread>
#include <iostream>
#include <thread>
#include <mutex>

class Data
{
private:
	int a = 0, b = 0;
	std::mutex m;
public:
	Data(int n_a, int n_b)
	{
		a = n_a;
		b = n_b;
	}
	int get_a() { return a; }
	int get_b() { return b; }
};

void lock_swap(Data& obj1, Data& obj2)
{
	;
}

void scoped_swap(Data& obj1, Data& obj2)
{
	;
}

void unique_swap(Data& obj1, Data& obj2)
{
	;
}