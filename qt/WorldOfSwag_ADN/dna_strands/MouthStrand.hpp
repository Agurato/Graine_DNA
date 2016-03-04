#ifndef DEF_MOUTH_STRAND
#define DEF_MOUTH_STRAND

#include <string>
#include <vector>

#include "Strand.hpp"
#include "LimbStrand.hpp"

#define MOUTH_WIDTH_LENGTH 1
#define TEETH_NB_LENGTH 6
#define TEETH_TYPE_LENGTH 2

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
};

#endif
