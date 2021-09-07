#include "Mandelbrot.h"
#include <complex>

namespace fyf{

	fyf::Mandelbrot::Mandelbrot() {};

	fyf::Mandelbrot::~Mandelbrot() {};

	int fyf::Mandelbrot::getIterations(double x, double y) {
		std::complex<double> z = 0;
		std::complex<double> c(x,y);
		int iterations = 0;

		// Fractal Algorithm
		while (iterations < MAX_ITERATIONS) {
			z = z * z + c;
			if (abs(z) > 2) { // not part of mandelbrot set
				break;
			}
			iterations++;
		}

		return iterations;
	};

}