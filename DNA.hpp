#ifndef DEF_DNA
#define DEF_DNA

#include <string>
#include <vector>
#include "dna_strands/Strand.hpp"

class DNA {
	private:
		std::vector<Strand> sequence;

	public:
		DNA();
		DNA(Strand strand);

		void addStrand(Strand strand);

		vector<Strand> getSequence();

		void DNA::setSequence(Strand strand);

};


#endif
