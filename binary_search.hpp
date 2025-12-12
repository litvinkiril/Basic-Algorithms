#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <vector>
#include <functional>

namespace bs {

    // Базовые
    template<typename T>
    int binary_search_iterative(const std::vector<T>& arr, const T& target);

    template<typename T>
    int binary_search_recursive(const std::vector<T>& arr, const T& target);

    // Дубликаты
    template<typename T>
    int lower_bound(const std::vector<T>& arr, const T& target);

    template<typename T>
    int upper_bound(const std::vector<T>& arr, const T& target);

    template<typename T>
    int find_first_occurrence(const std::vector<T>& arr, const T& target);

    // Особые массивы
    template<typename T>
    int find_min_in_rotated(const std::vector<T>& arr);

    template<typename T>
    int search_in_rotated(const std::vector<T>& arr, const T& target);

    template<typename T>
    int find_last_occurrence(const std::vector<T>& arr, const T& target);

    template<typename T>
    int count_occurrences(const std::vector<T>& arr, const T& target);
} // namespace bs

#endif // BINARY_SEARCH_HPP