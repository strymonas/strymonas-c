#include "benchmarks.h"
#include <assert.h>
#include <stdio.h>

// printf("%d\n", fn(v1, v1n, v2, v2n));
#define RUN2(take_mod, v1n, v2n, fn, ideal) \
  { allocs2(take_mod, &v1, v1n);\
    allocs2(take_mod, &v2, v2n);\
    assert(fn(v1n, v1, v2n, v2) == ideal);\
    free(v1);\
    free(v2);}

int64_t *v1, *v2;

const int64_t v = 100000000;
const int64_t vHi = 10000000;
const int64_t vLo = 10;
const int64_t vFaZ = 10000;
const int64_t vZaF = 10000000;

/* Allocatate and initialize working arrays */
static void allocs(void)
{
  int64_t i;
  assert ((v1 = (int64_t *)calloc(v,sizeof v1[0])));
  for(i=0; i<v; i++)
    v1[i] = i % 10;
}

static void allocs2(int take_mod, int64_t **arr_p, const int64_t n)
{
  int64_t i;
  assert (((*arr_p) = (int64_t *)calloc(n,sizeof (*arr_p)[0])));
  if(take_mod) {
    for(i=0; i<n; i++)
      (*arr_p)[i] = i % 10;
  } else {
    for(i=0; i<n; i++)
      (*arr_p)[i] = i;
  }
}

int main(void)
{
  {
    allocs();
    assert(sum(v,v1)              == 450000000);
    assert(sum_squares(v,v1)      == 2850000000);
    assert(sum_squares_even(v,v1) == 1200000000);
    assert(maps(v,v1)             == 2268000000000);
    assert(filters(v,v1)          == 170000000);
    free(v1);
  }

  {
    RUN2(1, vHi,  vLo,  cart,                  2025000000);
    RUN2(1, vHi,  vHi,  dot_product,           285000000);
    RUN2(0, vFaZ, vFaZ, flatmap_after_zipwith, 1499850000000);
    RUN2(0, vZaF, vZaF, zipwith_after_flatmap, 99999990000000);
    RUN2(1, vHi,  vLo,  flat_map_take,         405000000);
    RUN2(1, v,    vHi,  zip_filter_filter,     64000000);
    RUN2(1, v,    vLo,  zip_flat_flat,         3250000000);
  }

  {
    int64_t arr1[] = {0,1,255,0,255,1,255,255};
    int64_t arr2[] = {1,0,255,0,255,255,0,255,255,255,1};
    // uint8_t arr1[] = {0,1,255,0,255,1,255,255};
    // uint8_t arr2[] = {1,0,255,0,255,255,0,255,255,255,1};
    assert(decoding(8,arr1,11,arr2) == 6);
  }

  printf("All tests were completed!\n");
}
