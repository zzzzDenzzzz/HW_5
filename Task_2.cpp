/*Написать перегруженные функции и протестировать их в основной программе:
- Нахождения максимального значения в одномерном массиве;
- Нахождения максимального значения в двумерном массиве;
- Нахождения максимального значения в трёхмерном массиве;
- Нахождения максимального значения двух целых;
- Нахождения максимального значения трёх целых;*/

#include<iostream>

const int length = 10;
const int row = 2;
const int col = 5;
const int number_arr = 2;

int maxArrayElement1(int array[length])
{
	int max_element = array[0];
	for (int i = 0; i < length; i++)
	{
		if (max_element < array[i])
		{
			max_element = array[i];
		}
	}
	return max_element;
}

double maxArrayElement1(double array[length])
{
	double max_element = array[0];
	for (int i = 0; i < length; i++)
	{
		if (max_element < array[i])
		{
			max_element = array[i];
		}
	}
	return max_element;
}

int maxArrayElement2(int array[row][col])
{
	int max_element = array[0][0];
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

double maxArrayElement2(double array[row][col])
{
	double max_element = array[0][0];
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

int maxArrayElement3(int array[number_arr][row][col])
{
	int max_element = array[0][0][0];
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

double maxArrayElement3(double array[number_arr][row][col])
{
	double max_element = array[0][0][0];
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

int maxValue(int a, int b)
{
	return (a > b) ? a : b;
}

int maxValue(int a, int b, int c)
{
	int max = (a > b) ? a : b;
	return (max > c) ? max : c;
}

int main()
{
	using namespace std;

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
