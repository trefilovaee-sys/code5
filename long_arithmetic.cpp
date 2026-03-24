#include "long_arithmetic.h"
#include <algorithm>

// Преобразование вектора в строку
std::string to_string(const LongNumber& num) {
    if (num.empty()) return "0";
    std::string result;
    for (int i = num.size() - 1; i >= 0; i--) {
        result += std::to_string(num[i]);
    }
    return result;
}

// Сложение двух длинных чисел
LongNumber add(const LongNumber& a, const LongNumber& b) {
    LongNumber result;
    int carry = 0;
    size_t max_size = std::max(a.size(), b.size());
    for (size_t i = 0; i < max_size || carry; i++) {
        int digit_a = (i < a.size()) ? a[i] : 0;
        int digit_b = (i < b.size()) ? b[i] : 0;
        int sum = digit_a + digit_b + carry;
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}

// Умножение на однозначное число (0-9)
LongNumber multiply_by_digit(const LongNumber& a, int digit) {
    LongNumber result;
    int carry = 0;
    for (size_t i = 0; i < a.size() || carry; i++) {
        int current = (i < a.size()) ? a[i] * digit + carry : carry;
        result.push_back(current % 10);
        carry = current / 10;
    }
    // Удаляем ведущие нули
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

// Факториал
LongNumber factorial(int n) {
    LongNumber result = {1};
    for (int i = 2; i <= n; i++) {
        result = multiply_by_digit(result, i);
    }
    return result;
}

// 2 в степени n
LongNumber power_of_two(int n) {
    LongNumber result = {1};
    for (int i = 0; i < n; i++) {
        result = multiply_by_digit(result, 2);
    }
    return result;
}

// Числа Фибоначчи
LongNumber fibonacci(int n) {
    if (n == 0) return {0};
    if (n == 1) return {1};
    LongNumber prev = {0};
    LongNumber curr = {1};
    for (int i = 2; i <= n; i++) {
        LongNumber next = add(prev, curr);
        prev = curr;
        curr = next;
    }
    return curr;
}