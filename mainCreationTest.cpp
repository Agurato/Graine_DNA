#include <iostream>
#include "sim/XMLData.hpp"
#include "sim/functions.hpp"
#include "DNA.hpp"

using namespace std;
using namespace xercesc;

int main(int argc, char **argv) {
	srand(time(0));

	XMLData* xml = XMLData::getInstance();
	xml->parseXML("sim/codes.xml");

	DNA dna = createRandomDNA();
	map<string, Strand*> strands = dna.getDNAStrand();

	SkinStrand* skin = (SkinStrand*) strands.find("skin")->second;
	LimbStrand* limb = (LimbStrand*) strands.find("limb")->second;
	EarStrand* ear = (EarStrand*) strands.find("ear")->second;
	EyeStrand* eye = (EyeStrand*) strands.find("eye")->second;
	MouthStrand* mouth = (MouthStrand*) strands.find("mouth")->second;
	NostrilStrand* nostril = (NostrilStrand*) strands.find("nostril")->second;

	cout << "========================================" << endl << "========================================" << endl << "DNA N°0" << endl;
	cout << skin->toString() << "----------------------------------------" << endl;
	cout << limb->toString() << "----------------------------------------" << endl;
	cout << ear->toString() << "----------------------------------------" << endl;
	cout << eye->toString() << "----------------------------------------" << endl;
	cout << mouth->toString() << "----------------------------------------" << endl;
	cout << nostril->toString() << endl;

	return 0;
}
