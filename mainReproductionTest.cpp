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

	cout << first_earStrand.toString("First Ear") << endl;
	cout << "___________________________________" << endl;

/* Eye Strand */

	cout << "First Eye" << endl;
	EyeStrand first_eyeStrand(4);

	cout << first_eyeStrand.toString("First Eye") << endl;
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

	cout << second_earStrand.toString("Second Ear") << endl;
	cout << "___________________________________" << endl;

	/* Eye Strand */

	cout << "Second Eye" << endl;
	EyeStrand second_eyeStrand(4);

	cout << second_eyeStrand.toString("Second Eye") << endl;
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

	cout << newDNA_earStrand->toString("newDNA Ear") << endl;
	cout << "___________________________________" << endl;

	cout << newDNA_eyeStrand->toString("newDNA Eye") << endl;
	cout << "___________________________________" << endl;

	return 0;
}
