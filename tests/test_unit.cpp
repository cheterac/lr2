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
    const int values[] = {-5, 0, 3, 3, 8, -2};
    constexpr std::size_t n = sizeof(values) / sizeof(values[0]);
    assert(arr_sum(values, n) == 7);
    assert(arr_max(values, n) == 8);
    assert(arr_min(values, n) == -5);
    assert(close(arr_average(values, n), 7.0 / 6.0));
    assert(arr_count_positive(values, n) == 3);
    assert(arr_count_negative(values, n) == 2);
    assert(arr_count_zero(values, n) == 1);
    assert(arr_product(values, n) == 0);

    const int even[] = {7, 1, 9, 3};
    const int even_copy[] = {7, 1, 9, 3};
    assert(close(arr_median(even, 4), 5.0));
    for (std::size_t i = 0; i < 4; ++i) assert(even[i] == even_copy[i]);

    const int odd[] = {5, 1, 3};
    assert(close(arr_median(odd, 3), 3.0));
    const int product_values[] = {1, 2, 3, 4};
    assert(arr_product(product_values, 4) == 24);

    std::cout << "[unit] All tests passed\n";
    return 0;
}
