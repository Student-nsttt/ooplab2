#pragma once
#include <iostream>

class Polynomial {
private:
    double* coeffs_ = nullptr; // Массив коэффициентов: индекс = степень x
    int degree_ = -1;          // Степень многочлена (-1 для нулевого)

    void trim();               // Вспомогательный метод для удаления старших нулей

public:
    // 1. Базовые конструкторы
    Polynomial(); // Нулевой многочлен
    Polynomial(const double* coeffs, int degree);

    // 2. Правило Пяти (Rule of Five)
    ~Polynomial();                                 // Деструктор
    Polynomial(const Polynomial& other);            // Конструктор копирования
    Polynomial(Polynomial&& other) noexcept;        // Конструктор перемещения
    Polynomial& operator=(Polynomial other);        // Присваивание (copy-and-swap)

    // Вспомогательный метод обмена для copy-and-swap
    void swap(Polynomial& other) noexcept;

    // 3. Обязательный базовый интерфейс (из примеров задания)
    void add(const Polynomial& other);
    void mul(const Polynomial& other);
    double evaluate(double x) const;
    void print(std::ostream& os) const;
    int degree() const { return degree_; }

    // 4. ВАРИАНТ 10: Определенный интеграл
    double definite_integral(double a, double b) const;
};
