#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "utils/utils.hpp"
#include "simfunctions/functions.hpp"
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

	DNA dna1;
	DNA dna2;
	DNA newDNA;

/* FIRST DNA STRAND */
/* Ear Strand */
	cout << "First Ear" << endl;
	EarStrand first_earStrand(4);

	first_earStrandNb = first_earStrand.getNumber();

	cout << "First Ear Sequence : " << binaryToString(first_earStrand.getSequence()) << endl;
	cout << "First Ear getNumber() : " << first_earStrandNb << endl;
	cout << "First Ear getNumberBin() : " << binaryToString(first_earStrand.getNumberBin()) << endl;
	cout << "First Ear getLocations() : " <<  binaryToString(first_earStrand.getLocations()) << endl;
	for(i = 0; i < first_earStrandNb; i++) {
		cout << "First Ear getLocationOf(" << i << ") :" << binaryToString(first_earStrand.getLocationOf(i)) << endl;
	}

	cout << "___________________________________" << endl;

/* Eye Strand */

	cout << "First Eye" << endl;
	EyeStrand first_eyeStrand(4);

	first_eyeStrandNb = first_eyeStrand.getNumber();

	cout << "First Eye Sequence : " << binaryToString(first_eyeStrand.getSequence()) << endl;
	cout << "First Eye getNumber() : " << first_eyeStrandNb << endl;
	cout << "First Eye getNumberBin() : " << binaryToString(first_eyeStrand.getNumberBin()) << endl;
	cout << "First Eye getLocations() : " <<  binaryToString(first_eyeStrand.getLocations()) << endl;
	for(i = 0; i < first_eyeStrandNb; i++) {
		cout << "First Eye getLocationOf(" << i << ") :" << binaryToString(first_eyeStrand.getLocationOf(i)) << endl;
	}
	cout << "First Eye getColor() :" << first_eyeStrand.getColor() << endl;
	cout << "First Eye getColorBin() :" << binaryToString(first_eyeStrand.getColorBin()) << endl;

	cout << "___________________________________" << endl;

/* DNA */
	dna1.addStrand(&first_earStrand);
	dna1.addStrand(&first_eyeStrand);


	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;

	/* SECOND DNA STRAND */

	cout << "Second Ear" << endl;
	EarStrand second_earStrand(4);

	second_earStrandNb = second_earStrand.getNumber();

	cout << "Second Ear Sequence : " << binaryToString(second_earStrand.getSequence()) << endl;
	cout << "Second Ear getNumber() : " << second_earStrandNb << endl;
	cout << "Second Ear getNumberBin() : " << binaryToString(second_earStrand.getNumberBin()) << endl;
	cout << "Second Ear getLocations() : " <<  binaryToString(second_earStrand.getLocations()) << endl;
	for(i = 0; i < second_earStrandNb; i++) {
		cout << "Second Ear getLocationOf(" << i << ") :" << binaryToString(second_earStrand.getLocationOf(i)) << endl;
	}

	cout << "___________________________________" << endl;

	/* Eye Strand */

	cout << "Second Eye" << endl;
	EyeStrand second_eyeStrand(4);

	second_eyeStrandNb = second_eyeStrand.getNumber();

	cout << "Second Eye Sequence : " << binaryToString(second_eyeStrand.getSequence()) << endl;
	cout << "Second Eye getNumber() : " << second_eyeStrandNb << endl;
	cout << "Second Eye getNumberBin() : " << binaryToString(second_eyeStrand.getNumberBin()) << endl;
	cout << "Second Eye getLocations() : " <<  binaryToString(second_eyeStrand.getLocations()) << endl;
	for(i = 0; i < second_eyeStrandNb; i++) {
		cout << "Second Eye getLocationOf(" << i << ") :" << binaryToString(second_eyeStrand.getLocationOf(i)) << endl;
	}
	cout << "Second Eye getColor() :" << second_eyeStrand.getColor() << endl;
	cout << "Second Eye getColorBin() :" << binaryToString(second_eyeStrand.getColorBin()) << endl;

	cout << "___________________________________" << endl;

	/* DNA */
	dna2.addStrand(&second_earStrand);
	dna2.addStrand(&second_eyeStrand);

	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;

/* REPRODUCTION */

	newDNA = mating(dna1, dna2);

	vector<Strand*> vectorStrand = newDNA.getDNAStrand();
	EarStrand* newDNA_earStrand = (EarStrand*) vectorStrand[0];
	EyeStrand* newDNA_eyeStrand = (EyeStrand*) vectorStrand[1];

	newDNA_earStrandNb = newDNA_earStrand->getNumber();

	cout << "newDNA : " << endl;
	cout << "___________________________________" << endl;
	cout << "newDNA EAR :" << endl;
	cout << "newDNA Ear Sequence : " << binaryToString(newDNA_earStrand->getSequence()) << endl;
	cout << "newDNA Ear getNumber() : " << newDNA_earStrandNb << endl;
	cout << "newDNA Ear getNumberBin() : " << binaryToString(newDNA_earStrand->getNumberBin()) << endl;
	cout << "newDNA Ear getLocations() : " <<  binaryToString(newDNA_earStrand->getLocations()) << endl;
	for(i = 0; i < newDNA_earStrandNb; i++) {
		cout << "newDNA Ear getLocationOf(" << i << ") :" << binaryToString(newDNA_earStrand->getLocationOf(i)) << endl;
	}

	cout << "___________________________________" << endl;

	newDNA_eyeStrandNb = newDNA_eyeStrand->getNumber();

	cout << "newDNA EYE" << endl;
	cout << "newDNA Eye Sequence : " << binaryToString(newDNA_eyeStrand->getSequence()) << endl;
	cout << "newDNA Eye getNumber() : " << newDNA_eyeStrandNb << endl;
	cout << "newDNA Eye getNumberBin() : " << binaryToString(newDNA_eyeStrand->getNumberBin()) << endl;
	cout << "newDNA Eye getLocations() : " <<  binaryToString(newDNA_eyeStrand->getLocations()) << endl;
	for(i = 0; i < first_eyeStrandNb; i++) {
		cout << "newDNA Eye getLocationOf(" << i << ") :" << binaryToString(newDNA_eyeStrand->getLocationOf(i)) << endl;
	}
	cout << "newDNA Eye getColor() :" << newDNA_eyeStrand->getColor() << endl;
	cout << "newDNA Eye getColorBin() :" << binaryToString(newDNA_eyeStrand->getColorBin()) << endl;

	cout << "___________________________________" << endl;

	return 0;
}
