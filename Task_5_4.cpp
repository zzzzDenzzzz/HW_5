/*Необходимо отсортировать первые две трети массива в порядке возрастания, если среднее арифметическое всех элементов больше нуля;
иначе - лишь первую треть. Остальную часть массива не сортировать, а расположить в обратном порядке.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void initArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = -99 + rand() % 199;
	}
}

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] <= -10)
		{
			std::cout << array[i] << " ";
		}
		else if (array[i] > -10 && array[i] < 0)
		{
			std::cout << " " << array[i] << " ";
		}
		else if (array[i] >= 0 && array[i] < 10)
		{
			std::cout << "  " << array[i] << " ";
		}
		else
		{
			std::cout << " " << array[i] << " ";
		}
		if ((i + 1) % 20 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

void printArray(int array[], int length_first, int length_last)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED);

	for (int i = 0; i < length_first; i++)
	{
		if (array[i] <= -10)
		{
			std::cout << array[i] << " ";
		}
		else if (array[i] > -10 && array[i] < 0)
		{
			std::cout << " " << array[i] << " ";
		}
		else if (array[i] >= 0 && array[i] < 10)
		{
			std::cout << "  " << array[i] << " ";
		}
		else
		{
			std::cout << " " << array[i] << " ";
		}
		if ((i + 1) % 20 == 0)
		{
			std::cout << std::endl;
		}
	}
	SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	for (int i = length_first; i < length_last; i++)
	{
		if (array[i] <= -10)
		{
			std::cout << array[i] << " ";
		}
		else if (array[i] > -10 && array[i] < 0)
		{
			std::cout << " " << array[i] << " ";
		}
		else if (array[i] >= 0 && array[i] < 10)
		{
			std::cout << "  " << array[i] << " ";
		}
		else
		{
			std::cout << " " << array[i] << " ";
		}
		if ((i + 1) % 20 == 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

bool key(int array[], int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += array[i];
	}

	double arithmetic_mean = static_cast<double>(sum) / length;

	if (arithmetic_mean > 0)
	{
		return true;
	}
	return false;
}

int lengthSortingArray(bool selector, int length)
{
	if (selector)
	{
		return  length * (2.0 / 3);
	}

	return length * (1.0 / 3);
}

void insertSort(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
		{
			int variable = array[j - 1];
			array[j - 1] = array[j];
			array[j] = variable;
		}
	}
}

void otherWay(int array[],int length_first, int length_last)
{
	int length_array = (length_last - length_first) / 2;
	for (int i = 0; i < length_array; i++)
	{
		int variable = array[i + length_first];
		array[i + length_first] = array[length_last - i - 1];
		array[length_last - i - 1] = variable;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO start_attribute;
	GetConsoleScreenBufferInfo(hStdOut, &start_attribute);

	const int LENGTH = 180;
	int array[LENGTH];
	initArray(array, LENGTH);
	printArray(array, LENGTH);

	bool selector = key(array, LENGTH);
	int length_sorting_array = lengthSortingArray(selector, LENGTH);

	insertSort(array, length_sorting_array);
	printArray(array, LENGTH);

	otherWay(array, length_sorting_array, LENGTH);

	printArray(array,length_sorting_array, LENGTH);

	SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);

	return 0;
}
