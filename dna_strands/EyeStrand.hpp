#ifndef DEF_EYE_STRAND
#define DEF_EYE_STRAND

#include <string>
#include <vector>

#include "Strand.hpp"
#include "LimbStrand.hpp"

#define EYE_COLOR_LENGTH 24
#define EYE_NB_LENGTH 3

class EyeStrand : public Strand {
public:
	EyeStrand(int limbNb);
	EyeStrand(std::vector<bool> colorBin, int eyeNb, std::vector<bool> locations);

	std::vector<bool> getColorBin();
	std::string getColor();

	std::vector<bool> getNumberBin();
	int getNumber();

	std::vector<bool> getLocations();
	std::vector<bool> getLocationOf(int index);
};

#endif
