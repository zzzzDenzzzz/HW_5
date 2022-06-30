/*Написать программу «успеваемость». Пользователь вводит 10 оценок студента. Реализовать меню для пользователя
- Вывод оценок (вывод содержимого массива)
- Пересдача экзамена (пользователь вводит номер элемента массива и новую оценку)
- Выходит ли стипендия (стипендия выходит, если средний бал не ниже 10.7)*/

#include<iostream>
#include<Windows.h>
#include<conio.h>

const double AVERAGE_SCORE = 10.7;
bool exit_menu = false;

void inputGrade(int array[], int length)
{
	std::cout << "Введите оценки(от 1 до 12): \n";

	for (int i = 0; i < length; i++)
	{
		if (i + 1 < 10)
		{
			while (true)
			{
				std::cout << "оценка " << i + 1 << " : ";
				std::cin >> array[i];

				if (array[i] >= 1 && array[i] <= 12)
				{
					std::cin.ignore(32767, '\n');
					break;
				}
				else if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "Oops!\n";
				}
				else
				{
					std::cin.ignore(32767, '\n');
					std::cout << "Oops!\n";
				}
			}
		}
		else
		{
			while (true)
			{
				std::cout << "оценка " << i + 1 << ": ";
				std::cin >> array[i];

				if (array[i] >= 1 && array[i] <= 12)
				{
					std::cin.ignore(32767, '\n');
					break;
				}
				else if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "Oops!\n";
				}
				else
				{
					std::cin.ignore(32767, '\n');
					std::cout << "Oops!\n";
				}
			}
		}
	}
	std::cout << std::endl;
}

void outputGrade(int array[], int length)
{
	std::cout << "Оценки: \n";

	for (int i = 0; i < length; i++)
	{
		if (i + 1 < 10)
		{
			std::cout << "оценка " << i + 1 << " : " << array[i] << std::endl;
		}
		else
		{
			std::cout << "оценка " << i + 1 << ": " << array[i] << std::endl;
		}
	}
	std::cout << std::endl;
}

double grant(int array[], int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += array[i];
	}
	return static_cast<double>(sum) / length;
}

void printGrant(int array[], int length)
{
	double arithmetic_mean = grant(array, length);
	if (arithmetic_mean >= AVERAGE_SCORE)
	{
		std::cout << "Стипендия выходит. Средний бал " << arithmetic_mean;
		std::cout << std::endl << std::endl;
	}
	else
	{
		std::cout << "Стипендия не выходит. Средний бал " << arithmetic_mean;
		std::cout << std::endl << std::endl;
	}
}

int inputNewIndexGrade()
{
	int index;
	while (true)
	{
		std::cout << "Укажите номер оценки: ";
		std::cin >> index;

		if (index >= 1 && index <= 10)
		{
			std::cin.ignore(32767, '\n');
			break;
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cout << "Oops!\n";
		}
	}
	return index;
}

void inputNewGrade(int array[])
{
	int index = inputNewIndexGrade() - 1;
	while (true)
	{
		std::cout << "Введите новую оценку: ";
		std::cin >> array[index];

		if (array[index] >= 1 && array[index] <= 12)
		{
			std::cin.ignore(32767, '\n');
			std::cout << std::endl;
			break;
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cout << "Oops!\n";
		}
	}
}

void menu(int array[], int length)
{
	do
	{
		std::cout << "Выберите действие(1, 2, 3, 4): \n";
		std::cout << "1 - вывод оценок\n";
		std::cout << "2 - пересдача экзамена\n";
		std::cout << "3 - выходит ли стипендия\n";
		std::cout << "4 - выход из программы\n\n";

		char button;
		if (!_kbhit())
		{
			button = _getch();
			switch (button)
			{
			case '1':
				outputGrade(array, length);
				break;
			case '2':
				inputNewGrade(array);
				break;
			case '3':
				printGrant(array, length);
				break;
			case '4':
				exit_menu = true;
				break;
			default:
				std::cout << "Oops!\n";
				break;
			}
		}
	} while (!exit_menu);
}

int main()
{
	SetConsoleOutputCP(1251);

	const int LENGTH = 10;
	int array_grade[LENGTH];

	inputGrade(array_grade, LENGTH);

	menu(array_grade, LENGTH);

	return 0;
}
