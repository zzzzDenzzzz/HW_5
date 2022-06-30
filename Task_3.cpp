/*Измените программы из первого и второго задания с помощью шаблонов*/

#include<iostream>

const int length = 10;
const int row = 2;
const int row_2 = 5;
const int col = 5;
const int number_arr = 2;

void cout_endl()
{
	std::cout << std::endl;
}

template<typename T>
void printMinMax(T min, T max)
{
	std::cout << "min = " << min << " max = " << max;
}

template<typename T>
void initMatrix(T array[row_2][col])
{
	for (int i = 0; i < row_2; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = (30.0 + rand() % 90) / 2.0;
		}
	}
}

template<typename T>
void printMatrix(T array[row_2][col])
{
	for (int i = 0; i < row_2; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << array[i][j] << "  ";
		}
		cout_endl();
	}
}

template<typename T>
void minMax(T array[row_2][col])
{
	T min = array[0][0];
	T max = array[0][0];
	for (int i = 0; i < row_2; i++)
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

template<typename T>
void sortRows(T array[row_2][col])
{
	for (int i = 0; i < row_2; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < col - 1; k++)
			{
				if (array[j][k] > array[j][k + 1])
				{
					T variable;
					variable = array[j][k];
					array[j][k] = array[j][k + 1];
					array[j][k + 1] = variable;
				}
			}
		}
	}
}

template<typename T>
T maxArrayElement1(T array[length])
{
	T max_element = array[0];
	for (int i = 0; i < length; i++)
	{
		if (max_element < array[i])
		{
			max_element = array[i];
		}
	}
	return max_element;
}

template<typename T>
T maxArrayElement2(T array[row][col])
{
	T max_element = array[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (max_element < array[i][j])
			{
				max_element = array[i][j];
			}
		}
	}
	return max_element;
}

template<typename T>
T maxArrayElement3(T array[number_arr][row][col])
{
	T max_element = array[0][0][0];
	for (int i = 0; i < number_arr; i++)
	{
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				if (max_element < array[i][j][k])
				{
					max_element = array[i][j][k];
				}
			}
		}
	}

	return max_element;
}

template<typename T>
T maxValue(T a, T b)
{
	return (a > b) ? a : b;
}

template<typename T>
T maxValue(T a, T b, T c)
{
	T max = (a > b) ? a : b;
	return (max > c) ? max : c;
}

int main()
{
	using namespace std;

	srand((unsigned)time(NULL));

	int arr_1[row_2][col];
	initMatrix(arr_1);
	printMatrix(arr_1);
	minMax(arr_1);
	cout_endl();
	sortRows(arr_1);
	printMatrix(arr_1);
	minMax(arr_1);
	cout_endl();

	double arr_2[row_2][col];
	initMatrix(arr_2);
	printMatrix(arr_2);
	minMax(arr_2);
	cout_endl();
	sortRows(arr_2);
	printMatrix(arr_2);
	minMax(arr_2);
	cout_endl();

	char arr_3[row_2][col];
	initMatrix(arr_3);
	printMatrix(arr_3);
	minMax(arr_3);
	cout_endl();
	sortRows(arr_3);
	printMatrix(arr_3);
	minMax(arr_3);
	cout_endl();

	int array_int_1[length]{ 9, 8, 3, 6, 12, 1, 5, 7, 0, 4 };
	int max_int_1 = maxArrayElement1(array_int_1);
	cout << max_int_1 << endl;

	double array_double_1[length]{ 9.5, 8, 3, 6, 12.9, 1.5, 5, 7, 0.3, 4 };
	double max_double_1 = maxArrayElement1(array_double_1);
	cout << max_double_1 << endl;

	int array_int_2[row][col]{
		{3, 5, 6, 45, 1},
		{7, 92, 55, 34, 2}
	};
	int max_int_2 = maxArrayElement2(array_int_2);
	cout << max_int_2 << endl;

	double array_double_2[row][col]{
		{3.5, 5, 6.7, 45, 1.1},
		{7, 92.9, 55, 34, 2.6}
	};
	double max_double_2 = maxArrayElement2(array_double_2);
	cout << max_double_2 << endl;

	int array_int_3[number_arr][row][col]{
		{
			{3, 5, 6, 45, 1},
			{7, 92, 55, 34, 2}
		},

		{
			{33, 45, 56, 145, 11},
			{74, 902, 555, 314, 32}
		}
	};
	int max_int_3 = maxArrayElement3(array_int_3);
	cout << max_int_3 << endl;

	double array_double_3[number_arr][row][col]{
		{
			{3.5, 5.6, 6, 45, 1},
			{7, 92, 55, 34.7, 2}
		},

		{
			{33, 45.9, 56, 145, 11},
			{74, 90.2, 555.5, 314, 32}
		}
	};
	double max_double_3 = maxArrayElement3(array_double_3);
	cout << max_double_3 << endl;

	cout << endl;

	int a = 10;
	int b = 12;
	int c = 15;
	cout << maxValue(a, b) << std::endl;
	cout << maxValue(a, b, c) << std::endl;

	return 0;
}
