GXX_FLAGS=-Wall -Wextra -Wno-long-long -pedantic

all:
	g++ -O3 $(GXX_FLAGS) mandelbrot.c -o mandelbrot
clean:
	rm -f mandelbrot

