#ifndef DEF_CREATURE
#define DEF_CREATURE

#include <string>
#include "DNA.hpp"
#include "dna_strands/Strand.hpp"

class Creature {
private:
	int id;
	DNA dna;

public:
	Creature(int id, DNA dna);

	int getID();
	DNA getDNA();
};


#endif
