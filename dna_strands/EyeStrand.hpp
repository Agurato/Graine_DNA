#ifndef DEF_EYE_STRAND
#define DEF_EYE_STRAND

#include <string>
#include <vector>

#include "Strand.hpp"
#include "LimbStrand.hpp"

class EyeStrand : public Strand {
public:
	EyeStrand();
	EyeStrand(std::string color, int nbEyes, std::vector<bool> locations);
	std::vector<bool> getColorBin();
	std::string getColor();

	std::vector<bool> getNumberBin();
	int getNumber();

	std::vector<bool> getLocationsBin();

};

#endif
