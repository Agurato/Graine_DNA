#include "DNA.hpp"

using namespace std;

DNA::DNA() {
	sequence.clear();
}

DNA::DNA(Strand strand) {
	sequence.insert(sequence.end(), &strand);
}

void DNA::addStrand(Strand strand) {
	sequence.insert(sequence.end(), &strand);
}

vector<Strand*> DNA::getSequence() {
	return sequence;
}

void DNA::setSequence(Strand strand) {
	sequence.clear();
	sequence.insert(sequence.end(), &strand);
}
