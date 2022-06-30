/*Написать программу, выполняющую сортировку одномерного массива целых чисел методом вставок.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

void initArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = 10 + rand() % 90;
	}
}

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
		if (!((i + 1) % 20) && i != 0)
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void insertionSort(int array[], int length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
		{
			int variable = array[j - 1];
			array[j - 1] = array[j];
			array[j] = variable;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH = 100;

	int array[LENGTH];
	initArray(array, LENGTH);
	printArray(array, LENGTH);
	std::cout << std::endl;

	insertionSort(array, LENGTH);
	printArray(array, LENGTH);
	std::cout << std::endl;

	return 0;
}
