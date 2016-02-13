#ifndef DEF_LIMB_STRAND
#define DEF_LIMB_STRAND

#include <string>
#include <vector>
#include "Strand.hpp"

class LimbStrand: public Strand {
	private:
	std::vector<int> size;
};

#endif
