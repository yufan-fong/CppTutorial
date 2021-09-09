#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

namespace fyf {

	fyf::Bitmap::Bitmap(int width, int height) :
		m_width(width), m_height(height), m_pPixels(
			new uint8_t[width * height * 3]{ }) {
	}

	bool fyf::Bitmap::write(std::string filename) {

		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)
			+ m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream file;
		file.open(filename, std::ios::out | std::ios::binary);

		if (!file) {
			return false;
		}

		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)m_pPixels.get(), m_width * m_height * 3);

		file.close();

		if (!file) return false;

		return true;
	}

	void fyf::Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		uint8_t* pPixel = m_pPixels.get();	// pointer to a specific pixel
		pPixel += y * 3 * m_width + x * 3;
		pPixel[0] = blue;	// little endian format for bit map
		pPixel[1] = green;
		pPixel[2] = red;
	}

	fyf::Bitmap::~Bitmap() {
		// TODO Auto-generated destructor stub
	}

}