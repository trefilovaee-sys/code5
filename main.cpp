#include <iostream>
#include <cstdint>
#include <climits>
#include "long_arithmetic.h"

// Прототипы функций из других файлов
int32_t divide(int32_t dividend, int32_t divisor);
void func2();

int main() {
    std::cout << "ЗАДАНИЕ 1: длинная арифметика (vector)" << std::endl;
    int n;
    std::cout << "Введите число для факториала (>100): ";
    std::cin >> n;
    if (n > 100) {
        std::cout << n << "! = " << to_string(factorial(n)) << std::endl;
    }
    std::cout << "\nВведите число для 2^n (>64): ";
    std::cin >> n;
    if (n > 64) {
        std::cout << "2^" << n << " = " << to_string(power_of_two(n)) << std::endl;
    }
    int a, b;
    std::cout << "\nВведите a и b для 2^a + 2^b (>64): ";
    std::cin >> a >> b;
    if (a > 64 && b > 64) {
        LongNumber sum = add(power_of_two(a), power_of_two(b));
        std::cout << "2^" << a << " + 2^" << b << " = " << to_string(sum) << std::endl;
    }
    std::cout << "\nВведите a и b для 2^a - 2^b (a>b>64): ";
    std::cin >> a >> b;
    if (a > 64 && b > 64 && a > b) {
        auto pow_a = power_of_two(a);
        auto pow_b = power_of_two(b);
        LongNumber result;
        int borrow = 0;
        for (size_t i = 0; i < pow_a.size(); i++) {
            int digit_a = pow_a[i];
            int digit_b = (i < pow_b.size()) ? pow_b[i] : 0;
            int diff = digit_a - digit_b - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.push_back(diff);
        }
        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }
        std::cout << "2^" << a << " - 2^" << b << " = " << to_string(result) << std::endl;
    }
    std::cout << "\nВведите n для числа Фибоначчи (>100): ";
    std::cin >> n;
    if (n > 100) {
        std::cout << "F(" << n << ") = " << to_string(fibonacci(n)) << std::endl;
    }
    std::cout << "\n\nЗАДАНИЕ 2: деление целых чисел" << std::endl;
    std::cout << "Запрещены операторы: *, /, %, - (кроме особых случаев)" << std::endl;
    int32_t x, y;
    std::cout << "Введите делимое и делитель: ";
    std::cin >> x >> y;
    std::cout << x << " / " << y << " = " << divide(x, y) << std::endl;
    std::cout << "INT32_MIN / -1 = " << divide(INT32_MIN, -1) << std::endl;

    std::cout << "\n\nЗАДАНИЕ 3: обработка исключений" << std::endl;
    std::cout << "Стек вызовов из 6 функций (снизу вверх):" << std::endl;
    std::cout << "1. main() - нижняя" << std::endl;
    std::cout << "2. func2()" << std::endl;
    std::cout << "3. func3() - обрабатывает int и double" << std::endl;
    std::cout << "4. func4() - обрабатывает int" << std::endl;
    std::cout << "5. func5() - пробрасывает" << std::endl;
    std::cout << "6. func6() - выбрасывает double\n" << std::endl;
    
    try {
        std::cout << "main: вызываю func2()" << std::endl;
        func2();
    } catch (int e) {
        std::cout << "\nmain: поймал int: " << e << std::endl;
    } catch (double e) {
        std::cout << "\nmain: поймал double: " << e << std::endl;
    }
    return 0;
}