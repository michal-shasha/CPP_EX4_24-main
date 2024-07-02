//325763498
//michalshasha8@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <stdexcept>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0);

    // Getters
    double getReal() const;
    double getImag() const;

    // Setters
    void setReal(double r);
    void setImag(double i);

    // Operator Overloads
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    bool operator<(const Complex& other) const;
    bool operator>(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    Complex operator-() const;

    // Friend Function for Output Stream
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
};

#endif // COMPLEX_HPP
