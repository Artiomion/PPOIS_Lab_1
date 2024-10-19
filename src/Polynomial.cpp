//
// Created by Artem Sotnikov on 12.10.24.
//
#include "Polynomial.h"
#include <cmath>
#include <stdexcept>

using namespace std;

Polynomial::Polynomial(int deg, const vector<double>& coeffs) {
    degree = deg;
    coefficients = coeffs;
}

int Polynomial::getDegree() const {
    return degree;
}

const double& Polynomial::operator[](int index) const {
    return coefficients[index];
}

Polynomial& Polynomial::operator+=(const Polynomial& other) {
    int maxDegree = max(degree, other.degree);
    coefficients.resize(maxDegree + 1, 0.0);

    for (int i = 0; i <= other.degree; ++i) {
        coefficients[i] += other[i];
    }

    degree = maxDegree;
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result = *this;
    result += other;
    return result;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    int maxDegree = max(degree, other.degree);
    coefficients.resize(maxDegree + 1, 0.0);

    for (int i = 0; i <= other.degree; ++i) {
        coefficients[i] -= other[i];
    }

    degree = maxDegree;
    while (degree > 0 && coefficients[degree] == 0.0) {
        --degree;
    }

    return *this;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result = *this;
    result -= other;
    return result;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    if (coefficients.empty() || other.coefficients.empty() ||
        (degree == 0 && coefficients[0] == 0.0)) {
        coefficients = {0.0};
        degree = 0;
        return *this;
    }

    vector<double> result(degree + other.degree + 1, 0.0);

    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= other.degree; ++j) {
            result[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    coefficients = std::move(result);
    degree += other.degree;

    while (degree > 0 && coefficients[degree] == 0.0) {
        --degree;
    }

    return *this;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result = *this;
    result *= other;
    return result;
}

Polynomial& Polynomial::operator/=(const Polynomial& divisor) {
    if (divisor.degree == 0 && divisor.coefficients[0] == 0.0) {
        throw invalid_argument("Деление на ноль");
    }

    if (degree < divisor.degree) {
        coefficients = {0.0};
        degree = 0;
        return *this;
    }

    Polynomial remainder = *this;
    vector<double> quotient(degree - divisor.degree + 1, 0.0);

    for (int i = degree; i >= divisor.degree; --i) {
        quotient[i - divisor.degree] = remainder.coefficients[i] / divisor.coefficients[divisor.degree];
        for (int j = 0; j <= divisor.degree; ++j) {
            remainder.coefficients[i - j] -= quotient[i - divisor.degree] * divisor.coefficients[divisor.degree - j];
        }
    }

    while (quotient.size() > 1 && quotient.back() == 0.0) {
        quotient.pop_back();
    }

    coefficients = quotient;
    degree = coefficients.size() - 1;

    return *this;
}

Polynomial Polynomial::operator/(const Polynomial& divisor) const {
    Polynomial result = *this;
    result /= divisor;
    return result;
}

double Polynomial::operator()(double x) const {
    double result = 0.0;
    for (int i = degree; i >= 0; --i) {
        result += coefficients[i] * pow(x, i);
    }
    return result;
}
