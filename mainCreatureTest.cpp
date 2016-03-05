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

	vector<bool> location = decToBinary(3, xml->LIMB_NB_LENGTH());
	vector<bool> location2 = decToBinary(1, xml->LIMB_NB_LENGTH());
	location.insert(location.end(), location2.begin(), location2.end());


/* Ear Strand */
	cout << "First Ear" << endl;
	EarStrand first_earStrand(2, location);

	cout << "First Ear Sequence : " << binaryToString(first_earStrand.getSequence()) << endl;
	cout << "First Ear getNumber() : " << first_earStrand.getNumber() << endl;
	cout << "First Ear getNumberBin() : " << binaryToString(first_earStrand.getNumberBin()) << endl;
	cout << "First Ear getLocations() : " <<  binaryToString(first_earStrand.getLocations()) << endl;
	cout << "First Ear getLocationOf(0) :" << binaryToString(first_earStrand.getLocationOf(0)) << endl;
	cout << "First Ear getLocationOf(1) :" << binaryToString(first_earStrand.getLocationOf(1)) << endl;

	cout << "___________________________________" << endl;

/* Eye Strand */

	vector<bool> eyeColour = hexToBinary("FFFFFF");

	location = decToBinary(2, xml->LIMB_NB_LENGTH());
	location2 = decToBinary(14, xml->LIMB_NB_LENGTH());
	vector<bool> location3 = decToBinary(1, xml->LIMB_NB_LENGTH());
	location.insert(location.end(), location2.begin(), location2.end());
	location.insert(location.end(), location3.begin(), location3.end());

	cout << "First Eye" << endl;
	EyeStrand first_eyeStrand(eyeColour, 3, location);

	cout << "First Eye Sequence : " << binaryToString(first_eyeStrand.getSequence()) << endl;
	cout << "First Eye getNumber() : " << first_eyeStrand.getNumber() << endl;
	cout << "First Eye getNumberBin() : " << binaryToString(first_eyeStrand.getNumberBin()) << endl;
	cout << "First Eye getLocations() : " <<  binaryToString(first_eyeStrand.getLocations()) << endl;
	cout << "First Eye getLocationOf(0) :" << binaryToString(first_eyeStrand.getLocationOf(0)) << endl;
	cout << "First Eye getLocationOf(1) :" << binaryToString(first_eyeStrand.getLocationOf(1)) << endl;
	cout << "First Eye getLocationOf(2) :" << binaryToString(first_eyeStrand.getLocationOf(2)) << endl;
	cout << "First Eye getColor() :" << first_eyeStrand.getColor() << endl;
	cout << "First Eye getColorBin() :" << binaryToString(first_eyeStrand.getColorBin()) << endl;

	cout << "___________________________________" << endl;

/* Creature */
	DNA dna1;
	dna1.addStrand(&first_earStrand);
	dna1.addStrand(&first_eyeStrand);

	Creature creature1(0, dna1);
	DNA dna12 = creature1.getDNA();
	vector<Strand*> vectorStrand1 = dna12.getDNAStrand();
	EarStrand* first_creature_earStrand = (EarStrand*) vectorStrand1[0];
	EyeStrand* first_creature_eyeStrand = (EyeStrand*) vectorStrand1[1];

	cout << "First Creature ID : " << creature1.getID() << endl;
	cout << "First Creature First Sequence Type : " << vectorStrand1[0]->getStrandType() << endl;
	cout << "First Creature Second Sequence Type : " << vectorStrand1[1]->getStrandType() << endl;
	cout << "-------------------------" << endl;
	cout << "First Creature Ear Sequence : " << binaryToString(first_creature_earStrand->getSequence()) << endl;
	cout << "First Creature Ear getNumber() : " << first_creature_earStrand->getNumber() << endl;
	cout << "First Creature Ear getNumberBin() : " << binaryToString(first_creature_earStrand->getNumberBin()) << endl;
	cout << "First Creature Ear getLocations() : " <<  binaryToString(first_creature_earStrand->getLocations()) << endl;
	cout << "First Creature Ear getLocationOf(0) :" << binaryToString(first_creature_earStrand->getLocationOf(0)) << endl;
	cout << "First Creature Ear getLocationOf(1) :" << binaryToString(first_creature_earStrand->getLocationOf(1)) << endl;
	cout << "----------------------------" << endl;
	cout << "First Creature Eye Sequence : " << binaryToString(first_creature_eyeStrand->getSequence()) << endl;
	cout << "First Creature Eye getNumber() : " << first_creature_eyeStrand->getNumber() << endl;
	cout << "First Creature Eye getNumberBin() : " << binaryToString(first_creature_eyeStrand->getNumberBin()) << endl;
	cout << "First Creature Eye getLocations() : " <<  binaryToString(first_creature_eyeStrand->getLocations()) << endl;
	cout << "First Creature Eye getLocationOf(0) :" << binaryToString(first_creature_eyeStrand->getLocationOf(0)) << endl;
	cout << "First Creature Eye getLocationOf(1) :" << binaryToString(first_creature_eyeStrand->getLocationOf(1)) << endl;
	cout << "First Creature Eye getLocationOf(2) :" << binaryToString(first_creature_eyeStrand->getLocationOf(2)) << endl;
	cout << "First Creature Eye getColor() :" << first_creature_eyeStrand->getColor() << endl;
	cout << "First Creature Eye getColorBin() :" << binaryToString(first_creature_eyeStrand->getColorBin()) << endl;
	cout << "----------------------------" << endl;


	return 0;
}
