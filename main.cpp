#include <iostream>
#include "polynomial.h"

int main() {
    std::cout << "Программа работы с многочленами\n";
    
    int size;
    std::cout << "Введите количество коэффициентов: ";
    std::cin >> size;

    Polynomial p;

    if (size > 0) {
        double* arr = new double[size];
        std::cout << "Введите " << size << " коэффициентов через пробел:";
        for (int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
        p = Polynomial(arr, size); 
        delete[] arr;
    }

    int choice = 0;
    while (true) {
        std::cout << "\nВыберите действие:\n";
        std::cout << "1. Посчитать значение многочлена при конкретном x\n";
        std::cout << "2. Посчитать определенный интеграл\n";
        std::cout << "3. Выйти из программы\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            double x;
            std::cout << "Введите значение x: ";
            std::cin >> x;
            std::cout << "Результат (" << x << ") = " << p.evaluate(x) << "\n";
        } 
        else if (choice == 2) {
            double a, b;
            std::cout << "Введите нижнюю границу интеграла (a): ";
            std::cin >> a;
            std::cout << "Введите верхнюю границу интеграла (b): ";
            std::cin >> b;
            std::cout << "Значение определенного интеграла: " << p.definite_integral(a, b) << "\n";
        } 
        else if (choice == 3) {
            break;
        } 
        else {
            std::cout << "Неверный пункт меню\n";
        }
    }

    return 0;
}


