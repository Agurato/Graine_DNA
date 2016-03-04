#include "DNA.hpp"

using namespace std;

DNA::DNA() {

}

DNA::DNA(Strand strand) {
	sequence.insert(sequence.end(), strand);
}

void DNA::addStrand(Strand strand) {
	sequence.insert(sequence.end(), strand)
}

vector<Strand> DNA::getSequence() {
	return sequence;
}

void DNA::setSequence(Strand strand) {
	sequence = NULL;
	sequence.insert(sequence.end(), strand);
}
