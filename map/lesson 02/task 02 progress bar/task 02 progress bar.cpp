#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <functional>
#include <Windows.h>
#include "Timer.h"
#include <stdlib.h>


std::mutex m;
void draw (int numthreads, int i, int length)
{
	auto start = std::chrono::high_resolution_clock::now();

	std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500));
	m.lock();
	consol_parameter::SetPosition(0, i + 1);
	std::cout << i << "\t";
	m.unlock();

	std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500));
	m.lock();
	consol_parameter::SetPosition(10, i + 1);
	std::cout << std::this_thread::get_id() << "\t";
	m.unlock();

	std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500));

	for (int j = 0; j < length; j++)
	{
		m.lock();
		consol_parameter::SetPosition(j+20, i + 1);
		char b = 219;
		std::cout << b;
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 500));
		m.unlock();
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	m.lock();
	consol_parameter::SetPosition(40, i + 1);
	std::cout <<  time << "\n";
	m.unlock();
};

int main() {

	int num_threads = 4;

	//std::cout << "Enter number of threads - ";
	//std::cin >> num_threads;

	int length = 10;
	//std::cout << "Enter length - ";
	//std::cin >> length;
	
	std::vector<std::thread> threads(num_threads);

	std::cout << "#\t" << "id\t" << "Progress bar\t" << "Time\n";
	for (int i = 0; i < num_threads; i++)
	{
		threads[i] = std::thread(draw, num_threads, i, length);
	}
	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	consol_parameter::SetPosition(0, num_threads+1);
}