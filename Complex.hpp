#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Getters
    double get_real() const ;
    double get_imag() const ;

    // Setters
    void set_real(double r) ;
    void set_imag(double i) ;

    // Overloaded operators
    Complex operator+(const Complex& other) const ;
    Complex operator-(const Complex& other) const ;
    Complex operator*(const Complex& other) const ;
    Complex operator/(const Complex& other) const ;
    bool operator==(const Complex& other) const ;
    bool operator!=(const Complex& other) const ;

    // Overloaded output operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }
};

#endif // COMPLEX_HPP
