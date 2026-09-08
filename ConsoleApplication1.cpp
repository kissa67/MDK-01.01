#include <iostream>
using std::cout;
using std::cin;

int zad1()
{
    cout << "C++ is a general-purpose programming language with a bias towards systems programming that  \n";
    cout << "- is a better C\n";
    cout << "- supports data abstraction\n";
    cout << "- supports object-oriented programming\n";
    cout << "- supports generic programming.\n";
    return 0;
}

int zad2()
{
    int num1, num2, sum;
    cin >> num1 >> num2;
    sum = num1 + num2;
    cout << sum << "\n";
    return 0;
}

int zad3()
{
    double sm, inches;
    cin >> sm;
    inches = sm / 2.54;
    cout << inches << "\n";
    return 0;
}

int zad4()
{
    long long n;
    cin >> n;
    cout << n * (n + 1) / 2 << "\n";
    return 0;
}

int main()
{
    zad1();
    cout << "\n";
    zad2();
    cout << "\n";
    zad3();
    cout << "\n";
    zad4();
    return 0;
}