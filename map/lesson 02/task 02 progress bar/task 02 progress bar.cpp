#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <functional>
#include <Windows.h>


std::mutex m;
void par_print_thread(int numthreads, int length)
{
	char b = 219;
	std::vector<std::thread> threads(numthreads);
	for (int i = 0; i < numthreads; ++i)
	{
		threads[i] = std::thread([i, b, length]()
			{
				std::unique_lock mutex(m);
				//std::unique_lock mutex(m, std::adopt_lock);
				//std::scoped_lock scoped_mutex(m);
				auto start = std::chrono::high_resolution_clock::now();
				std::cout << i << "\t" << std::this_thread::get_id() << "\t";
				for (int j = 0; j < length; j++)
				{
					//std::unique_lock mutex(m);
					//std::unique_lock mutex(m, std::adopt_lock);
					//std::scoped_lock scoped_mutex(m);
					std::cout << b;
					std::this_thread::sleep_for(std::chrono::milliseconds(20));
				}
				std::cout << '\t';
				auto end = std::chrono::high_resolution_clock::now();
				std::chrono::duration<double> time = end - start;
				std::cout << time << "\n";
			});
	}
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
};


int main() {
	char b = 219;

	int num_threads = 0;

	std::cout << "Enter number of threads - ";
	std::cin >> num_threads;

	int length = 0;
	std::cout << "Enter length - ";
	std::cin >> length;
	std::cout << "#\t" << "id\t" << "Progress bar\t" << "Time\n";

	par_print_thread(num_threads, length);
}


