#include <fstream>
#include <iostream>

int main()
{
    int n = 0, m = 0; // инициализация размеров массивов

    std::ifstream fin("in.txt");
    
    fin >> n; //задали размер массива из файла для массива n

    int* n_arr = new int[n];//   long *array = new long [num]; // выделели память для массива n

    for (int i = 0; i < n; i++)
    {
        fin >> n_arr[i];
    }

    fin >> m; //задали размер массива из файла для массива m
    
    int* m_arr = new int[m]; // выделели память для массива m

    for (int i = 0; i < m; i++)
    {
        fin >> m_arr[i];
    }

    //тестовый вывод
    std::cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << n_arr[i] << " ";
    }
    std::cout << "\n" << m << "\n";
    for (int i = 0; i < m; i++)
    {
        std::cout << m_arr[i] << " ";
    }
    //std::ofstream fout("out.txt");

    delete[] n_arr;
    delete[] m_arr;
    fin.close();
    //fout.close();

}