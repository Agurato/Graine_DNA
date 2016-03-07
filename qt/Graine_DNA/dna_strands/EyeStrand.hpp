#ifndef DEF_EYE_STRAND
#define DEF_EYE_STRAND

#include "Strand.hpp"
#include "../utils/utils.hpp"

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

	virtual std::string getStrandType();
	virtual std::string toString();
	virtual std::string toString(std::string name);
};

#endif
