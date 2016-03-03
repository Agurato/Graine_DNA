#ifndef DEF_NOSTRIL_STRAND
#define DEF_NOSTRIL_STRAND

#include <string>
#include <vector>

#include "Strand.hpp"
#include "LimbStrand.hpp"

#define NOSTRIL_NB_SIZE 3

class NostrilStrand : public Strand {
public:
	NostrilStrand(int limbNb);
	NostrilStrand(int nbNostrils, std::vector<bool> locations);

	std::vector<bool> getNumberBin();
	int getNumber();

	std::vector<bool> getLocationsBin();
};


#endif
