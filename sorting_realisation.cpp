#include "sorting.hpp"
#include <algorithm>
#include <cmath>

namespace sort {

    // ==================== 1. œ”«€–≈  ====================
    template<typename T>
    void bubble_sort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // ==================== 2. ¬€¡Œ–ŒÃ ====================
    template<typename T>
    void selection_sort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            std::swap(arr[i], arr[min_idx]);
        }
    }

    // ==================== 3. ¬—“¿¬ ¿Ã» ====================
    template<typename T>
    void insertion_sort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            T key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // ==================== 4.  ”◊¿ (ÔÓÏÓ˘ÌËÍ) ====================
    namespace {
        template<typename T>
        void heapify(std::vector<T>& arr, int n, int i) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[left] > arr[largest]) {
                largest = left;
            }

            if (right < n && arr[right] > arr[largest]) {
                largest = right;
            }

            if (largest != i) {
                std::swap(arr[i], arr[largest]);
                heapify(arr, n, largest);
            }
        }
    }

    template<typename T>
    void heap_sort(std::vector<T>& arr) {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    // ==================== 5. œŒƒ—◊≈“ ====================
    void counting_sort(std::vector<int>& arr) {
        if (arr.empty()) return;

        int min_val = arr[0];
        int max_val = arr[0];
        for (int num : arr) {
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }

        int range = max_val - min_val + 1;
        std::vector<int> count(range, 0);

        for (int num : arr) {
            count[num - min_val]++;
        }

        int index = 0;
        for (int i = 0; i < range; i++) {
            while (count[i] > 0) {
                arr[index++] = i + min_val;
                count[i]--;
            }
        }
    }

    // ==================== 6. œŒ–¿«–ﬂƒÕ¿ﬂ (int) ====================
    namespace {
        void counting_sort_for_radix(std::vector<int>& arr, int exp) {
            int n = arr.size();
            std::vector<int> output(n);
            int count[10] = { 0 };

            for (int i = 0; i < n; i++) {
                int digit = (arr[i] / exp) % 10;
                count[digit]++;
            }

            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }

            for (int i = n - 1; i >= 0; i--) {
                int digit = (arr[i] / exp) % 10;
                output[count[digit] - 1] = arr[i];
                count[digit]--;
            }

            arr = std::move(output);
        }
    }

    void radix_sort(std::vector<int>& arr) {
        if (arr.empty()) return;

        int max_val = arr[0];
        for (int num : arr) {
            if (num > max_val) max_val = num;
        }

        for (int exp = 1; max_val / exp > 0; exp *= 10) {
            counting_sort_for_radix(arr, exp);
        }
    }

    // ==================== œ–Œ¬≈– ¿ ====================
    template<typename T>
    bool is_sorted(const std::vector<T>& arr) {
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    template void bubble_sort<int>(std::vector<int>&);
    template void bubble_sort<double>(std::vector<double>&);
    template void bubble_sort<float>(std::vector<float>&);

    template void selection_sort<int>(std::vector<int>&);
    template void selection_sort<double>(std::vector<double>&);
    template void selection_sort<float>(std::vector<float>&);

    template void insertion_sort<int>(std::vector<int>&);
    template void insertion_sort<double>(std::vector<double>&);
    template void insertion_sort<float>(std::vector<float>&);

    template void heap_sort<int>(std::vector<int>&);
    template void heap_sort<double>(std::vector<double>&);
    template void heap_sort<float>(std::vector<float>&);

    template bool is_sorted<int>(const std::vector<int>&);
    template bool is_sorted<double>(const std::vector<double>&);
    template bool is_sorted<float>(const std::vector<float>&);

}