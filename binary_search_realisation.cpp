#include "binary_search.hpp"
#include <algorithm>
#include <stdexcept>

namespace bs {

    template<typename T>
    int binary_search_iterative(const std::vector<T>& arr, const T& target) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            }
            else if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    template<typename T>
    int binary_search_recursive_impl(const std::vector<T>& arr, const T& target,
        int left, int right) {
        if (left > right) return -1;

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] < target)
            return binary_search_recursive_impl(arr, target, mid + 1, right);
        else
            return binary_search_recursive_impl(arr, target, left, mid - 1);
    }

    template<typename T>
    int binary_search_recursive(const std::vector<T>& arr, const T& target) {
        return binary_search_recursive_impl(arr, target, 0,
            static_cast<int>(arr.size()) - 1);
    }

    // ============================================================================
    // Для дубликатов
    // ============================================================================

    template<typename T>
    int lower_bound(const std::vector<T>& arr, const T& target) {
        int left = 0;
        int right = static_cast<int>(arr.size());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

    template<typename T>
    int upper_bound(const std::vector<T>& arr, const T& target) {
        int left = 0;
        int right = static_cast<int>(arr.size());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

    template<typename T>
    int find_first_occurrence(const std::vector<T>& arr, const T& target) {
        int idx = lower_bound(arr, target);
        if (idx != static_cast<int>(arr.size()) && arr[idx] == target) {
            return idx;
        }
        return -1;
    }

    // ============================================================================
    // Для особых массивов
    // ============================================================================

    template<typename T>
    int find_min_in_rotated(const std::vector<T>& arr) {
        if (arr.empty()) return -1;

        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }

    template<typename T>
    int search_in_rotated(const std::vector<T>& arr, const T& target) {
        if (arr.empty()) return -1;

        int left = 0;
        int right = static_cast<int>(arr.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) return mid;

            if (arr[left] <= arr[mid]) {
                if (arr[left] <= target && target < arr[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (arr[mid] < target && target <= arr[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

    template<typename T>
    int find_last_occurrence(const std::vector<T>& arr, const T& target) {
        int ub = upper_bound(arr, target);

        if (ub > 0 && arr[ub - 1] == target) {
            return ub - 1;
        }

        return -1;
    }

    template<typename T>
    int count_occurrences(const std::vector<T>& arr, const T& target) {
        int first = find_first_occurrence(arr, target);

        if (first == -1) {
            return 0;
        }

        int last = find_last_occurrence(arr, target);
        return last - first + 1;
    }






    template int binary_search_iterative<int>(const std::vector<int>&, const int&);
    template int binary_search_iterative<double>(const std::vector<double>&, const double&);
    template int binary_search_iterative<float>(const std::vector<float>&, const float&);
    template int binary_search_iterative<long>(const std::vector<long>&, const long&);\
    template int binary_search_recursive<long long>(const std::vector<long long>&, const long long&);

    template int binary_search_recursive<int>(const std::vector<int>&, const int&);
    template int binary_search_recursive<double>(const std::vector<double>&, const double&);
    template int binary_search_recursive<float>(const std::vector<float>&, const float&);
    template int binary_search_recursive<long>(const std::vector<long>&, const long&);
    template int binary_search_recursive<long long>(const std::vector<long long>&, const long long&);

    template int lower_bound<int>(const std::vector<int>&, const int&);
    template int lower_bound<double>(const std::vector<double>&, const double&);
    template int lower_bound<float>(const std::vector<float>&, const float&);
    template int lower_bound<long>(const std::vector<long>&, const long&);
    template int lower_bound<long long>(const std::vector<long long>&, const long long&);

    template int upper_bound<int>(const std::vector<int>&, const int&);
    template int upper_bound<double>(const std::vector<double>&, const double&);
    template int upper_bound<float>(const std::vector<float>&, const float&);
    template int upper_bound<long>(const std::vector<long>&, const long&);
    template int upper_bound<long long>(const std::vector<long long>&, const long long&);

    template int find_first_occurrence<int>(const std::vector<int>&, const int&);
    template int find_first_occurrence<double>(const std::vector<double>&, const double&);
    template int find_first_occurrence<float>(const std::vector<float>&, const float&);
    template int find_first_occurrence<long>(const std::vector<long>&, const long&);
    template int find_first_occurrence<long long>(const std::vector<long long>&, const long long&);

    template int find_min_in_rotated<int>(const std::vector<int>&);
    template int find_min_in_rotated<double>(const std::vector<double>&);
    template int find_min_in_rotated<float>(const std::vector<float>&);
    template int find_min_in_rotated<long>(const std::vector<long>&);
    template int find_min_in_rotated<long long>(const std::vector<long long>&);

    template int search_in_rotated<int>(const std::vector<int>&, const int&);
    template int search_in_rotated<double>(const std::vector<double>&, const double&);
    template int search_in_rotated<float>(const std::vector<float>&, const float&);
    template int search_in_rotated<long>(const std::vector<long>&, const long&);
    template int search_in_rotated<long long>(const std::vector<long long>&, const long long&);

    template int find_last_occurrence<int>(const std::vector<int>&, const int&);
    template int find_last_occurrence<double>(const std::vector<double>&, const double&);
    template int find_last_occurrence<float>(const std::vector<float>&, const float&);
    template int find_last_occurrence<long>(const std::vector<long>&, const long&);
    template int find_last_occurrence<long long>(const std::vector<long long>&, const long long&);

    template int count_occurrences<int>(const std::vector<int>&, const int&);
    template int count_occurrences<double>(const std::vector<double>&, const double&);
    template int count_occurrences<float>(const std::vector<float>&, const float&);
    template int count_occurrences<long>(const std::vector<long>&, const long&);
    template int count_occurrences<long long>(const std::vector<long long>&, const long long&);

} 