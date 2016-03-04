#ifndef DEF_DNA
#define DEF_DNA

#include <string>
#include <vector>
#include "dna_strands/Strand.hpp"

class DNA {
	private:
		std::vector<Strand*> sequence;

	public:
		DNA();
		DNA(Strand strand);

		void addStrand(Strand strand);

		std::vector<Strand*> getSequence();

		void setSequence(Strand strand);

};


#endif
