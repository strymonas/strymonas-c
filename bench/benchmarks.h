#ifndef INCLUDED_BENCHMARKS_H
#define INCLUDED_BENCHMARKS_H

#include <stdlib.h>
#include <stdbool.h>
// #include <stdint.h>

int64_t sum(const int64_t arr[], const int64_t n);
int64_t sum_squares(const int64_t arr[], const int64_t n);
int64_t sum_squares_even(const int64_t arr1[], const int64_t size_arr1);
int64_t maps(const int64_t arr1[], const int64_t size_arr1);
int64_t filters(const int64_t arr1[], const int64_t size_arr1);
int64_t cart(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2);
int64_t dot_product(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2);
int64_t flatmap_after_zipwith(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2);
int64_t zipwith_after_flatmap(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2);
int64_t flat_map_take(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2);
int64_t zip_filter_filter(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2);
int64_t zip_flat_flat(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2);

int64_t decoding(const int64_t arr1[], const int64_t size_arr1, const int64_t arr2[], const int64_t size_arr2);
// int64_t decoding(const uint8_t arr1[], const uint64_t size_arr1, const uint8_t arr2[], const uint64_t size_arr2);

#endif