#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <functional>
#include <Windows.h>
#include "Timer.h"


std::mutex m;
void draw (int numthreads, int length, int i)
{

};


int main() {

	int num_threads = 5;

	//std::cout << "Enter number of threads - ";
	//std::cin >> num_threads;

	int length = 10;
	//std::cout << "Enter length - ";
	//std::cin >> length;
	
	std::vector<std::thread> threads(num_threads);

	std::cout << "#\t" << "id\t" << "Progress bar\t" << "Time\n";
	for (int i = 0; i < num_threads; i++)
	{
		threads[i] = std::thread(draw, num_threads, length, i);
	}
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
}