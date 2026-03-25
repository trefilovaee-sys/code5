#ifndef LONG_ARITHMETIC_H
#define LONG_ARITHMETIC_H

#include <vector>
#include <string>

using LongNumber = std::vector<int>;

// Прототипы всех функций длинной арифметики
LongNumber add(const LongNumber& a, const LongNumber& b);
LongNumber subtract(const LongNumber& a, const LongNumber& b);
LongNumber multiply_by_digit(const LongNumber& a, int digit);
LongNumber factorial(int n);
LongNumber power_of_two(int n);
LongNumber fibonacci(int n);
std::string to_string(const LongNumber& num);

#endif