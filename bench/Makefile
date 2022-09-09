CC=gcc
# CFLAGS=-W -Wall -O3 -lm -save-temps
CFLAGS=-W -Wall -O3 -lm

.PHONY: main clean
main: utils.o
	sh bench.sh

test: test-base.out test-gen.out
	./test-base.out
	./test-gen.out

test-base.out: benchmarks_base.o test.o
	$(CC) -o $@ $(CFLAGS) $^

test-gen.out: benchmarks_gen.o test.o
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm -f *.bc *.i *.s *.out *.o \
	   *.csv

.c.o:
	$(CC) -c $(CFLAGS) $<
