#include "arraylib.h"

#include <cstddef>
#include <iomanip>
#include <iostream>

int main() {
    const int exchange_rate[] = {
        91, 93, 92, 95, 94,
        96, 90, 89, 94, 97
    };
    const std::size_t n = sizeof(exchange_rate) / sizeof(exchange_rate[0]);

    int days_above_93 = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (exchange_rate[i] > 93) ++days_above_93;
    }

    std::cout << "Курс по дням: ";
    for (std::size_t i = 0; i < n; ++i) {
        if (i != 0) std::cout << ", ";
        std::cout << exchange_rate[i];
    }
    std::cout << '\n'
              << "Минимальный курс: " << arr_min(exchange_rate, n) << '\n'
              << "Максимальный курс: " << arr_max(exchange_rate, n) << '\n'
              << "Средний курс: " << std::fixed << std::setprecision(2)
              << arr_average(exchange_rate, n) << '\n'
              << "Медиана: " << arr_median(exchange_rate, n) << '\n'
              << "Дней с курсом выше 93: " << days_above_93 << '\n';
    return 0;
}
