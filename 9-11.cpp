#include <math.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double a, b, n, h, tr, pr1, pr2, pr3, pr4, x0, x1, x2, x3, x4, fx0, fx1, fx2, fx3, fx4, c40, c41, c42, c43, c44, Pogr1, Pogr2, Pogr3, Pogr4;
	n = 4;                // Количество интервалов разбиения//   
	tr = 2.53720948;      // Точное решение//
	a = 2;                // начало диапазона//
	b = 4;                // конец диапазона//
	h = (b - a) / n;      // шаг сетки
	x0 = a;               // a с шагом находится
	x1 = a + h;           
	x2 = a + 2 * h;       
	x3 = a + 3 * h;       
	x4 = a + 4 * h;       
	fx0 = pow(log(x0), 2.4); // значения подынтегральной функции в точках 
	fx1 = pow(log(x1), 2.4); // значения подынтегральной функции в точках 
	fx2 = pow(log(x2), 2.4); // значения подынтегральной функции в точках 
	fx3 = pow(log(x3), 2.4); // значения подынтегральной функции в точках 
	fx4 = pow(log(x4), 2.4); // значения подынтегральной функции в точках 
	cout << "h = " << h << "\n\n";
	cout << "x0 = " << x0 << "\n\n";
	cout << "x1 = " << x1 << "\n\n";
	cout << "x2 = " << x2 << "\n\n";
	cout << "x3 = " << x3 << "\n\n";
	cout << "x4 = " << x4 << "\n\n";
	printf("fx0 = %.8f", fx0);
	cout << "\n\n";
	printf("fx1 = %.8f", fx1);
	cout << "\n\n";
	printf("fx2 = %.8f", fx2);
	cout << "\n\n";
	printf("fx3 = %.8f", fx3);
	cout << "\n\n";
	printf("fx4 = %.8f", fx4);
	cout << "\n\n";
	printf("Точное решение = %.8f", tr);
	cout << "\n\n";


	cout << "1) Ньютон-Котес\n";                                      // коэффициенты Котеса
	c40 = c44 = (7 * (b - a)) / 90; 
	c41 = c43 = (16 * (b - a)) / 45;
	c42 = (2 * (b - a)) / 15;
	pr1 = fx0 * c40 + fx1 * c41 + fx2 * c42 + fx3 * c43 + fx4 * c44;  // вычисление функции
	printf("Интеграл = %.8f", pr1);
	cout << "\n";
	Pogr1 = abs(tr - pr1);
	printf("Погрешность = %.8f", Pogr1);
	cout << "\n\n";


	cout << "2)Прямоугольники\n"; 
	pr2 = h * (fx0 + fx1 + fx2 + fx3); // формула правых
	printf("Интеграл = %.8f", pr2);
	cout << "\n";
	Pogr2 = abs(tr - pr2);
	printf("Погрешность = %.8f", Pogr2);
	cout << "\n\n";


	cout << "3) Трапеция\n";
	pr3 = (h / 2) * (fx0 + 2 * (fx1 + fx2 + fx3) + fx4); //вычисление функции
	printf("Интеграл = %.8f", pr3);
	cout << "\n";
	Pogr3 = abs(tr - pr3);
	printf("Погрешность = %.8f", Pogr3);
	cout << "\n\n";


	cout << "4)Парабола\n";
	pr4 = (h / 3) * ((fx0 + fx4) + 2 * fx2 + 4 * (fx1 + fx3)); // вычисление функции
	printf("Интеграл = %.8f", pr4);
	cout << "\n";
	Pogr4 = abs(tr - pr4);
	printf("Погрешность = %.8f ", Pogr4);
	cout << "\n";
}