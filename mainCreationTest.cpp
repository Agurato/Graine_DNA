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

	DNA dna = createRandomDNA();
	vector<Strand*> strands = dna.getDNAStrand();

	LimbStrand* limb = (LimbStrand*) strands.at(0);
	EarStrand* ear = (EarStrand*) strands.at(1);
	EyeStrand* eye = (EyeStrand*) strands.at(2);
	MouthStrand* mouth = (MouthStrand*) strands.at(3);
	NostrilStrand* nostril = (NostrilStrand*) strands.at(4);

	cout << "========================================" << endl << "========================================" << endl << "DNA N°0" << endl;
	cout << limb->toString() << "----------------------------------------" << endl;
	cout << ear->toString() << "----------------------------------------" << endl;
	cout <<eye->toString() << "----------------------------------------" << endl;
	cout <<mouth->toString() << "----------------------------------------" << endl;
	cout <<nostril->toString() << endl;

	return 0;
}
