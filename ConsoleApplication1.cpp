#include <iostream>
#include <windows.h>
using std::cout;
using std::cin;

int zad1()
{
    cout << "ЗАДАНИЕ 1\n";
    cout << "C++ is a general-purpose programming language with a bias towards systems programming that  \n";
    cout << "- is a better C\n";
    cout << "- supports data abstraction\n";
    cout << "- supports object-oriented programming\n";
    cout << "- supports generic programming.\n";
    return 0;
}

int zad2()
{
    cout << "ЗАДАНИЕ 2\n";
    cout << "Введите два числа: ";
    long long a, b;
    cin >> a >> b;
    cout << "Сумма: " << a + b << "\n";
    return 0;
}

int zad3()
{
    cout << "ЗАДАНИЕ 3\n";
    cout << "Введите сантиметры: ";
    double sm;
    cin >> sm;
    cout << "Дюймы: " << sm / 2.54 << "\n";
    return 0;
}

int zad4()
{
    cout << "ЗАДАНИЕ 4\n";
    cout << "Введите n: ";
    long long n;
    cin >> n;
    cout << "Сумма: " << n * (n + 1) / 2 << "\n";
    return 0;
}

int zad5()
{
    cout << "ЗАДАНИЕ 5\n";
    cout << "Введите координаты (x1 y1 x2 y2): ";
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

int zad6()
{
    cout << "ЗАДАНИЕ 6\n";
    cout << "Введите стороны треугольника: ";
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "UNDEFINED\n";
        return 0;
    }

    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

int zad7()
{
    cout << "ЗАДАНИЕ 7\n";
    cout << "Введите год: ";
    int year;
    cin >> year;

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

int zad8()
{
    cout << "ЗАДАНИЕ 8\n";
    cout << "Введите месяц и год: ";
    int month, year;
    cin >> month >> year;

    int days;

    if (month == 2)
    {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            days = 29;
        else
            days = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else
        days = 31;

    cout << "Дней: " << days << "\n";
    return 0;
}

int zad9()
{
    cout << "ЗАДАНИЕ 9\n";
    cout << "Введите число: ";
    int n;
    cin >> n;

    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    cout << "Сумма цифр: " << sum << "\n";
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    zad1();
    cout << "\n";
    zad2();
    cout << "\n";
    zad3();
    cout << "\n";
    zad4();
    cout << "\n";
    zad5();
    cout << "\n";
    zad6();
    cout << "\n";
    zad7();
    cout << "\n";
    zad8();
    cout << "\n";
    zad9();
    return 0;
}