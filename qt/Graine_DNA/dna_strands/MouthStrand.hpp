#ifndef DEF_MOUTH_STRAND
#define DEF_MOUTH_STRAND

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

	std::vector<bool> getTeethTypeBin();
	std::string getTeethType();

	std::vector<bool> getLocation();

	virtual std::string getStrandType();
	virtual std::string toString();
	virtual std::string toString(std::string name);
};

#endif
