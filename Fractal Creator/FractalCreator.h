#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

namespace fyf {

	class FractalCreator {
	private:
		int m_width;
		int m_height;
		int m_total{ 0 };

		std::unique_ptr<int[]> m_histogram;
		std::unique_ptr<int[]> m_fractal;

		Bitmap m_bitmap;
		ZoomList m_zoomlist;

		std::vector<int> m_ranges;
		std::vector<RGB> m_colors;
		std::vector<int> m_rangeTotals;

		bool m_bGotFirstRange{ false };

	private:
		void calculateIteration();
		void calculateTotalIterations();
		void calculateRangeTotals();
		void drawFractal();
		void writeBitmap(std::string name);
		int getRange(int iterations) const;

	public:
		FractalCreator(int width, int height);
		virtual ~FractalCreator();
		void addZoom(const Zoom& zoom);
		void addRange(double rangeEnd, const RGB& rgb);
		void run(std::string name);
	};

}