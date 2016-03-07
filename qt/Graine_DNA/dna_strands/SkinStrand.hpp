#ifndef DEF_SKIN_STRAND
#define DEF_SKIN_STRAND

#include "Strand.hpp"
#include "../utils/utils.hpp"

class SkinStrand : public Strand {
public:
	SkinStrand();
	SkinStrand(std::vector<bool> colorBin, std::vector<bool> hairiness);

	std::vector<bool> getColorBin();
	std::string getColor();

	std::vector<bool> getHairBin();
	std::string getHair();

	virtual std::string getStrandType();
	virtual std::string toString();
	virtual std::string toString(std::string name);
};

#endif
