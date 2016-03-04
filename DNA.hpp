#ifndef DEF_DNA
#define DEF_DNA

#include <string>
#include <vector>
#include "dna_strands/Strand.hpp"

class DNA {
private:
	std::vector<Strand*> dnaStrand;

public:
	DNA();
	DNA(std::vector<Strand*> strands);

	void addStrand(Strand strand);

	std::vector<Strand*> getDNAStrand();

	void setDNAStrand(std::vector<Strand*> strands);

};


#endif
