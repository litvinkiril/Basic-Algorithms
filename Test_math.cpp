#include "math_algo.h"
#include <iostream>
#include <vector>
#include <cassert>

// Вспомогательная функция для сравнения векторов
bool compare_vectors(const std::vector<bool>& v1, const std::vector<bool>& v2) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

// Тесты для gcd
void test_gcd() {
    std::cout << "gcd\n";

    // Test 1
    int result1 = math::gcd(48, 18);
    std::cout << "test 1 " << (result1 == 6 ? "OK" : "ERROR") << std::endl;

    // Test 2
    int result2 = math::gcd(17, 13);
    std::cout << "test 2 " << (result2 == 1 ? "OK" : "ERROR") << std::endl;

    // Test 3
    int result3 = math::gcd(0, 5);
    std::cout << "test 3 " << (result3 == 5 ? "OK" : "ERROR") << std::endl;
}

// Тесты для lcm
void test_lcm() {
    std::cout << "\nlcm\n";

    // Test 1
    int result1 = math::lcm(12, 18);
    std::cout << "test 1 " << (result1 == 36 ? "OK" : "ERROR") << std::endl;

    // Test 2
    int result2 = math::lcm(7, 13);
    std::cout << "test 2 " << (result2 == 91 ? "OK" : "ERROR") << std::endl;

    // Test 3
    int result3 = math::lcm(0, 5);
    std::cout << "test 3 " << (result3 == 0 ? "OK" : "ERROR") << std::endl;
}

// Тесты для extended_gcd
void test_extended_gcd() {
    std::cout << "\nextended_gcd\n";

    // Test 1
    {
        int x, y, g;
        g = math::extended_gcd(35, 15, x, y);
        bool ok = (g == 5) && (35 * x + 15 * y == g);
        std::cout << "test 1 " << (ok ? "OK" : "ERROR") << std::endl;
    }

    // Test 2
    {
        int x, y, g;
        g = math::extended_gcd(17, 13, x, y);
        bool ok = (g == 1) && (17 * x + 13 * y == g);
        std::cout << "test 2 " << (ok ? "OK" : "ERROR") << std::endl;
    }

    // Test 3
    {
        int x, y, g;
        g = math::extended_gcd(8, 12, x, y);
        bool ok = (g == 4) && (8 * x + 12 * y == g);
        std::cout << "test 3 " << (ok ? "OK" : "ERROR") << std::endl;
    }
}

// Тесты для mod
void test_mod() {
    std::cout << "\nmod\n";

    // Test 1
    int result1 = math::mod(17, 5);
    std::cout << "test 1 " << (result1 == 2 ? "OK" : "ERROR") << std::endl;

    // Test 2
    int result2 = math::mod(-17, 5);
    std::cout << "test 2 " << (result2 == 3 ? "OK" : "ERROR") << std::endl;

    // Test 3
    int result3 = math::mod(10, 1);
    std::cout << "test 3 " << (result3 == 0 ? "OK" : "ERROR") << std::endl;
}

// Тесты для sieve_of_eratosthenes
void test_sieve() {
    std::cout << "\nsieve_of_eratosthenes\n";

    // Test 1
    {
        std::vector<bool> result = math::sieve_of_eratosthenes(10);
        std::vector<bool> expected = { false, false, true, true, false, true, false, true, false, false, false };
        std::cout << "test 1 " << (compare_vectors(result, expected) ? "OK" : "ERROR") << std::endl;
    }

    // Test 2
    {
        std::vector<bool> result = math::sieve_of_eratosthenes(2);
        std::vector<bool> expected = { false, false, true };
        std::cout << "test 2 " << (compare_vectors(result, expected) ? "OK" : "ERROR") << std::endl;
    }

    // Test 3
    {
        std::vector<bool> result = math::sieve_of_eratosthenes(1);
        std::vector<bool> expected = { false, false };
        std::cout << "test 3 " << (compare_vectors(result, expected) ? "OK" : "ERROR") << std::endl;
    }
}

// Тесты для fibonacci
void test_fibonacci() {
    std::cout << "\nfibonacci\n";

    // Test 1
    int result1 = math::fibonacci<int>(0);
    std::cout << "test 1 " << (result1 == 0 ? "OK" : "ERROR") << std::endl;

    // Test 2
    int result2 = math::fibonacci<int>(10);
    std::cout << "test 2 " << (result2 == 55 ? "OK" : "ERROR") << std::endl;

    // Test 3
    long long result3 = math::fibonacci<long long>(20);
    std::cout << "test 3 " << (result3 == 6765 ? "OK" : "ERROR") << std::endl;
}

// Тесты для solve_diophantine
void test_diophantine() {
    std::cout << "\nsolve_diophantine\n";

    // Test 1
    {
        int x, y, g;
        bool has_solution = math::solve_diophantine(3, 5, 7, x, y, g);
        bool ok = has_solution && (3 * x + 5 * y == 7);
        std::cout << "test 1 " << (ok ? "OK" : "ERROR") << std::endl;
    }

    // Test 2
    {
        int x, y, g;
        bool has_solution = math::solve_diophantine(6, 9, 12, x, y, g);
        bool ok = has_solution && (6 * x + 9 * y == 12);
        std::cout << "test 2 " << (ok ? "OK" : "ERROR") << std::endl;
    }

    // Test 3
    {
        int x, y, g;
        bool has_solution = math::solve_diophantine(6, 9, 10, x, y, g);
        std::cout << "test 3 " << (!has_solution ? "OK" : "ERROR") << std::endl;
    }
}

// Тесты для is_power_of_two
void test_is_power_of_two() {
    std::cout << "\nis_power_of_two\n";

    // Test 1
    bool result1 = math::is_power_of_two(16);
    std::cout << "test 1 " << (result1 == true ? "OK" : "ERROR") << std::endl;

    // Test 2
    bool result2 = math::is_power_of_two(15);
    std::cout << "test 2 " << (result2 == false ? "OK" : "ERROR") << std::endl;

    // Test 3
    bool result3 = math::is_power_of_two(0);
    std::cout << "test 3 " << (result3 == false ? "OK" : "ERROR") << std::endl;
}

// Тесты для gcd_vector
void test_gcd_vector() {
    std::cout << "\ngcd_vector\n";

    // Test 1
    {
        std::vector<int> nums = { 24, 36, 48, 60 };
        int result = math::gcd_vector(nums);
        std::cout << "test 1 " << (result == 12 ? "OK" : "ERROR") << std::endl;
    }

    // Test 2
    {
        std::vector<int> nums = { 17, 19, 23 };
        int result = math::gcd_vector(nums);
        std::cout << "test 2 " << (result == 1 ? "OK" : "ERROR") << std::endl;
    }

    // Test 3
    {
        std::vector<int> nums = {};
        int result = math::gcd_vector(nums);
        std::cout << "test 3 " << (result == 0 ? "OK" : "ERROR") << std::endl;
    }
}

// Главная функция для запуска всех тестов
void run_all_math_tests() {
    test_gcd();
    test_lcm();
    test_extended_gcd();
    test_mod();
    test_sieve();
    test_fibonacci();
    test_diophantine();
    test_is_power_of_two();
    test_gcd_vector();
}

// Пример использования
int main() {
    run_all_math_tests();
    return 0;
}