#include <stdio.h>
#include <complex.h>

int depth = 100;

inline int mandelbrotSet (double complex c) {
	double complex z = c;
	int i = 0;
	while (i++ < depth) {
		if (cabs(z) > 2.0)
			break;
		z = z * z + c;
	}
	return i;
}

int main () {
	// double x1 = -2.0, x2 = 1.0;
	// double y1 = -1.5, y2 = 1.5;

	// double x1 = -1.5, x2 = 1.5;
	// double y1 = -1.5, y2 = 1.5;

	double x1 = -0.7, x2 = 0.1;
	double y1 = -1.05, y2 = -0.6;

	double dx = x2 - x1;
	double dy = y2 - y1;

	double width = 1600, height = width * dy / dx;

	FILE * f = fopen("mandelbrot.ppm", "w");

	if (f == NULL) {
		fprintf(stderr, "Failed to create a file.");
		return 1;
	}

	fprintf(f, "P6\n%d\n%d\n%d\n", (int) width, (int) height, depth);

	double complex c;
	double x, y;
	for (y = 0; y < height; y++) {
		for (x = 0; x < width; x++) {
			c = (x1 + (x / width) * dx) + I * (y1 + (y / height) * dy);
			int steps = mandelbrotSet(c);
			fprintf(f, "%c%c%c", steps, steps, steps);
		}
	}

	fclose(f);
	return 0;
}
