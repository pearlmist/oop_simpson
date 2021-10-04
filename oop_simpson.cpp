#include <iostream>
#include <cmath>

double function_in_dot(double x) {
    return (pow(x, 2) + 2.0 * x + 1);
}
//function: x^2 + 2x + 1
//задание: формула Симпсона на двух промежутках
int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");
    int a, b; //a, b - пределы интегрирования, где а наименьшее
    double h, result, result2; //h - длина промежутка
    std::cout << "Введите пределы интегрирования a и b:\n";
    std::cin >> a >> b;
    if (std::cin.fail()) {
        std::cout << "Неверное число a или b\n";
        return 0;
    }
    if (b < a) { //меняет местами, если b меньше a
        int temp;
        temp = b;
        b = a;
        a = temp;
    }
    h = (b - a) / 2.0;
    result = h / 3.0 * (function_in_dot(a) + function_in_dot(b) + 4.0 * function_in_dot(a + h)); //составная формула (формула Котеса)
    result2 = (b - a) / 6.0 * (function_in_dot(a) + 4 * function_in_dot((a + b) / 2.0) + function_in_dot(b)); //формула Симпсона
    std::cout << "result (составная формула) = " << result;
    std::cout << "\nresult2 (формула Симпсона) = " << result2;
}