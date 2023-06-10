#include <fstream>
#include <iostream>

int main()
{
    int n = 0, m = 0; // инициализация размеров массивов

    std::ifstream fin("in.txt");
    
    fin >> n; //задали размер массива из файла для массива n

    int* n_arr = new int[n]; // выделели память для массива n

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

    //изменение массивов
    int temp = m_arr[m-1];
    for ( int i = m-1; i>= 0; i--)
    {
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[0] = temp;

    int temp1 = n_arr[0];
    for (int i = 1; i < n; i++)
    {
        n_arr[i-1] = n_arr[i];
    }
    n_arr[n - 1] = temp1;

    //вывод
    std::ofstream fout ("out.txt");

    fout << m << "\n";
    for (int i = 0; i < m; i++)
    {
        fout << m_arr[i] << " ";
    }

    fout << "\n" << n << "\n";
    for (int i = 0; i < n; i++)
    {
        fout << n_arr[i] << " ";
    }

    
    delete[] n_arr;
    delete[] m_arr;
    fin.close();
    fout.close();

}