#pragma once
#include <iostream>

class Polynomial {
private:
    double* coeffs = nullptr;
    int deg = -1;

    void trim();              

public:
    Polynomial(); 
    Polynomial(const double* arr, int size);

    ~Polynomial();
    Polynomial(const Polynomial& other);
    Polynomial(Polynomial&& other);
    Polynomial& operator=(Polynomial other);

    void swap(Polynomial& other);         

    double evaluate(double x) const;
    
    int get_degree() const;

    double definite_integral(double a, double b) const;
};

