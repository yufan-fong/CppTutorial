#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

using namespace std;
using namespace fyf;

int main() {

	FractalCreator fractalCreator(800, 600);	// bitmap bottom left is origin

	// hardcoded zoom sequence, change the m_Center coordinates
	fractalCreator.addZoom(Zoom(290, 202, 0.1));
	fractalCreator.addZoom(Zoom(314, 314, 0.1));

	fractalCreator.addRange(0.0, RGB(0, 0, 255));
	fractalCreator.addRange(0.05, RGB(255, 99, 71));
	fractalCreator.addRange(0.08, RGB(255, 215, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));

	fractalCreator.run("test.bmp");

	std::cout << "Finished." << std::endl;

	return 0;
}
