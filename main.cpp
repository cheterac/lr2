#include "arraylib.h"

#include <iomanip>
#include <iostream>

int main() {
    const int data[] = {5, 3, 8, 1, 9, 2};
    const std::size_t n = sizeof(data) / sizeof(data[0]);

    std::cout << "Массив: ";
    for (std::size_t i = 0; i < n; ++i) {
        if (i != 0) std::cout << ", ";
        std::cout << data[i];
    }
    std::cout << '\n'
              << "Сумма: " << arr_sum(data, n) << '\n'
              << "Минимум: " << arr_min(data, n) << '\n'
              << "Максимум: " << arr_max(data, n) << '\n'
              << "Среднее: " << std::fixed << std::setprecision(2)
              << arr_average(data, n) << '\n'
              << "Медиана: " << arr_median(data, n) << '\n';
    return 0;
}
