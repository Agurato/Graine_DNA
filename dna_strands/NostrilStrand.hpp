#ifndef DEF_NOSTRIL_STRAND
#define DEF_NOSTRIL_STRAND

#include <string>
#include <vector>
#include <cmath>
#include <ctime>

#include "Strand.hpp"
#include "../utils/utils.hpp"

class NostrilStrand : public Strand {
public:
	NostrilStrand(int limbNb);
	NostrilStrand(int nbNostrils, std::vector<bool> locations);

	std::vector<bool> getNumberBin();
	int getNumber();

	std::vector<bool> getLocations();
	std::vector<bool> getLocationOf(int index);
};

#endif
