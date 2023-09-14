#include <iostream> // Виклик головних модулів
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

float pointLength(int firstX, int firstY, int secondX, int secondY) // Створення функції підрахунку для п'ятого завдання
			{
				float value = sqrt(pow(secondX - firstX, 2) + pow(secondY - firstY, 2));
				return value;
			}

int main()
{
	int taskNum;
	while (true)
	{
		cout << "Choose the task (enter 0 to exit): "; // Вибір задачі
		cin >> taskNum;

		if (taskNum == 0) // Якщо користувач вирішив вийти з програми
		{
			return 0;
		}

		cout << "Variant 7. Task " << taskNum << ":\n";

		if (taskNum == 1) // Якщо обрана задача 1
		{
			int radius; // Створення змінної

			while (true)
			{
				cout << "Enter the radius: "; // Запит на введення значення радіуса
				cin >> radius;

				if (radius < 0)
				{
					cout << "Radius should be >= 0. Try again.\n"; // Запит на повторне введення, якщо радіус < 0
				}
				else
				{
					break;
				}
			}
			float circuit = 2 * 3.1415 * radius; // Виконання розрахунків
			cout << "Circuit: " << circuit << endl;
			float circleArea = pow(radius, 2) * 3.1415;
			cout << "The area of circle: " << circleArea << endl;
			float sphereVolume = 4 / 3 * 3.1415 * pow(radius, 3);
			cout << "The volume of sphere: " << sphereVolume << endl;
		}

		else if (taskNum == 2) // Якщо обрана задача 2
		{
			int number; // Створення змінної
			string month[]
			{
				"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
			}; // Створення масиву з місяцями для застосування в завданні

			Again1:
			cout << "Enter the number: "; // Запит на введення числа
			cin >> number;

			if (1 == number || 2 == number || 12 == number) // Цикл для визначення пори року
			{
				cout << "You've chosen " << month[number - 1] << ", which belongs to Winter.\n";
			}
			else if (3 <= number && number <= 5)
			{
				cout << "You've chosen " << month[number - 1] << ", which belongs to Spring.\n";
			}
			else if (6 <= number && number <= 8)
			{
				cout << "You've chosen " << month[number - 1] << ", which belongs to Summer.\n";
			}
			else if (9 <= number && number <= 11)
			{
				cout << "You've chosen " << month[number - 1] << ", which belongs to Autumn.\n";
			}
			else
			{
				cout << "Month with such number doesn't exist. Choose between 1 and 12.\n"; 
				goto Again1; // Запит на повторне введення числа, якщо введене неправильне значення
			}
		}

		else if (taskNum == 3) // Якщо обрана задача 3
		{
			int n, num = 0; // Створення змінних
			float S = 1;

			Again2:
			cout << "Please, enter the value of variable n: "; // Запит на введення значення змінної
			cin >> n;
			if (n < 1)
			{
				cout << "This number is not natural. Try again.\n"; // Запит на повторне введення, якщо введено не натуральне число
				goto Again2;
			}
			do // Цикл обчислення виразу
			{
				num++;
				S = S * (1 + 1 / pow(num, 2));
			} while (num < n);
			cout << "If n = " << n << ", S = " << S << "." << endl; // Виведення результату
		}
		else if (taskNum == 4) // Якщо обрана задача 4
		{
			int array[100], withoutRemainder = 0, num; // Створення масиву та змінних

			srand(time(NULL));

			for (num = 0; num < 100; num++) // Цикл для заповнення масиву та визначення кількості елементів, що діляться на 5 без остачі
			{
				array[num] = rand();
				if (array[num] % 5 == 0)
				{
					withoutRemainder++;
				}
				cout << num + 1 << ")" << array[num] << "   "; // Виведення значень масиву
			}
			cout << endl << "Number of array elements that are divisible by 5 without a remainder: " << withoutRemainder << endl; // Виведення результату
		}
		else if (taskNum == 5) // Якщо обрана задача 5
		{
			int A[2], B[2], C[2]; // Створення масивів для запису координат точок
			float AB, AC, BC, P = 0; // Створення змінних

			cout << "Enter the x and y value of the point A: "; // Запит на введення координат точок
			cin >> A[0] >> A[1];
			cout << "Enter the x and y value of the point B: ";
			cin >> B[0] >> B[1];
			cout << "Enter the x and y value of the point C: ";
			cin >> C[0] >> C[1];

			AB = pointLength(A[0], A[1], B[0], B[1]); // Обчислення відстані між точками за допомогою функції
			AC = pointLength(A[0], A[1], C[0], C[1]);
			BC = pointLength(B[0], B[1], C[0], C[1]);
			P = AB + AC + BC; // Обчислення периметру

			cout << "If A(" << A[0] << ";" << A[1] << "), B(" << B[0] << ";" << B[1] << "), C(" << C[0] << ";" << C[1] << "), then\n";
			cout << "AB = " << AB << ", AC = " << AC << ", BC = " << BC << ", which forms a triangle with P = " << P << ".\n"; // Виведення результату
		}
		else // Якщо обрана задача, якої не існує
		{
			cout << "This task doesn't exist." << endl;
		}
	}
}

