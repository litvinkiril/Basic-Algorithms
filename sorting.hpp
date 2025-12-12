#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>

namespace sort {

	// 1. Пузырек (самый понятный)
	template<typename T>
	void bubble_sort(std::vector<T>& arr);

	// 2. Выбором (проще некуда)
	template<typename T>
	void selection_sort(std::vector<T>& arr);

	// 3. Вставками (как карты в руке)
	template<typename T>
	void insertion_sort(std::vector<T>& arr);

	// 4. Куча (пирамидка)
	template<typename T>
	void heap_sort(std::vector<T>& arr);

	// 5. Подсчет
	void counting_sort(std::vector<int>& arr);

	// 6. Поразрядная
	void radix_sort(std::vector<int>& arr);

	// Бонус: проверка отсортированности
	template<typename T>
	bool is_sorted(const std::vector<T>& arr);
	
}

#endif