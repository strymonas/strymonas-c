#ifndef INCLUDED_BENCHMARKS_H
#define INCLUDED_BENCHMARKS_H

#include <stdlib.h>
#include <stdbool.h>
// #include <stdint.h>

int64_t sum(int64_t const n, int64_t * const arr);
int64_t sum_squares(int64_t const n, int64_t * const arr);
int64_t sum_squares_even(int64_t const n, int64_t * const arr);
int64_t maps(int64_t const n, int64_t * const arr);
int64_t filters(int64_t const n, int64_t * const arr);
int64_t cart(int64_t const n1, int64_t * const arr1, int64_t const n2, int64_t * const arr2);
int64_t dot_product(int64_t const n1, int64_t * const arr1, int64_t const n2, int64_t * const arr2);
int64_t flatmap_after_zipwith(int64_t const n1, int64_t * const arr1, int64_t const n2, int64_t * const arr2);
int64_t zipwith_after_flatmap(int64_t const n1, int64_t * const arr1, int64_t const n2, int64_t * const arr2);
int64_t flat_map_take(int64_t const n1, int64_t * const arr1, int64_t const n2, int64_t * const arr2);
int64_t zip_filter_filter(int64_t const n1, int64_t * const arr1, int64_t const n2, int64_t * const arr2);
int64_t zip_flat_flat(int64_t const n1, int64_t * const arr1, int64_t const n2, int64_t * const arr2);

int64_t decoding(int64_t const n1, int64_t * const arr1, int64_t const n2, int64_t * const arr2);
// int64_t decoding(const uint8_t arr1[], const uint64_t n1, const uint8_t arr2[], const uint64_t n2);

#endif
