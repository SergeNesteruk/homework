#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {

	std::string str {"Hello world!!"};

	std::cout << "[IN]: "<<str << "\n";

	std::unordered_map<char, int> um;
    for (const char c : str)
        ++um[c];

	std::vector <std::pair <char, int>> vec_map;
	std::copy(um.begin(), um.end(), std::back_inserter(vec_map));

	std::sort(
		vec_map.begin(), vec_map.end(),
		[](const auto& lhs, const auto& rhs) {
			return lhs.second > rhs.second;
		}
	);

	std::cout << "[OUT]: " << "\n";
	for (auto elem : vec_map)
	{
		std::cout << elem.first << ": " << elem.second<< std::endl;
	}
	return 0;
}