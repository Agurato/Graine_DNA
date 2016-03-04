#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "utils/utils.hpp"
#include "parts/XMLData.hpp"

#include "dna_strands/Strand.hpp"
#include "dna_strands/EarStrand.hpp"
#include "dna_strands/EyeStrand.hpp"
#include "dna_strands/LimbStrand.hpp"
#include "dna_strands/MouthStrand.hpp"
#include "dna_strands/NostrilStrand.hpp"

#include "Creature.hpp"
#include "DNA.hpp"

using namespace std;
using namespace xercesc;

int main() {
	XMLData* xml = XMLData::getInstance();
	xml->parseXML("parts/codes.xml");

	srand(time(0));

	vector<bool> location = decToBinary(4, 4);
	vector<bool> location2 = decToBinary(7, 4);
	location.insert(location.end(), location2.begin(), location2.end());

	cout << "First Ear" << endl;
	EarStrand first_earStrand(2, location);

	cout << "First Ear Sequence : " << binaryToString(first_earStrand.getSequence()) << endl;
	cout << "First Ear getNumber() : " << first_earStrand.getNumber() << endl;
	cout << "First Ear getNumberBin() : " << binaryToString(first_earStrand.getNumberBin()) << endl;
	cout << "First Ear getLocations() : " <<  binaryToString(first_earStrand.getLocations()) << endl;
	cout << "First Ear getLocationOf(0) :" << binaryToString(first_earStrand.getLocationOf(0)) << endl;
	cout << "First Ear getLocationOf(1) :" << binaryToString(first_earStrand.getLocationOf(1)) << endl;

	cout << "___________________________________" << endl;


	DNA dna1(first_earStrand);

	Creature creature1(0, dna1);
	DNA dna12 = creature1.getDNA();
	vector<Strand*> vectorStrand1 = dna12.getSequence();
	EarStrand* first_creature_earStrand = (EarStrand*) vectorStrand1[0];

	cout << "First Creature ID : " << creature1.getID() << endl;
	cout << "First Creature Ear Sequence : " << binaryToString(first_creature_earStrand->getSequence()) << endl;
	cout << "First Creature Ear getNumber() : " << first_creature_earStrand->getNumber() << endl;
	cout << "First Creature Ear getNumberBin() : " << binaryToString(first_creature_earStrand->getNumberBin()) << endl;
	cout << "First Creature Ear getLocations() : " <<  binaryToString(first_creature_earStrand->getLocations()) << endl;
	cout << "First Creature Ear getLocationOf(0) :" << binaryToString(first_creature_earStrand->getLocationOf(0)) << endl;
	cout << "First Creature Ear getLocationOf(1) :" << binaryToString(first_creature_earStrand->getLocationOf(1)) << endl;


	return 0;
}
