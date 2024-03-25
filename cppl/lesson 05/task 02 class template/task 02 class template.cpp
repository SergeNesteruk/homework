#include <iostream>
#include <Windows.h>
#include <string>

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
		//std::cout << "Создана матрица размера " << row << " на " << col << '\n';
	};
	table(const table& a)
	{
		row = a.row;
		col = a.col;
		table_ = new T * [row] {};
		for (size_t i = 0; i < row; i++)
		{
			table_[i] = new T[col]{};
		}
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				table_[i][j] = a.table_[i][j];
			}
		}
	}
	table& operator = (const table& a)
	{
		if (&a == this)
		{
			return *this;
		}

		for (size_t i = 0; i < row; i++)
		{
			delete[] table_[i];
		}
		delete[] table_;

		row = a.row;
		col = a.col;
		table_ = new T * [row] {};
		for (size_t i = 0; i < row; i++)
		{
			table_[i] = new T[col]{};
		}
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{
				table_[i][j] = a.table_[i][j];
			}
		}

	}
	~table()
	{
			for (int i = 0; i < row; i++)
			{
				delete[] table_[i];
			}
			delete[] table_;
			//std::cout << "Матрица удалена" << '\n';

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
	friend std::ostream& operator <<(std::ostream & out, const table<int>& right);
};

std::ostream& operator<<(std::ostream& out, const table<int>& right)
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


	//table<int> a(3, 5);
	//a[1][1] = 5;
	////std::cout << "Вывод матрицы\n" << a <<'\n';
	//std::cout << "Размер матрицы " << a.Size()<<'\n';
	//
	//std::cout << "Вывод одного элемента " << a[1][1] << '\n';
	//std::cout << '\n';

	auto test = table<int>(2, 3);
	test[0][0] = 4;
		
	std::cout << test[0][0]<<"\n";

	table<int> a1(3, 5);
	table<int> a2(a1);
	table<int> a3(0,0);
	a3 = a1;

	std::cout << "Вывод матрицы\n" << a1 <<'\n';
	std::cout << "Вывод матрицы\n" << a2 << '\n';
	std::cout << "Вывод матрицы\n" << a3 << '\n';

	a3 = test;
	std::cout << "Вывод матрицы\n" << a3 << '\n';
}
