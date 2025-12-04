#include "binary_search.hpp"
#include <iostream>
#include <vector>
#include <string>

// ANSI коды цветов для консоли
#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_RED     "\033[31m"
#define COLOR_YELLOW  "\033[33m"

// ==================== ТЕСТЫ ДЛЯ БАЗОВЫХ АЛГОРИТМОВ ====================

void binary_search_iterative_test() {
    std::cout << COLOR_YELLOW << "Testing binary_search_iterative:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Обычный массив
    {
        std::vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15 };
        int target = 7;
        int expected = 3;
        int result = bs::binary_search_iterative(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: Элемент не найден
    {
        std::vector<int> arr = { 2, 4, 6, 8, 10 };
        int target = 5;
        int expected = -1;
        int result = bs::binary_search_iterative(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Пустой массив
    {
        std::vector<int> arr = {};
        int target = 5;
        int expected = -1;
        int result = bs::binary_search_iterative(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void binary_search_recursive_test() {
    std::cout << COLOR_YELLOW << "Testing binary_search_recursive:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Обычный массив
    {
        std::vector<int> arr = { 10, 20, 30, 40, 50, 60 };
        int target = 30;
        int expected = 2;
        int result = bs::binary_search_recursive(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: Первый элемент
    {
        std::vector<int> arr = { 1, 2, 3, 4, 5 };
        int target = 1;
        int expected = 0;
        int result = bs::binary_search_recursive(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Последний элемент
    {
        std::vector<int> arr = { 100, 200, 300, 400, 500 };
        int target = 500;
        int expected = 4;
        int result = bs::binary_search_recursive(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

// ==================== ТЕСТЫ ДЛЯ ПОИСКА С ДУБЛИКАТАМИ ====================

void lower_bound_test() {
    std::cout << COLOR_YELLOW << "Testing lower_bound:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Без дубликатов
    {
        std::vector<int> arr = { 1, 3, 5, 7, 9 };
        int target = 5;
        int expected = 2;
        int result = bs::lower_bound(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: С дубликатами
    {
        std::vector<int> arr = { 1, 2, 2, 2, 3, 4, 5 };
        int target = 2;
        int expected = 1;
        int result = bs::lower_bound(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Элемент больше всех
    {
        std::vector<int> arr = { 1, 2, 3, 4, 5 };
        int target = 10;
        int expected = 5;  // arr.size()
        int result = bs::lower_bound(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void upper_bound_test() {
    std::cout << COLOR_YELLOW << "Testing upper_bound:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Без дубликатов
    {
        std::vector<int> arr = { 1, 3, 5, 7, 9 };
        int target = 5;
        int expected = 3;  // индекс первого элемента > 5
        int result = bs::upper_bound(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: С дубликатами
    {
        std::vector<int> arr = { 1, 2, 2, 2, 3, 4, 5 };
        int target = 2;
        int expected = 4;  // индекс первого элемента > 2
        int result = bs::upper_bound(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Все элементы меньше
    {
        std::vector<int> arr = { 1, 2, 3, 4, 5 };
        int target = 0;
        int expected = 0;  // индекс первого элемента > 0
        int result = bs::upper_bound(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void find_first_occurrence_test() {
    std::cout << COLOR_YELLOW << "Testing find_first_occurrence:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Есть дубликаты
    {
        std::vector<int> arr = { 1, 2, 2, 2, 3, 4, 5 };
        int target = 2;
        int expected = 1;
        int result = bs::find_first_occurrence(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: Нет элемента
    {
        std::vector<int> arr = { 1, 3, 5, 7, 9 };
        int target = 4;
        int expected = -1;
        int result = bs::find_first_occurrence(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Один элемент
    {
        std::vector<int> arr = { 5 };
        int target = 5;
        int expected = 0;
        int result = bs::find_first_occurrence(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void find_last_occurrence_test() {
    std::cout << COLOR_YELLOW << "Testing find_last_occurrence:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Есть дубликаты
    {
        std::vector<int> arr = { 1, 2, 2, 2, 3, 4, 5 };
        int target = 2;
        int expected = 3;
        int result = bs::find_last_occurrence(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: Уникальный элемент
    {
        std::vector<int> arr = { 1, 3, 5, 7, 9 };
        int target = 5;
        int expected = 2;
        int result = bs::find_last_occurrence(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Нет элемента
    {
        std::vector<int> arr = { 1, 2, 3, 4, 5 };
        int target = 6;
        int expected = -1;
        int result = bs::find_last_occurrence(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void count_occurrences_test() {
    std::cout << COLOR_YELLOW << "Testing count_occurrences:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Несколько вхождений
    {
        std::vector<int> arr = { 1, 2, 2, 2, 3, 3, 4, 5 };
        int target = 2;
        int expected = 3;
        int result = bs::count_occurrences(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: Одно вхождение
    {
        std::vector<int> arr = { 1, 3, 5, 7, 9 };
        int target = 5;
        int expected = 1;
        int result = bs::count_occurrences(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Нет вхождений
    {
        std::vector<int> arr = { 1, 2, 3, 4, 5 };
        int target = 6;
        int expected = 0;
        int result = bs::count_occurrences(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

// ==================== ТЕСТЫ ДЛЯ ОСОБЫХ МАССИВОВ ====================

void find_min_in_rotated_test() {
    std::cout << COLOR_YELLOW << "Testing find_min_in_rotated:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Обычный случай
    {
        std::vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
        int expected = 4;  // индекс 0
        int result = bs::find_min_in_rotated(arr);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: Не сдвинутый массив
    {
        std::vector<int> arr = { 0, 1, 2, 3, 4, 5 };
        int expected = 0;  // индекс 0
        int result = bs::find_min_in_rotated(arr);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Два элемента
    {
        std::vector<int> arr = { 2, 1 };
        int expected = 1;  // индекс 1 (значение 1)
        int result = bs::find_min_in_rotated(arr);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

void search_in_rotated_test() {
    std::cout << COLOR_YELLOW << "Testing search_in_rotated:" << COLOR_RESET << std::endl;
    int passed = 0;
    int total = 3;

    // Тест 1: Элемент найден
    {
        std::vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
        int target = 0;
        int expected = 4;
        int result = bs::search_in_rotated(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 1: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 1: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 2: Элемент не найден
    {
        std::vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
        int target = 3;
        int expected = -1;
        int result = bs::search_in_rotated(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 2: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 2: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    // Тест 3: Не сдвинутый массив
    {
        std::vector<int> arr = { 1, 2, 3, 4, 5 };
        int target = 3;
        int expected = 2;
        int result = bs::search_in_rotated(arr, target);

        if (result == expected) {
            std::cout << COLOR_GREEN << "  Test 3: OK" << COLOR_RESET << std::endl;
            passed++;
        }
        else {
            std::cout << COLOR_RED << "  Test 3: NO (expected " << expected << ", got " << result << ")" << COLOR_RESET << std::endl;
        }
    }

    std::cout << COLOR_YELLOW << "  Result: " << passed << "/" << total << " passed" << COLOR_RESET << std::endl << std::endl;
}

// ==================== ГЛАВНАЯ ФУНКЦИЯ ТЕСТИРОВАНИЯ ====================

void run_all_tests() {
    std::cout << COLOR_YELLOW << "========== STARTING BINARY SEARCH TESTS ==========" << COLOR_RESET << std::endl << std::endl;

    // Базовые алгоритмы
    binary_search_iterative_test();
    binary_search_recursive_test();

    // Поиск с дубликатами
    lower_bound_test();
    upper_bound_test();
    find_first_occurrence_test();
    find_last_occurrence_test();
    count_occurrences_test();

    // Особые массивы
    find_min_in_rotated_test();
    search_in_rotated_test();

    std::cout << COLOR_YELLOW << "========== TESTS COMPLETED ==========" << COLOR_RESET << std::endl;
}