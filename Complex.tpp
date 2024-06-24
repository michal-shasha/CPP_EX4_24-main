#ifndef COMPLEX_TPP
#define COMPLEX_TPP

#include "Complex.hpp"
#include <stdexcept>
#include <cmath>

Complex::Complex(double r, double i) : real(r), imag(i) {}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

void Complex::set_real(double r) {
    real = r;
}

void Complex::set_imag(double i) {
    imag = i;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Complex((real * other.real + imag * other.imag) / denominator, 
                   (imag * other.real - real * other.imag) / denominator);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

#endif // COMPLEX_TPP

