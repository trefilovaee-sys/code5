#include <iostream>
#include <cstdint>
#include <climits>

int32_t divide(int32_t dividend, int32_t divisor) {
    // Проверка деления на ноль
    if (divisor == 0) {
        std::cerr << "Ошибка: деление на ноль!" << std::endl;
        return 0;
    }
    
    // Особый случай: INT32_MIN / -1 = переполнение
    if (dividend == INT32_MIN && divisor == -1) {
        return INT32_MAX;
    }
    
    // Определяем знак результата
    bool negative = (dividend < 0) ^ (divisor < 0);
    
    // Переводим в положительные числа (uint32_t)
    uint32_t abs_dividend, abs_divisor;
    if (dividend == INT32_MIN) {
        abs_dividend = static_cast<uint32_t>(INT32_MAX) + 1;
    } else {
        abs_dividend = (dividend < 0) ? -dividend : dividend;
    }
    if (divisor == INT32_MIN) {
        abs_divisor = static_cast<uint32_t>(INT32_MAX) + 1;
    } else {
        abs_divisor = (divisor < 0) ? -divisor : divisor;
    }
    
    // Если делимое меньше делителя
    if (abs_dividend < abs_divisor) {
        return 0;
    }
    
    // Деление с помощью битовых сдвигов
    uint32_t quotient = 0;
    uint32_t remainder = abs_dividend;
    uint32_t temp = abs_divisor;
    int shift = 0;
    
    // Находим максимальный сдвиг
    while ((temp << 1) > 0 && (temp << 1) <= remainder) {
        temp <<= 1;
        shift++;
    }
    
    // Основной цикл
    while (shift >= 0) {
        if (remainder >= temp) {
            remainder -= temp;
            quotient += (1 << shift);
        }
        temp >>= 1;
        shift--;
    }
    
    // Проверка переполнения
    if (!negative && quotient > static_cast<uint32_t>(INT32_MAX)) {
        return INT32_MAX;
    }
    if (negative && quotient > static_cast<uint32_t>(INT32_MAX) + 1) {
        return INT32_MIN;
    }
    return negative ? -static_cast<int32_t>(quotient) : static_cast<int32_t>(quotient);
}