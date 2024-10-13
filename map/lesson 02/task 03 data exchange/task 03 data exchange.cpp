#include <thread>
#include <iostream>
#include <thread>
#include <mutex>

class Data
{
private:
	int a = 0, b = 0;
public:
	Data(int n_a, int n_b)
	{
		a = n_a;
		b = n_b;
	}
	std::mutex m;
	int get_a() { return a; }
	int get_b() { return b; }
	void set_a(int new_a) { a = new_a; }
	void set_b(int new_b) { b = new_b; }
	void print()
	{
		std::cout << "a = " << a << "\t" << "b = " << b << "\n";
	}
};

void lock_swap(Data& obj1, Data& obj2)
{
	std::lock (obj1.m, obj2.m);
	
	int temp_a = obj1.get_a();
	int temp_b = obj1.get_b();
	obj1.set_a(obj2.get_a());
	obj1.set_b(obj2.get_b());
	obj2.set_a(temp_a);
	obj2.set_b(temp_b);

	obj1.m.unlock();
	obj2.m.unlock();
}

void scoped_swap(Data& obj1, Data& obj2)
{
	std::scoped_lock scoped_mutex (obj1.m, obj2.m);
	
	int temp_a = obj1.get_a();
	int temp_b = obj1.get_b();
	obj1.set_a(obj2.get_a());
	obj1.set_b(obj2.get_b());
	obj2.set_a(temp_a);
	obj2.set_b(temp_b);
}

void unique_swap(Data& obj1, Data& obj2)
{
	std::unique_lock unique_mutex1 (obj1.m, std::defer_lock);
	std::unique_lock unique_mutex2 (obj2.m, std::defer_lock);

	std::lock(unique_mutex1, unique_mutex2);
	
	int temp_a = obj1.get_a();
	int temp_b = obj1.get_b();
	obj1.set_a(obj2.get_a());
	obj1.set_b(obj2.get_b());
	obj2.set_a(temp_a);
	obj2.set_b(temp_b);

}

int main()
{
	Data obj1(5, 10), obj2(1, 2);

	std::cout << "before lock swap\n" << "obj1 ";
	obj1.print();
	std::cout << "obj2 ";
	obj2.print();
	
	lock_swap(obj1, obj2);
	
	std::cout << "\nafter lock swap\n" << "obj1 ";
	obj1.print();
	std::cout << "obj2 ";
	obj2.print();

	std::cout << "\nbefore scoped_swap\n" << "obj1 ";
	obj1.print();
	std::cout << "obj2 ";
	obj2.print();

	scoped_swap(obj1, obj2);

	std::cout << "\nafter scoped_swap\n" << "obj1 ";
	obj1.print();
	std::cout << "obj2 ";
	obj2.print();

	std::cout << "\nbefore unique_swap\n" << "obj1 ";
	obj1.print();
	std::cout << "obj2 ";
	obj2.print();

	unique_swap(obj1, obj2);

	std::cout << "\nafter unique_swap\n" << "obj1 ";
	obj1.print();
	std::cout << "obj2 ";
	obj2.print();
	
	return 0;
}