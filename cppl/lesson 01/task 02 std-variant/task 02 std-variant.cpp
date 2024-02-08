#include <iostream>
#include <variant>
#include <algorithm>
#include <vector>
#include <string>

std::variant <int, std::string, std::vector<int>> get_variant() {
    std::srand(std::time(nullptr));
    int random_variable = std::rand() % 3;

    std::variant<int, std::string, std::vector<int>> result;
    switch (random_variable)
    {
    case 0:
        result = 5;
        break;
    case 1:
        result = "string";
        break;
    case 2:
        result = std::vector<int>{ 1, 2, 3, 4, 5 };
        break;
    default:
        break;
    }
    return result;
}

int main()
{
    std::cout<<
    //int int_var;
    //std::string string_var;
    //std::vector vec_var{0};

    //if (std::holds_alternative<int>(get_variant()) == true)
    //{
    //            
    //}
}

