#include <memory>
#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace fyf;

int main() {

	int const WIDTH = 800;
	int const HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT);
	// bitmap bottom left is origin

	std::unique_ptr<int[]> histogram(new int[fyf::Mandelbrot::MAX_ITERATIONS]{0});
	std::unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{ 0 });

	// get iterations loop
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			double xFractal = (x - WIDTH/2.0 - 200) / (HEIGHT/2.0);	// scale 0:800 to -1:1
			double yFractal = (y - HEIGHT/2.0) / (HEIGHT/2.0);

			int iterations = fyf::Mandelbrot::getIterations(xFractal, yFractal);
			fractal[y * WIDTH + x] = iterations;

			if(iterations != fyf::Mandelbrot::MAX_ITERATIONS) histogram[iterations]++;
		}
	}

	// obtain total pixels not in mandelbrot set
	int total = 0;
	for (int i = 0; i < fyf::Mandelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}

	// coloring loop
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			int iterations = fractal[y * WIDTH + x];
		
			double hue = 0.0;
			for (int i = 0; i <= iterations; i++) {
				hue += ((double)histogram[i]) / total;
			}

			uint8_t red = 0;
			uint8_t green = hue*255;
			uint8_t blue = 0;

			bitmap.setPixel(x, y, red, green, blue);
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;

	return 0;
}
