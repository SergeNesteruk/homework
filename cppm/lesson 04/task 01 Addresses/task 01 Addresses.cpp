#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class address
{
private:
    std::string city;
    std::string street;
    int house_num, flat_num;
public:
    address (std::string city, std::string street, int house, int flat)
    {
        
        this->city = city;
        this->street = street;
        house_num = house;
        flat_num = flat;
    }

    address ()
    {    
    };
    void set_city(std::string new_city) { city = new_city; } //сеттеры для полей
    void set_street(std::string new_street) { street = new_street; }
    void set_house_num (int new_house) { house_num = new_house; }
    void set_flat_num(int new_flat) { flat_num = new_flat; }

    void print()
    {
        std::cout << city << ", " << street << ", " << house_num << ", " << flat_num << std::endl; //для тестирования, как оно выглядит
    }
    std::string get_out_full_add()
    {
        std::string x = city + ", " + street + ", " + std::to_string(house_num) + ", " + std::to_string(flat_num)+"\n";
        return x;
    }
 };

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    int size = 0;
    fin >> size;

    address *arr_add = new address[size];

    std::string temp_city_in, temp_street_in;
    int temp_house_in = 0, temp_flat_in = 0;

    for (int i = 0; i < size; i++)
    {
        fin >> temp_city_in >> temp_street_in >> temp_house_in >> temp_flat_in;
        arr_add[i].set_city(temp_city_in);
        arr_add[i].set_street(temp_street_in);
        arr_add[i].set_house_num(temp_house_in);
        arr_add[i].set_flat_num(temp_flat_in);
    }

    fout << size<<"\n";
    for (int i = size-1; i >= 0; i--)
    {
        fout << arr_add[i].get_out_full_add();
    }

    fin.close();
    fout.close();
}


