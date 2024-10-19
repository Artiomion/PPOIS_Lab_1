//
// Created by Artem Sotnikov on 18.10.24.
//
#include "gtest/gtest.h"
#include "Polynomial.h"
#include "PolynomialFunction.h"
#include <sstream>

// Тест для функции showCoefficients
TEST(PolynomialFunctionTest, ShowCoefficientsTest) {
    Polynomial poly(2, {1.0, 2.0, 3.0});
    std::string expected_output = "3.000000, 2.000000, 1.000000";

    std::string result = showCoefficients(poly);
    EXPECT_EQ(result, expected_output);
}

// Тест для функции showPolynomial
TEST(PolynomialFunctionTest, ShowPolynomialTest) {
    Polynomial poly(2, {1.0, 2.0, 3.0});
    std::string expected_output = "3.000000x^2 + 2.000000x^1 + 1.000000";

    std::string result = showPolynomial(poly);
    EXPECT_EQ(result, expected_output);
}

// Тест для функции createPolynomial через ввод данных с помощью потоков
TEST(PolynomialFunctionTest, CreatePolynomialTest) {
    // Используем stringstream для симуляции пользовательского ввода
    std::istringstream input("2\n3.0\n2.0\n1.0\n");
    std::cin.rdbuf(input.rdbuf());  // Подменяем стандартный поток ввода на stringstream

    Polynomial poly = createPolynomial();

    EXPECT_EQ(poly.getDegree(), 2);
    EXPECT_EQ(poly[0], 1.0);
    EXPECT_EQ(poly[1], 2.0);
    EXPECT_EQ(poly[2], 3.0);
}

