#ifndef DEF_EAR_STRAND
#define DEF_EAR_STRAND

#include <string>
#include <vector>
#include <cmath>
#include <ctime>

#include "Strand.hpp"
#include "../utils/utils.hpp"

class EarStrand : public Strand {
public:
	EarStrand(int limbNb);
	EarStrand(int nbEars, std::vector<bool> locations);

	std::vector<bool> getNumberBin();
	int getNumber();

	std::vector<bool> getLocations();
	std::vector<bool> getLocationOf(int index);

	std::string getStrandType();
	std::string toString();
	std::string toString(std::string name);
};

#endif
