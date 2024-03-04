#include <iostream>
#include <Windows.h>
#include <string>
//Все ячейки таблицы имеют один и тот же тип данных T.
//
//Требования к классу :
//
//Должен быть конструктор, получающий на входе два целых числа — количество строк и столбцов соответственно.
//Должны быть константная и неконстантная версии оператора[], возвращающего массив, к которому снова можно применить оператор[].
//Нужно, чтобы работали конструкции вида :
//*cout << table[i][j]; *table[i][j] = value; .
//
//Должна быть константная функция Size, возвращающая размер таблицы.

template <class T>
class table
{
private:
	int row;
	int col;
	T** table_ = nullptr;
public:
	table(int rows, int cols)
	{
		row = rows;
		col = cols;
		table_ = new T* [row] {};
		for (size_t i = 0; i < row; i++)
		{
			table_[i] = new T [col] {};
		}
		std::cout << "Создана матрица размера " << row << " на " << col << '\n';
	};
	~table()
	{
			for (int i = 0; i < row; i++)
			{
				delete[] table_[i];
			}
			delete[] table_;
			std::cout << "Матрица удалена" << '\n';

	};

	std::string Size() const
	{
		std::string size = std::to_string(col) + "x" + std::to_string(row);
		return size;
	}


	T *operator [] (const int index)
	{
		return table_[index];
	}


	const T* operator [] (const int index) const
	{
		return table_[index];
	}

	table& operator= (const T value)
	{
		table_[row][col] = value;
		return *this;
	}
	friend std::ostream& operator <<(std::ostream & out, const table<T>& right);
};

std::ostream& operator<<(std::ostream& out, const table<T>& right)
{
	for (int i = 0; i < right.row; i++) {
		for (int j = 0; j < right.col; j++)
		{
			out << right.table_[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	table<double> a(3, 5);
	a[1][1] = 5;
	std::cout << "Вывод матрицы\n" << a <<'\n';
	std::cout << "размер матрицы " << a.Size()<<'\n';
	
	std::cout << "Вывод одного элемента " << a[1][1] << '\n';
}
