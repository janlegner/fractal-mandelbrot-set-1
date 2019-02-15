# fractal-mandelbrot-set-1

This is a simple C program to generate a PPM image with a representation of a Mandelbrot set.

## Build
```
$ make
g++ -O3 -Wall -Wextra -Wno-long-long -pedantic mandelbrot.c -o mandelbrot
```

## Usage
```
$ ./mandelbrot
```

## Clean
```
$ make clean 
rm -f mandelbrot
```

## Example result
![Mandelbrot set - showcase](https://github.com/janlegner/fractal-mandelbrot-set-1/raw/master/showcase/mandelbrot.ppm)
