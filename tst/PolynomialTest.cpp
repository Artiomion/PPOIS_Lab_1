//
// Created by Artem Sotnikov on 18.10.24.
//
#include "gtest/gtest.h"
#include "Polynomial.h"
#include <stdexcept>

TEST(PolynomialTest, ConstructorAndGetters) {
    Polynomial poly(2, {1.0, 2.0, 3.0});

    EXPECT_EQ(poly.getDegree(), 2);
    EXPECT_EQ(poly[0], 1.0);
    EXPECT_EQ(poly[1], 2.0);
    EXPECT_EQ(poly[2], 3.0);
}

TEST(PolynomialTest, AdditionOperator) {
    Polynomial poly1(2, {1.0, 2.0, 3.0});
    Polynomial poly2(1, {4.0, 5.0});

    Polynomial result = poly1 + poly2;

    EXPECT_EQ(result.getDegree(), 2);
    EXPECT_EQ(result[0], 5.0);
    EXPECT_EQ(result[1], 7.0);
    EXPECT_EQ(result[2], 3.0);
}

TEST(PolynomialTest, AdditionAssignmentOperator) {
    Polynomial poly1(2, {1.0, 2.0, 3.0});
    Polynomial poly2(1, {4.0, 5.0});

    poly1 += poly2;

    EXPECT_EQ(poly1.getDegree(), 2);
    EXPECT_EQ(poly1[0], 5.0);
    EXPECT_EQ(poly1[1], 7.0);
    EXPECT_EQ(poly1[2], 3.0);
}

TEST(PolynomialTest, SubtractionOperator) {
    Polynomial poly1(2, {1.0, 2.0, 3.0});
    Polynomial poly2(1, {4.0, 5.0});

    Polynomial result = poly1 - poly2;

    EXPECT_EQ(result.getDegree(), 2);
    EXPECT_EQ(result[0], -3.0);
    EXPECT_EQ(result[1], -3.0);
    EXPECT_EQ(result[2], 3.0);
}

TEST(PolynomialTest, SubtractionAssignmentOperator) {
    Polynomial poly1(2, {1.0, 2.0, 3.0});
    Polynomial poly2(1, {4.0, 5.0});

    poly1 -= poly2;

    EXPECT_EQ(poly1.getDegree(), 2);
    EXPECT_EQ(poly1[0], -3.0);
    EXPECT_EQ(poly1[1], -3.0);
    EXPECT_EQ(poly1[2], 3.0);
}

TEST(PolynomialTest, MultiplicationOperator) {
    Polynomial poly1(1, {1.0, 2.0});
    Polynomial poly2(1, {3.0, 4.0});

    Polynomial result = poly1 * poly2;

    EXPECT_EQ(result.getDegree(), 2);
    EXPECT_EQ(result[0], 3.0);
    EXPECT_EQ(result[1], 10.0);
    EXPECT_EQ(result[2], 8.0);
}

TEST(PolynomialTest, MultiplicationAssignmentOperator) {
    Polynomial poly1(1, {1.0, 2.0});
    Polynomial poly2(1, {3.0, 4.0});

    poly1 *= poly2;

    EXPECT_EQ(poly1.getDegree(), 2);
    EXPECT_EQ(poly1[0], 3.0);
    EXPECT_EQ(poly1[1], 10.0);
    EXPECT_EQ(poly1[2], 8.0);
}

TEST(PolynomialTest, DivisionOperator) {
    Polynomial poly1(2, {2.0, -4.0, 2.0});
    Polynomial poly2(1, {1.0, -1.0});

    Polynomial result = poly1 / poly2;

    EXPECT_EQ(result.getDegree(), 1);
    EXPECT_EQ(result[0], 2.0);
    EXPECT_EQ(result[1], -2.0);
}

TEST(PolynomialTest, DivisionAssignmentOperator) {
    Polynomial poly1(2, {2.0, -4.0, 2.0});
    Polynomial poly2(1, {1.0, -1.0});

    poly1 /= poly2;

    EXPECT_EQ(poly1.getDegree(), 1);
    EXPECT_EQ(poly1[0], 2.0);
    EXPECT_EQ(poly1[1], -2.0);
}

TEST(PolynomialTest, DivisionByZeroThrows) {
    Polynomial poly1(1, {1.0, 2.0});
    Polynomial poly2(0, {0.0});

    EXPECT_THROW(poly1 / poly2, std::invalid_argument);
}

TEST(PolynomialTest, EvaluateAtPoint) {
    Polynomial poly(2, {1.0, 2.0, 3.0});

    double result = poly(2.0);

    EXPECT_DOUBLE_EQ(result, 17.0); // 3*2^2 + 2*2 + 1 = 17
}

TEST(PolynomialTest, ZeroPolynomialMultiplication) {
    Polynomial poly1(1, {1.0, 2.0});
    Polynomial zeroPoly(0, {0.0});

    Polynomial result = poly1 * zeroPoly;

    EXPECT_EQ(result.getDegree(), 0);
    EXPECT_EQ(result[0], 0.0);
}

TEST(PolynomialTest, ZeroPolynomialDivision) {
    Polynomial poly1(1, {1.0, 2.0});
    Polynomial zeroPoly(0, {0.0});

    EXPECT_THROW(poly1 /= zeroPoly, std::invalid_argument);
}
