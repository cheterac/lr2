#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>

namespace {
bool close(double left, double right) {
    return std::fabs(left - right) < 1e-9;
}
}

int main() {
    const int exchange_rate[] = {91, 93, 92, 95, 94, 96, 90, 89, 94, 97};
    constexpr std::size_t n = sizeof(exchange_rate) / sizeof(exchange_rate[0]);
    int days_above_93 = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (exchange_rate[i] > 93) ++days_above_93;
    }

    assert(arr_min(exchange_rate, n) == 89);
    assert(arr_max(exchange_rate, n) == 97);
    assert(close(arr_average(exchange_rate, n), 93.1));
    assert(close(arr_median(exchange_rate, n), 93.5));
    assert(days_above_93 == 5);
    assert(arr_sum(exchange_rate, n) == 931);

    std::cout << "[integration] Variant 21 results are correct\n";
    return 0;
}
