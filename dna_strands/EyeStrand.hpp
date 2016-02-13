#ifndef DEF_EYE_STRAND
#define DEF_EYE_STRAND

#include <string>
#include <vector>

#include "Strand.hpp"
#include "LimbStrand.hpp"

class EyeStrand: public Strand {
private:
	std::vector<bool> completeStrand;
public:
	EyeStrand();
	std::string getEyeColor();
	int getEyeNumber();
};

#endif
