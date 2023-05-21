#include <iostream>
#include <Windows.h>

struct address 
{
    std::string city;
    std::string street;
    int house_num;
    int flat_num;
    int index;
};

void struct_output (address & add)
{
    std::cout << "Город: " << add.city << "\n";
    std::cout << "Улица: " << add.street << "\n";
    std::cout << "Номер дома: " << add.house_num << "\n";
    std::cout << "Номер квартиры: " << add.flat_num << "\n";
    std::cout << "Индекс: " << add.index << "\n";
};

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    
    address user1 = { "Москва", "Арбат", 12, 8, 123456 };

    struct_output(user1);

    std::cout << "\n"; 
    
    address user2;
    user2.city = "Ижевск";
    user2.street = "Пушкина";
    user2.house_num = 59;
    user2.flat_num = 143;
    user2.index = 953769;

    struct_output(user2);

    std::cout << "\n";
    
    address user3;
    address* us3 = &user3;
    (*us3).city = "Астрахань";
    (*us3).street = "Кирова";
    (*us3).house_num = 82;
    (*us3).flat_num = 1;
    (*us3).index = 414045;

    struct_output(user3);

    std::cout << "\n";
    
    address user4;
    address* us4 = &user4;
    us4->city = "Калиниград";
    us4->street = "Дзержинского";
    us4->house_num = 57;
    us4->flat_num = 378;
    us4->index = 453861;

    struct_output(user4); 
}
