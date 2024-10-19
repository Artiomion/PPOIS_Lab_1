#include "Polynomial.h"
#include <iostream>
#include "PolynomialUI.h"

using namespace std;

int main() {
    Polynomial poly1 = createPolynomial();
    Polynomial poly2 = createPolynomial();

    cout << "Первый многочлен: " << showPolynomial(poly1) << endl;
    cout << "Второй многочлен: " << showPolynomial(poly2) << endl;

    int c;
    do {
        cout << "\nВыберите действие, которое вы хотите выполнить\n"
                "1. Получить значения коэффициентов\n"
                "2. Вычисление значения многочлена для заданного аргумента\n"
                "3. Сложение двух многочленов\n"
                "4. Вычитание двух многочленов\n"
                "5. Произведение двух многочленов\n"
                "6. Деление двух многочленов\n"
                "7. Завершение программы\n"
                "   Выбор: ";
        cin >> c;
        if (c == 1) {
            cout << "Коэффициенты первого многочлена: " << showCoefficients(poly1) << endl;
            cout << "Коэффициенты второго многочлена: " << showCoefficients(poly2) << endl;
        } else if (c == 2) {
            double x;
            cout << "Введите значение x = "; cin >> x;
            cout << "Значение первого многочлена при x = " << x << ": " << poly1(x) << endl;
            cout << "Значение второго многочлена при x = " << x << ": " << poly2(x) << endl;
        } else if (c == 3) {
            Polynomial sum = poly1 + poly2;
            cout << "Сумма многочленов: " << showPolynomial(sum) << endl;
            poly1 += poly2;
            cout << "Первый многочлен после сложения со вторым (через +=): " << showPolynomial(poly1) << endl;
        } else if (c == 4) {
            Polynomial difference = poly1 - poly2;
            cout << "Разность многочленов: " << showPolynomial(difference) << endl;
            poly1 -= poly2;
            cout << "Первый многочлен после вычитания второго (через -=): " << showPolynomial(poly1) << endl;
        } else if (c == 5) {
            Polynomial product = poly1 * poly2;
            cout << "Произведение многочленов (через *): " << showPolynomial(product) << endl;
            poly1 *= poly2;
            cout << "Первый многочлен после умножения на второй (через *=): " << showPolynomial(poly1) << endl;
        } else if (c == 6) {
            if (poly2.getDegree() == 0 && poly2[0] == 0.0) {
                cout << "\033[1;31mОшибка: Деление на ноль!\033[0m" << endl;
            } else {
                Polynomial quotient = poly1 / poly2;
                cout << "Частное многочленов (через /): " << showPolynomial(quotient) << endl;
                poly1 /= poly2;
                cout << "Первый многочлен после деления на второй (через /=): " << showPolynomial(poly1) << endl;
            }
        } else if (c == 7) {
            cout << "\033[1;32mПрограмма завершена.\033[0m" << endl;
            break;
        } else {
            cout << "\033[1;31mОшибка ввода!\033[0m";
        }
    } while (true);
}
