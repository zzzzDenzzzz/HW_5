/*Написать программу, выполняющую сортировку одномерного массива целых чисел методом пузырьковой сортировки.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

void initArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 10;
	}
}

void printArray(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

void bubbleSort(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			int variable = array[j];
			if (array[j] > array[j + 1])
			{
				array[j] = array[j + 1];
				array[j + 1] = variable;
			}
		}
	}
}

int main()
{
	const int LENGTH = 10;
	int array[LENGTH];

	srand((unsigned)time(NULL));

	initArray(array, LENGTH);
	printArray(array, LENGTH);
	bubbleSort(array, LENGTH);
	printArray(array, LENGTH);

	return 0;
}
