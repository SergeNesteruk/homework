#include <iostream>

class smart_array
{
private:
	int size;
	int memory_size;
	int* ptr;
public:
	smart_array(int size)
	{
		this->size = size;
		memory_size = size * 2;
		int* ptr = new int[memory_size] {0};
	}
	~smart_array() {
		delete[] ptr;
	}
	int* add_element(int val);
	int get_element(int ind);
};

int smart_array::get_element(int ind)
{
	return ptr[ind];
}
int* smart_array::add_element(int val)
{

}

int main()
{

/*	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}*/
}

