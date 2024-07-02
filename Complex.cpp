//325763498
//michalshasha8@gmail.com

#include "Complex.hpp"

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getters
double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

// Setters
void Complex::setReal(double r) {
    real = r;
}

void Complex::setImag(double i) {
    imag = i;
}

// Operator Overloads
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

bool Complex::operator<(const Complex& other) const {
    return std::sqrt(real * real + imag * imag) < std::sqrt(other.real * other.real + other.imag * other.imag);
}

bool Complex::operator>(const Complex& other) const {
    return std::sqrt(real * real + imag * imag) > std::sqrt(other.real * other.real + other.imag * other.imag);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator-() const {
    return Complex(-real, -imag);
}

// Friend Function for Output Stream
std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}
