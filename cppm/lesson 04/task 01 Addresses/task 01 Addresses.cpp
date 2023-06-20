#include <iostream>
#include <fstream>
#include <string>

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
    void print()
    {
        std::cout << city << ", " << street << ", " << house_num << ", " << flat_num << std::endl; //для тестирования, как оно выглядит
    }
    std::string get_out_full_add()
    {
        std::string x = city + ", " + street + ", " + std::to_string(house_num) + ", " + std::to_string(flat_num);
        return x;
    }
 };

int main()
{
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    address test("Msc", "somestreet", 1, 1);

    test.print();

    std::cout<<test.get_out_full_add();

    int add_num = 0;
    fin >> add_num;    //введем количесво адресов
    address* arr_add = new address[add_num];
    


    fin.close();
    fout.close();
}


