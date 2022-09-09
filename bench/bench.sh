#!/bin/sh
# gcc-11 -Q --help=warnings 
CC="gcc-11"
# CFLAGS="-W -Wall -Wno-tautological-compare -O3 -lm -save-temps"
CFLAGS="-W -Wall -Wno-tautological-compare -O3 -lm"
OBJS="utils.o benchmarks_gen.c main.c"
OBJSBASE="utils.o benchmarks_base.c main.c"

benchs1=(\
"sum" \
"sum_squares" \
"sum_squares_even" \
"maps" \
"filters")

benchs2=(\
"cart" \
"dot_product" \
"flatmap_after_zipwith" \
"zipwith_after_flatmap" \
"flat_map_take" \
"zip_filter_filter" \
"zip_flat_flat")

echo "The number of repetition is changed by REPS in main.c"

($CC $CFLAGS -o t.out $OBJS) && ./t.out >| result_o0.csv
($CC $CFLAGS -o t.out $OBJS) && ./t.out >| result_o3.csv
# NOOPT
for bench in ${benchs1[@]}; do
  ($CC $CFLAGS -o ${bench}.out -DBENCHF1=$bench -DNOOPT $OBJS) && ./${bench}.out >> result_o0.csv
  ($CC $CFLAGS -o ${bench}.out -DBENCHF1=$bench -DBASELINE -DNOOPT $OBJSBASE) && ./${bench}.out >> result_o0.csv
done
for bench in ${benchs2[@]}; do
  ($CC $CFLAGS -o ${bench}.out -DBENCHF2=$bench -DNOOPT $OBJS) && ./${bench}.out >> result_o0.csv
  ($CC $CFLAGS -o ${bench}.out -DBENCHF2=$bench -DBASELINE -DNOOPT $OBJSBASE) && ./${bench}.out >> result_o0.csv
done

#OPT
for bench in ${benchs1[@]}; do
  ($CC $CFLAGS -o ${bench}.out -DBENCHF1=$bench $OBJS) && ./${bench}.out >> result_o3.csv
  ($CC $CFLAGS -o ${bench}.out -DBENCHF1=$bench -DBASELINE $OBJSBASE) && ./${bench}.out >> result_o3.csv
done
for bench in ${benchs2[@]}; do
  ($CC $CFLAGS -o ${bench}.out -DBENCHF2=$bench $OBJS) && ./${bench}.out >> result_o3.csv
  ($CC $CFLAGS -o ${bench}.out -DBENCHF2=$bench -DBASELINE $OBJSBASE) && ./${bench}.out >> result_o3.csv
done

echo "Completed"
