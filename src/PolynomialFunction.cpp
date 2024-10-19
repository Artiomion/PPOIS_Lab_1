//
// Created by Artem Sotnikov on 18.10.24.
//
#include "PolynomialFunction.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Polynomial createPolynomial() {
    int degree;
    cout << "Введите степень многочлена: ";
    cin >> degree;

    vector<double> coeffs(degree + 1);
    cout << "Введите коэффициенты: " << endl;
    for (int i = degree; i >= 0; --i) {
        cout << "Коэффициент при x^" << i << ": ";
        cin >> coeffs[i];
    }

    return Polynomial(degree, coeffs);
}

string showPolynomial(const Polynomial& poly) {
    string result;
    for (int i = poly.getDegree(); i >= 0; --i) {
        result += to_string(poly[i]) + (i > 0 ? "x^" + to_string(i) + " + " : "");
    }
    return result;
}

string showCoefficients(const Polynomial& poly) {
    string result;
    for (int i = poly.getDegree(); i >= 0; --i) {
        result += to_string(poly[i]);
        if (i > 0) {
            result += ", ";
        }
    }
    return result;
}