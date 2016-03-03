#ifndef DEF_LIMB_STRAND
#define DEF_LIMB_STRAND

#include <string>
#include <vector>
#include "Strand.hpp"

#define LIMB_NB_LENGTH 4
#define LIMB_SIZE_LENGTH 8
#define LIMB_TYPES_LENGTH 4

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
};

#endif
