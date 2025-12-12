#include "sorting.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"

// ==================== ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ====================

std::vector<int> generate_test_array(size_t size) {
    std::vector<int> arr(size);
    for (size_t i = 0; i < size; i++) {
        arr[i] = static_cast<int>(size - i);
    }
    return arr;
}

std::vector<int> generate_random_array(size_t size, int min_val, int max_val) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min_val, max_val);

    for (size_t i = 0; i < size; i++) {
        arr[i] = dist(gen);
    }
    return arr;
}

bool arrays_equal(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// ==================== ТЕСТЫ ДЛЯ КАЖДОЙ СОРТИРОВКИ ====================

void bubble_sort_test() {
    std::cout << COLOR_YELLOW << "Testing bubble_sort:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Простой массив
    {
        std::vector<int> arr = { 5, 2, 8, 1, 9, 3 };
        std::vector<int> expected = { 1, 2, 3, 5, 8, 9 };

        sort::bubble_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO" << COLOR_RESET << std::endl;
            std::cout << "    Expected: 1 2 3 5 8 9" << std::endl;
            std::cout << "    Got: ";
            for (int n : arr) std::cout << n << " ";
            std::cout << std::endl;
        }
    }

    // Тест 2: Уже отсортированный массив
    {
        std::vector<int> arr = { 1, 2, 3, 4, 5 };
        std::vector<int> expected = { 1, 2, 3, 4, 5 };

        sort::bubble_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Большой массив (100 элементов)
    {
        std::vector<int> arr = generate_test_array(100);
        std::vector<int> expected = arr;
        std::sort(expected.begin(), expected.end());

        sort::bubble_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void selection_sort_test() {
    std::cout << COLOR_YELLOW << "Testing selection_sort:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Простой массив
    {
        std::vector<int> arr = { 64, 25, 12, 22, 11 };
        std::vector<int> expected = { 11, 12, 22, 25, 64 };

        sort::selection_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO" << COLOR_RESET << std::endl;
            std::cout << "    Expected: 11 12 22 25 64" << std::endl;
            std::cout << "    Got: ";
            for (int n : arr) std::cout << n << " ";
            std::cout << std::endl;
        }
    }

    // Тест 2: Массив с одинаковыми элементами
    {
        std::vector<int> arr = { 5, 5, 5, 5, 5 };
        std::vector<int> expected = { 5, 5, 5, 5, 5 };

        sort::selection_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Случайный массив
    {
        std::vector<int> arr = generate_random_array(50, 1, 100);
        std::vector<int> expected = arr;
        std::sort(expected.begin(), expected.end());

        sort::selection_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void insertion_sort_test() {
    std::cout << COLOR_YELLOW << "Testing insertion_sort:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Простой массив
    {
        std::vector<int> arr = { 9, 5, 1, 4, 3 };
        std::vector<int> expected = { 1, 3, 4, 5, 9 };

        sort::insertion_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO" << COLOR_RESET << std::endl;
            std::cout << "    Expected: 1 3 4 5 9" << std::endl;
            std::cout << "    Got: ";
            for (int n : arr) std::cout << n << " ";
            std::cout << std::endl;
        }
    }

    // Тест 2: Почти отсортированный массив
    {
        std::vector<int> arr = { 1, 2, 3, 5, 4 };
        std::vector<int> expected = { 1, 2, 3, 4, 5 };

        sort::insertion_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Один элемент
    {
        std::vector<int> arr = { 42 };
        std::vector<int> expected = { 42 };

        sort::insertion_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void heap_sort_test() {
    std::cout << COLOR_YELLOW << "Testing heap_sort:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Простой массив
    {
        std::vector<int> arr = { 4, 10, 3, 5, 1 };
        std::vector<int> expected = { 1, 3, 4, 5, 10 };

        sort::heap_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO" << COLOR_RESET << std::endl;
            std::cout << "    Expected: 1 3 4 5 10" << std::endl;
            std::cout << "    Got: ";
            for (int n : arr) std::cout << n << " ";
            std::cout << std::endl;
        }
    }

    // Тест 2: Большой случайный массив
    {
        std::vector<int> arr = generate_random_array(1000, 1, 10000);
        std::vector<int> expected = arr;
        std::sort(expected.begin(), expected.end());

        sort::heap_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Отрицательные числа
    {
        std::vector<int> arr = { -5, -1, -8, -3, -2 };
        std::vector<int> expected = { -8, -5, -3, -2, -1 };

        sort::heap_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void counting_sort_test() {
    std::cout << COLOR_YELLOW << "Testing counting_sort:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Простой массив
    {
        std::vector<int> arr = { 4, 2, 2, 8, 3, 3, 1 };
        std::vector<int> expected = { 1, 2, 2, 3, 3, 4, 8 };

        sort::counting_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO" << COLOR_RESET << std::endl;
            std::cout << "    Expected: 1 2 2 3 3 4 8" << std::endl;
            std::cout << "    Got: ";
            for (int n : arr) std::cout << n << " ";
            std::cout << std::endl;
        }
    }

    // Тест 2: Массив из одного элемента
    {
        std::vector<int> arr = { 7 };
        std::vector<int> expected = { 7 };

        sort::counting_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Диапазон от 0 до 5
    {
        std::vector<int> arr = { 0, 5, 2, 5, 1, 3, 2, 4, 0, 1 };
        std::vector<int> expected = { 0, 0, 1, 1, 2, 2, 3, 4, 5, 5 };

        sort::counting_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void radix_sort_test() {
    std::cout << COLOR_YELLOW << "Testing radix_sort:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Простой массив
    {
        std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
        std::vector<int> expected = { 2, 24, 45, 66, 75, 90, 170, 802 };

        sort::radix_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO" << COLOR_RESET << std::endl;
            std::cout << "    Expected: 2 24 45 66 75 90 170 802" << std::endl;
            std::cout << "    Got: ";
            for (int n : arr) std::cout << n << " ";
            std::cout << std::endl;
        }
    }

    // Тест 2: Большие числа
    {
        std::vector<int> arr = { 1000, 999, 1001, 500, 1234 };
        std::vector<int> expected = { 500, 999, 1000, 1001, 1234 };

        sort::radix_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Одинаковые числа
    {
        std::vector<int> arr = { 111, 111, 111, 111 };
        std::vector<int> expected = { 111, 111, 111, 111 };

        sort::radix_sort(arr);

        if (arrays_equal(arr, expected)) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void is_sorted_test() {
    std::cout << COLOR_YELLOW << "Testing is_sorted:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Отсортированный массив
    {
        std::vector<int> arr = { 1, 2, 3, 4, 5 };

        if (sort::is_sorted(arr)) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: Неотсортированный массив
    {
        std::vector<int> arr = { 5, 3, 1, 4, 2 };

        if (!sort::is_sorted(arr)) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Пустой массив
    {
        std::vector<int> arr = {};

        if (sort::is_sorted(arr)) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ====================

void run_all_sorting_tests() {
    std::cout << COLOR_YELLOW << "========== STARTING SORTING TESTS ==========" << COLOR_RESET << std::endl << std::endl;

    bubble_sort_test();
    selection_sort_test();
    insertion_sort_test();
    heap_sort_test();
    counting_sort_test();
    radix_sort_test();
    is_sorted_test();

    std::cout << COLOR_YELLOW << "========== SORTING TESTS COMPLETED ==========" << COLOR_RESET << std::endl;
}