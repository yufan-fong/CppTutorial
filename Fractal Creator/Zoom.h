#pragma once
namespace fyf{

	struct Zoom {
		// data structure to contain information about zooms
		int x{0};
		int y{0};
		double scale{ 0.0 };

		Zoom(int x, int y, double scale) : x(x), y(y), scale(scale) {};
	};

}