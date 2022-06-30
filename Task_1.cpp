/*Написать перегруженные функции (int, double, char) для выполнения следующих задач:
- Инициализация квадратной матрицы;
- Вывод матрицы на экран;
- Определение максимального и минимального элемента на главной диагонали матрицы;
- Сортировка элементов по возрастанию отдельно для каждой строки матрицы.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

const int row = 5;
const int col = 5;

void cout_endl()
{
	std::cout << std::endl;
}

template<typename T>
void printMinMax(T min, T max)
{
	std::cout << "min = " << min << " max = " << max;
}

void initMatrix(int array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = 10 + rand() % 90;
		}
	}
}

void initMatrix(double array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = (20.0 + rand() % 80) / 10.0;
		}
	}
}

void initMatrix(char array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = 20 + rand() % 20;
		}
	}
}

void printMatrix(int array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << array[i][j] << "  ";
		}
		cout_endl();
	}
}

void printMatrix(double array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << array[i][j] << "  ";
			if ((array[i][j] - static_cast<int>(array[i][j])) == 0)
			{
				std::cout << "  ";
			}
		}
		cout_endl();
	}
}

void printMatrix(char array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << array[i][j] << "  ";
		}
		cout_endl();
	}
}

void minMax(int array[row][col])
{
	int min = array[0][0];
	int max = array[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (min > array[i][j] && i == j)
			{
				min = array[i][j];
			}
			if (max < array[i][j] && i == j)
			{
				max = array[i][j];
			}
		}
	}
	printMinMax(min, max);
	cout_endl();
}

void minMax(double array[row][col])
{
	double min = array[0][0];
	double max = array[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (min > array[i][j] && i == j)
			{
				min = array[i][j];
			}
			if (max < array[i][j] && i == j)
			{
				max = array[i][j];
			}
		}
	}
	printMinMax(min, max);
	cout_endl();
}

void minMax(char array[row][col])
{
	char min = array[0][0];
	char max = array[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (min > array[i][j] && i == j)
			{
				min = array[i][j];
			}
			if (max < array[i][j] && i == j)
			{
				max = array[i][j];
			}
		}
	}
	printMinMax(min, max);
	cout_endl();
}

void sortRows(int array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < col - 1; k++)
			{
				if (array[j][k] > array[j][k + 1])
				{
					int variable;
					variable = array[j][k];
					array[j][k] = array[j][k + 1];
					array[j][k + 1] = variable;
				}
			}
		}
	}
}

void sortRows(double array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < col - 1; k++)
			{
				if (array[j][k] > array[j][k + 1])
				{
					double variable;
					variable = array[j][k];
					array[j][k] = array[j][k + 1];
					array[j][k + 1] = variable;
				}
			}
		}
	}
}

void sortRows(char array[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < col - 1; k++)
			{
				if (array[j][k] > array[j][k + 1])
				{
					char variable;
					variable = array[j][k];
					array[j][k] = array[j][k + 1];
					array[j][k + 1] = variable;
				}
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr_1[row][col];
	initMatrix(arr_1);
	printMatrix(arr_1);
	minMax(arr_1);
	cout_endl();
	sortRows(arr_1);
	printMatrix(arr_1);
	minMax(arr_1);
	cout_endl();

	double arr_2[row][col];
	initMatrix(arr_2);
	printMatrix(arr_2);
	minMax(arr_2);
	cout_endl();
	sortRows(arr_2);
	printMatrix(arr_2);
	minMax(arr_2);
	cout_endl();

	char arr_3[row][col];
	initMatrix(arr_3);
	printMatrix(arr_3);
	minMax(arr_3);
	cout_endl();
	sortRows(arr_3);
	printMatrix(arr_3);
	minMax(arr_3);
	cout_endl();

	return 0;
}
