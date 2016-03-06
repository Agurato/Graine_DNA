#include <iostream>
#include "parts/XMLData.hpp"
#include "simfunctions/functions.hpp"
#include "DNA.hpp"

using namespace std;
using namespace xercesc;

int main(int argc, char **argv) {
	srand(time(0));

	XMLData* xml = XMLData::getInstance();
	xml->parseXML("parts/codes.xml");

	cout << "------------------" << endl << "DNA N°0" << endl;
	DNA *dna = createRandomDNA();
	vector<Strand*> strands = dna->getDNAStrand();

	LimbStrand* limb = (LimbStrand*) strands[0];
	cout << limb->toString() << endl;

	return 0;
}
