// #define _USE_MATH_DEFINES//
#include <iostream>   
#include <cmath>
#include <Windows.h>
using namespace std;
double func(double x)
{
    return (2 * log(x) + x - 2); // Вычисление функции //
}
double find(double x0, double x1, double eps) // Дихотомии //
{
    double a = x0, b = x1, x, c;  // a b границы диапазона
                                        // c значение х в нуле функции                              
    int iter = 0;
    cout << "x0 = " << x0 << " x1 = " << x1 << " ";
    do {

        x = (a + b) / 2;
        if (func(a) * func(b) < 0) //сравнение 
            c = func(x);
        if (c < 0) b = x;
        else a = x;
        iter++;
    } while (fabs(c) > eps);                   //модуль
    cout << "\nИтерации : " << iter << endl;
    return x;
}
double find2(double x0, double eps) // Метод итераций //
{
    double rez; int iter = 0;
    cout << "x0= " << x0 << " ";
    do {
        rez = x0;
        x0 = sqrt(1+(2/x0));        //извлечение корня из производной
        iter++;
    } while (fabs(rez - x0) > eps); //модуль
    cout << "\nИтерации : " << iter << endl;
    return x0;
}
double find3(double x0, double eps) //Метод Ньютона//
{
    double f, df; int iter = 0;
    cout << "x0= " << x0 << " ";
    do {
        f = 2 * log(x0) + x0 -2;    // функция
        df = -2/pow(x0, 2);         // вторая производная
        x0 = x0 - f / df;
        iter++;
    } while (fabs(f) > eps);        // модуль из функции
    cout << "\nИтерации : " << iter << endl;
    return x0;
}
double find4(double x0, double x1, double eps) //Метод секущих//
{
    double rez = 0, y;
    int iter = 0;
    cout << "x0= " << x0 << " x1= " << x1 << " "; // х0- начало  х1 - конец
    do {
        y = rez;
        rez = x1 - ((x1 - x0) / (func(x1) - func(x0)) * func(x1)); // формула секущих
        x1 = x0;
        x1 = rez;
        iter++;
    } while (fabs(y - rez) > eps); 
    cout << "\nИтерации : " << iter << endl;
    return rez;
}
double find5(double x0, double x1, double eps) //Метод хорд//
{
    int iter = 0;
    cout << "x0= " << x0 << " x1= " << x1 << " ";// х0- начало  х1 - конец
    do
    {
        x0 = x1 - ((x1 - x0) * func(x1)) / (func(x1) - func(x0)); // приближение корня
        x1 = x0 - ((x0 - x1) * func(x0)) / (func(x0) - func(x1)); // приближение корня
        iter++;
    }     while (fabs(x1-x0) > eps);                               // 
    cout << "\nИтерации : " << iter << endl;
    return x1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    double x0, x1, rez, eps;
    cout << "Введите метод, который хотите использовать для решения уравнения \n Введите: \n 1 - для метода дихотомии \n 2 - для метода простых итераций \n 3 - для метода Ньютона \n 4 - для метода секущих \n 5 - для метода хорд \n";
        cin >> N;
        switch (N)
        {
        case 1:
            cout << "Введите x0 = ";
            cin >> x0;
            cout << "Введите x1 = ";
            cin >> x1;
            cout << "Введите eps = ";
            cin >> eps;
            cout << "Приближенное значение = " << find(x0, x1, eps);
            cin.get();
            return 0;
        case 2:
            cout << "Введите x0 = ";
            cin >> x0;
            cout << "Введите eps = ";
            cin >> eps;
            cout << "Приближенное значение = " << find2(x0, eps);
            cin.get();
            return 0;
        case 3:
            cout << "Введите x0 = ";
            cin >> x0;
            cout << "Введите eps = ";
            cin >> eps;
            cout << "Приближенное значение = " << find3(x0, eps);
            cin.get(); return 0;
        case 4:
            cout << "Введите x0 = ";
            cin >> x0;
            cout << "Введите x1 = ";
            cin >> x1;
            cout << "Введите eps = ";
            cin >> eps;
            cout << "Приближенное значение = " << find4(x0, x1, eps);
            cin.get();
            return 0;
        case 5:
            cout << "Введите x0 = ";
            cin >> x0;
            cout << "Введите x1 = ";
            cin >> x1;
            cout << "Введите eps = ";
            cin >> eps;
            cout << "Приближенное значение = " << find5(x0, x1, eps);
            cin.get();
            return 0;
        }
    }

