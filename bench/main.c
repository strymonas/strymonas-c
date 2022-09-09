#if defined(BASELINE)
  #if defined(NOOPT)
    #define ADDSUFFRAW(name) #name"_BaselineCO0"
  #else
    #define ADDSUFFRAW(name) #name"_BaselineCO3"
  #endif
  #define ADDSUFF(name) ADDSUFFRAW(name)
#else
  #if defined(NOOPT)
    #define ADDSUFFRAW(name) #name"_StagedCO0"
  #else
    #define ADDSUFFRAW(name) #name"_StagedCO3"
  #endif
  #define ADDSUFF(name) ADDSUFFRAW(name)
#endif
#include "benchmarks.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define WARMUP 1
#define REPS 2

#define sum_def                   1
#define sum_squares_def           2
#define sum_squares_even_def      3
#define maps_def                  4
#define filters_def               5
#define cart_def                  6
#define dot_product_def           7
#define flatmap_after_zipwith_def 8
#define zipwith_after_flatmap_def 9
#define flat_map_take_def         10
#define zip_filter_filter_def     11
#define zip_filter_filter2_def    12
#define zip_flat_flat_def         13

#define ADDDEF(name) name##_def
#define STRCMP(benchf, bench) (ADDDEF(benchf) == ADDDEF(bench))

#define RUN1() \
  { allocs();\
    int64_t i;\
    for (i=0; i<WARMUP; ++i) {\
      result = BENCHF1 (v1,v);\
    }\
    for (i=0; i<REPS; ++i) {\
      double start = time_in_mili();\
      result = BENCHF1 (v1,v);\
      double end = time_in_mili();\
      results[i] = (end - start);\
    }}
#define RUN2(take_mod, v1n, v2n) \
  { allocs2(take_mod, &v1, v1n);\
    allocs2(take_mod, &v2, v2n);\
    int64_t i;\
    for (i=0; i<WARMUP; ++i) {\
      result = BENCHF2 (v1,v1n, v2,v2n);\
    }\
    for (i=0; i<REPS; ++i) {\
      double start = time_in_mili();\
      result = BENCHF2 (v1,v1n, v2,v2n);\
      double end = time_in_mili();\
      results[i] = (end - start);\
    }}


int64_t *v1, *v2;
const int64_t v = 100000000;
const int64_t vHi = 10000000;
const int64_t vLo = 10;
const int64_t vFaZ = 10000;
const int64_t vZaF = 10000000;


struct timespec ts, te;
char bench[41];
int64_t result;
double results[REPS];


#if defined(BENCHF1)
/* Allocatate and initialize working arrays */
void allocs(void)
{
  int64_t i;
  assert ((v1 = (int64_t *)calloc(v,sizeof v1[0])));
  for(i=0; i<v; i++)
    v1[i] = i % 10;
}

int main(void)
{
  bench[40]= '\0';

  #if STRCMP(BENCHF1, sum)
    strcpy(bench, ADDSUFF(sum));
    RUN1();
  #elif STRCMP(BENCHF1, sum_squares)
    strcpy(bench, ADDSUFF(sumOfSquares));
    RUN1();
  #elif STRCMP(BENCHF1, sum_squares_even)
    strcpy(bench, ADDSUFF(sumOfSquaresEven));
    RUN1();
  #elif STRCMP(BENCHF1, maps)
    strcpy(bench, ADDSUFF(mapsMegamorphic));
    RUN1();
  #elif STRCMP(BENCHF1, filters)
    strcpy(bench, ADDSUFF(filtersMegamorphic));
    RUN1();
  #else
    #error "invalid bench"
  #endif

  printf("%-40s %10.1lf %10.1lf %5.1lf   ms/op\n",\
        bench,\
        mean(results, REPS),\
        mean_error(results, REPS),\
        standard_deviation(results, REPS));
}

#elif defined(BENCHF2)
void allocs2(int take_mod, int64_t **arr_p, const int64_t n)
{
  int i;
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
  bench[40]= '\0';

  #if STRCMP(BENCHF2, cart)
    strcpy(bench, ADDSUFF(cart));
    RUN2(1, vHi, vLo);
  #elif STRCMP(BENCHF2, dot_product)
    strcpy(bench, ADDSUFF(dotProduct));
    RUN2(1, vHi, vHi);
  #elif STRCMP(BENCHF2, flatmap_after_zipwith)
    strcpy(bench, ADDSUFF(flatMapAfterZip));
    RUN2(0, vFaZ, vFaZ);
  #elif STRCMP(BENCHF2, zipwith_after_flatmap)
    strcpy(bench, ADDSUFF(zipAfterFlatMap));
    RUN2(0, vZaF, vZaF);
  #elif STRCMP(BENCHF2, flat_map_take)
    strcpy(bench, ADDSUFF(flatMapTake));
    RUN2(1, vHi, vLo);
  #elif STRCMP(BENCHF2, zip_filter_filter)
    strcpy(bench, ADDSUFF(zipFilterFilter));
    RUN2(1, v, vHi);
  #elif STRCMP(BENCHF2, zip_filter_filter2)
    strcpy(bench, ADDSUFF(zipFilterFilter2));
    RUN2(1, v, vHi);
  #elif STRCMP(BENCHF2, zip_flat_flat)
    strcpy(bench, ADDSUFF(zipFlatMapFlatMap));
    RUN2(1, v, vLo);
  #else
    #error "invalid bench"
  #endif

  printf("%-40s %10.1lf %10.1lf %5.1lf   ms/op\n",\
        bench,\
        mean(results, REPS),\
        mean_error(results, REPS),\
        standard_deviation(results, REPS));
}

#else
int main(void)
{
  printf("%-40s %10s %10s %5s %7s\n", "Benchmark", "Mean", "Mean-Error", "Sdev", "Unit");
}
#endif
