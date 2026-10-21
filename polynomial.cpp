#include "polynomial.h"
#include <utility>
#include <cmath> 

Polynomial::Polynomial() {
    coeffs = nullptr;
    deg = -1;
}

Polynomial::Polynomial(const double* arr, int size) {
    if (size <= 0 || arr == nullptr) {
        coeffs = nullptr;
        deg = -1;
    } else {
        deg = size - 1;
        coeffs = new double[size];

        for (int i = 0; i < size; i++) {
            coeffs[i] = arr[i];
        }
    }
}

// правило пяти 
Polynomial::~Polynomial() {
    delete[] coeffs;
}

Polynomial::~Polynomial(const Polynomial& other) {
    deg = other.deg;
    if (deg >= 0) {
        coeffs = new double[deg + 1];
        for (int i = 0; i <= deg; i++) {
            coeffs[i] = other.coeffs[i];
        }
    } else {
        coeffs = nullptr;
    }
}

Polynomial::Polynomial(Polynomial&& other) noexcept {
    coeffs = other.coeffs;
    deg = other.deg;

    other.coeffs = nullptr;
    other.deg = -1;
}

void Polynomial::swap(Polynomial& other) noexcept {
    std::swap(coeffs, other.coeffs);
    std::swap(deg, other.deg);
}

Polynomial& Polynomial::operator=(Polynomial other) {
    this->swap(other);
    return *this;
}

double Polynomial::difinite_integral(double a, double b) const {
    if (deg < 0 || coeffs == nullptr) return 0.0;

    double integral_b = 0.0;
    double integral_a = 0.0;

    for (int i = 0; i <= deg; i++) {
        int new_power = i + 1;

        double new_coeff = coeffs[i] / new_power;

        integral_b += new_coeff * std::pow(b, new_power);
        integral_a += new_coeff * std::pow(a, new_power);
    }

    return integral_b - integral_a;
}

double Polynomial::evaluate(double x) const {
    if (deg < 0 || coeffs == nullptr) return 0.0;
    double result = 0.0;
    for (int i = 0; i <= deg; i++) {
        result += coeffs[i] * std::pow(x, i);
    }
    return result;
}

int Polynomial::get_degree() const {
    return deg;
}











