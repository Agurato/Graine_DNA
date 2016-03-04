#ifndef DEF_MOUTH_STRAND
#define DEF_MOUTH_STRAND

#include <string>
#include <vector>
#include <cmath>
#include <ctime>

#include "Strand.hpp"
#include "../utils/utils.hpp"

class MouthStrand : public Strand {
public:
	MouthStrand(int limbNb);
	MouthStrand(std::vector<bool> mouthType, int teethNb, std::vector<bool> teethType, std::vector<bool> locations);

	std::vector<bool> getMouthTypeBin();
	std::string getMouthType();

	std::vector<bool> getTeethNbBin();
	int getTeethNb();

	std::vector<bool> getTeethTypeeBin();
	std::string getTeethType();

	std::vector<bool> getLocation();

	std::string getStrandType();
};

#endif
