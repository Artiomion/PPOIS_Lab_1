//
// Created by Artem Sotnikov on 12.10.24.
//

#ifndef PPOIS_LAB_1_POLYNOMIAL_H
#define PPOIS_LAB_1_POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Polynomial {
private:
    int degree;                // Степень многочлена
    std::vector<double> coefficients;  // Массив коэффициентов (тип double)
public:
    Polynomial(int deg, const std::vector<double>& coeffs);

    int getDegree() const;
    const double& operator[](int index) const;

    Polynomial& operator+=(const Polynomial& other);
    Polynomial operator+(const Polynomial& other) const;

    Polynomial& operator-=(const Polynomial& other);
    Polynomial operator-(const Polynomial& other) const;

    Polynomial& operator*=(const Polynomial& other);
    Polynomial operator*(const Polynomial& other) const;

    Polynomial& operator/=(const Polynomial& divisor);
    Polynomial operator/(const Polynomial& divisor) const;

    double operator()(double x) const;
};

#endif //PPOIS_LAB_1_POLYNOMIAL_H
