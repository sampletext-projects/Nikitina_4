#include <iostream>
using namespace std;

int is_in(double x1, double y1, double x2, double y2, double x3, double y3)
{
	//Формула расчёта через векторное произведение, 0 - координата центра координат
	//Решение найдено здесь: https://www.cyberforum.ru/post821209.html
	if ((x1 == x2 && x2 == x3) || (y1 == y2 && y2 == y3))
	{
		return -1;
	}
	int a = (x1 - 0) * (y2 - y1) - (x2 - x1) * (y1 - 0);
	int b = (x2 - 0) * (y3 - y2) - (x3 - x2) * (y2 - 0);
	int c = (x3 - 0) * (y1 - y3) - (x1 - x3) * (y3 - 0);

	if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void main(void)
{
	setlocale(LC_ALL, "Russian");

	cout << "Автор: Никитина Дарья Сергеевна\n";
	cout << "Программа для проверки попадания центра координат в треугольник заданный координатами\n";

	int k = -1;
	do
	{
		double x1, y1, x2, y2, x3, y3;
		cout << "Введите 1 точку: ";
		cin >> x1 >> y1;
		cout << "Введите 2 точку: ";
		cin >> x2 >> y2;
		cout << "Введите 3 точку: ";
		cin >> x3 >> y3;

		int res = is_in(x1, y1, x2, y2, x3, y3);

		if (res == -1)
		{
			cout << "Неправильный треугольник\n";
		}
		else if (res == 0)
		{
			cout << "Центр координат вне треугольника\n";
		}
		else
		{
			cout << "Центр координат в треугольнике\n";
		}

		cout << "Повторить(1): ";
		cin >> k;
	}
	while (k == 1);

	system("PAUSE");
}
