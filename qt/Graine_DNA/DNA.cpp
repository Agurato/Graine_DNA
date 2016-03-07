#include "DNA.hpp"

using namespace std;

DNA::DNA() {
	dnaStrand.clear();
}

DNA::DNA(map<string, Strand*> strands) {
	dnaStrand = strands;
}

void DNA::addStrand(string key, Strand* strand) {
	dnaStrand.insert(pair<string, Strand*>(key, strand));
}

map<string, Strand*> DNA::getDNAStrand() {
	return dnaStrand;
}

void DNA::setDNAStrand(map<string, Strand*> strands) {
	dnaStrand = strands;
}
