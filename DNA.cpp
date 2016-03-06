#include "DNA.hpp"

using namespace std;

DNA::DNA() {
	dnaStrand.clear();
}

DNA::DNA(vector<Strand*> strands) {
	dnaStrand = strands;
}

void DNA::addStrand(Strand* strand) {
	dnaStrand.push_back(strand);
}

vector<Strand*> DNA::getDNAStrand() {
	return dnaStrand;
}

void DNA::setDNAStrand(vector<Strand*> strands) {
	dnaStrand = strands;
}
