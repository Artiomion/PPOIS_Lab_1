//
// Created by Artem Sotnikov on 18.10.24.
//

#ifndef PPOIS_LAB_1_POLYNOMIALFUNCTION_H
#define PPOIS_LAB_1_POLYNOMIALFUNCTION_H

#include "Polynomial.h"
#include <string>

Polynomial createPolynomial();
std::string showPolynomial(const Polynomial& poly);
std::string showCoefficients(const Polynomial& poly);

#endif //PPOIS_LAB_1_POLYNOMIALFUNCTION_H
