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
	vector<Strand*> strands = dna.getDNAStrand();

	SkinStrand* skin = (SkinStrand*) strands.at(0);
	LimbStrand* limb = (LimbStrand*) strands.at(1);
	EarStrand* ear = (EarStrand*) strands.at(2);
	EyeStrand* eye = (EyeStrand*) strands.at(3);
	MouthStrand* mouth = (MouthStrand*) strands.at(4);
	NostrilStrand* nostril = (NostrilStrand*) strands.at(5);

	cout << "========================================" << endl << "========================================" << endl << "DNA N°0" << endl;
	cout << skin->toString() << "----------------------------------------" << endl;
	cout << limb->toString() << "----------------------------------------" << endl;
	cout << ear->toString() << "----------------------------------------" << endl;
	cout << eye->toString() << "----------------------------------------" << endl;
	cout << mouth->toString() << "----------------------------------------" << endl;
	cout << nostril->toString() << endl;

	if(skin->getHair() == "fur") {
		cout << endl << endl << "FUR !!!" << endl;
	}

	return 0;
}
