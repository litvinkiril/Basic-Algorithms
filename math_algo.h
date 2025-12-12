#ifndef MATH_H
#define MATH_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>

namespace math {

    // 1) Алгоритм Евклида
    template<typename T>
    T gcd(T a, T b) {
        while (b != 0) {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // 2) Наименьшее общее кратное
    template<typename T>
    T lcm(T a, T b) {
        if (a == 0 || b == 0) return 0;
        return std::abs(a * b) / gcd(a, b);
    }

    // 3) Расширенный алгоритм Евклида
    // Возвращает НОД(a, b) и коэффициенты x, y такие что ax + by = gcd(a, b)
    template<typename T>
    T extended_gcd(T a, T b, T& x, T& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }

        T x1, y1;
        T gcd = extended_gcd(b, a % b, x1, y1);

        x = y1;
        y = x1 - (a / b) * y1;

        return gcd;
    }

    // 4) Деление по модулю
    template<typename T>
    T mod(T a, T m) {
        T result = a % m;
        return result >= 0 ? result : result + m;
    }

    // 5) Решето Эратосфена
    std::vector<bool> sieve_of_eratosthenes(int n) {
        if (n < 2) return std::vector<bool>(n, false);

        std::vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        return is_prime;
    }

    // 6) Вычисление i-го числа Фибоначчи
    template<typename T>
    T fibonacci(int n) {
        if (n < 0) throw std::invalid_argument("n must be non-negative");
        if (n <= 1) return n;

        T a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            T temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }

    // 7) Решение диофантового уравнения ax + by = c
    // Возвращает true, если решение существует
    template<typename T>
    bool solve_diophantine(T a, T b, T c, T& x, T& y, T& gcd_ab) {
        gcd_ab = extended_gcd(std::abs(a), std::abs(b), x, y);

        if (c % gcd_ab != 0) {
            return false;
        }

        x *= c / gcd_ab;
        y *= c / gcd_ab;

        if (a < 0) x = -x;
        if (b < 0) y = -y;

        return true;
    }

    // 8) Проверка на степень двойки
    template<typename T>
    bool is_power_of_two(T n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }

    // 9) Вычисление НОД для вектора чисел
    template<typename T>
    T gcd_vector(const std::vector<T>& numbers) {
        if (numbers.empty()) return 0;

        T result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            result = gcd(result, numbers[i]);
            if (result == 1) break;
        }
        return result;
    }

}

#endif 