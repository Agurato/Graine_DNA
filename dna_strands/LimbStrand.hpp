#ifndef DEF_LIMB_STRAND
#define DEF_LIMB_STRAND

#include <string>
#include <vector>
#include <cmath>
#include <ctime>

#include "Strand.hpp"
#include "../utils/utils.hpp"

enum limbTypeName {HAND, FEET, HOOF, HEAD};

class LimbStrand: public Strand {
public:
	LimbStrand();
	LimbStrand(int nb, std::vector<bool> sizes, std::vector<bool> types);

	std::vector<bool> getNumberBin();
	int getNumber();

	std::vector<bool> getSizes();
	std::vector<bool> getSizeOf(int index);

	std::vector<bool> getTypes();
	std::vector<bool> getTypeOf(int index);

	std::string getStrandType();
};

#endif
