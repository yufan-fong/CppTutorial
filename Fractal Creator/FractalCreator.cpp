#include "FractalCreator.h"
#include <assert.h>

namespace fyf {

	void fyf::FractalCreator::run(std::string name) {
		calculateIteration();
		calculateTotalIterations();
		calculateRangeTotals();
		drawFractal();
		writeBitmap(name);
	}

	fyf::FractalCreator::FractalCreator(int width, int height): m_width(width), m_height(height), 
		m_histogram(new int[fyf::Mandelbrot::MAX_ITERATIONS]{ 0 }),
		m_fractal(new int[m_width * m_height]{ 0 }),
		m_bitmap(m_width, m_height),
		m_zoomlist(m_width, m_height) {
		m_zoomlist.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
	};

	fyf::FractalCreator::~FractalCreator() {
	};

	void fyf::FractalCreator::calculateIteration() {
		for (int y = 0; y < m_height; y++) {
			for (int x = 0; x < m_width; x++) {
				std::pair<double, double> coords = m_zoomlist.doZoom(x, y);

				int iterations = fyf::Mandelbrot::getIterations(coords.first, coords.second);
				m_fractal[y * m_width + x] = iterations;

				if (iterations != fyf::Mandelbrot::MAX_ITERATIONS) m_histogram[iterations]++;
			}
		}
	};

	void fyf::FractalCreator::drawFractal() {
		// coloring loop

		for (int y = 0; y < m_height; y++) {
			for (int x = 0; x < m_width; x++) {


				uint8_t red = 0;
				uint8_t green = 0;
				uint8_t blue = 0;

				int iterations = m_fractal[y * m_width + x];
				int range = getRange(iterations);
				int rangeTotal = m_rangeTotals[range];
				int rangeStart = m_ranges[range];

				RGB& startColor = m_colors[range];
				RGB& endColor = m_colors[range+1];
				RGB colorDiff = endColor - startColor;

				if (iterations != fyf::Mandelbrot::MAX_ITERATIONS) {

					int totalPixels = 0;
					for (int i = rangeStart; i <= iterations; i++) {
						totalPixels += m_histogram[i];
					}
					//green = pow(255, hue);	// higher iterations, more color
					red = startColor.r + colorDiff.r * (double)totalPixels / rangeTotal;
					green = startColor.g + colorDiff.g * (double)totalPixels / rangeTotal;
					blue = startColor.b + colorDiff.b * (double)totalPixels / rangeTotal;
					//green = hue * 255;	// higher iterations, more color
				}

				m_bitmap.setPixel(x, y, red, green, blue);
			}
		}
	};

	void fyf::FractalCreator::writeBitmap(std::string name) {
		m_bitmap.write(name);
	};

	void fyf::FractalCreator::addZoom(const Zoom& zoom) {
		m_zoomlist.add(zoom);
	};

	void fyf::FractalCreator::calculateTotalIterations() {
		// obtain total no. of pixels not in mandelbrot set
		for (int i = 0; i < fyf::Mandelbrot::MAX_ITERATIONS; i++) {
			m_total += m_histogram[i];
		}

		std::cout << "Overall Total: " << m_total << std::endl;
	};


	void fyf::FractalCreator::calculateRangeTotals() {
		int rangeIndex = 0;

		for (int i = 0; i < fyf::Mandelbrot::MAX_ITERATIONS; i++) {
			int pixels = m_histogram[i];

			if (i >= m_ranges[rangeIndex + 1]) {
				rangeIndex++;
			}

			m_rangeTotals[rangeIndex] += pixels;

		}

		int overallTotal = 0;
		for (int value : m_rangeTotals) {
			std::cout << "Range total: " << value << std::endl;
			overallTotal += value;
		}

		std::cout << "Overall Total: " << overallTotal << std::endl;
	};

	void fyf::FractalCreator::addRange(double rangeEnd, const RGB& rgb) {
		m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITERATIONS);
		m_colors.push_back(rgb);
		if (m_bGotFirstRange) {
			m_rangeTotals.push_back(0);
		}
		m_bGotFirstRange = true;

		
	};

	int fyf::FractalCreator::getRange(int iterations) const {
		int range = 0;

		for (int i = 1; i < m_ranges.size(); i++) {
			range = i;
			if (m_ranges[i] > iterations) {
				break;
			}
		}

		range--;
		assert(range > -1);
		assert(range < m_ranges.size());

		return range;
	};

}