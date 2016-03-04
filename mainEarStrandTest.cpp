#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "utils/utils.hpp"

#include "dna_strands/Strand.hpp"
#include "dna_strands/EarStrand.hpp"
#include "dna_strands/EyeStrand.hpp"
#include "dna_strands/LimbStrand.hpp"
#include "dna_strands/MouthStrand.hpp"
#include "dna_strands/NostrilStrand.hpp"

using namespace std;

int main() {
	srand(time(0));

	vector<bool> location = decToBinary(4, 4);
	vector<bool> location2 = decToBinary(7, 4);
	location.insert(location.end(), location2.begin(), location2.end());
	int i;

	/* Ears Test */

	cout << "First Ear : RANDOM MODE" << endl;
	EarStrand first_earStrand(4);

	int first_earStrandNb = first_earStrand.getNumber();

	cout << "First Ear Sequence : " << binaryToString(first_earStrand.getSequence()) << endl;
	cout << "First Ear getNumber() : " << first_earStrandNb << endl;
	cout << "First Ear getNumberBin() : " << binaryToString(first_earStrand.getNumberBin()) << endl;
	cout << "First Ear getLocations() : " <<  binaryToString(first_earStrand.getLocations()) << endl;
	for(i = 0; i < first_earStrandNb; i++) {
		cout << "First Ear getLocationOf(" << i << ") :" << binaryToString(first_earStrand.getLocationOf(i)) << endl;
	}


	cout << "Second Ear : SET MODE" << endl;
	EarStrand second_earStrand(2, location);

	cout << "Second Ear Sequence : " << binaryToString(second_earStrand.getSequence()) << endl;
	cout << "Second Ear getNumber() : " << second_earStrand.getNumber() << endl;
	cout << "Second Ear getNumberBin() : " << binaryToString(second_earStrand.getNumberBin()) << endl;
	cout << "Second Ear getLocations() : " <<  binaryToString(second_earStrand.getLocations()) << endl;
	cout << "Second Ear getLocationOf(0) :" << binaryToString(second_earStrand.getLocationOf(0)) << endl;
	cout << "Second Ear getLocationOf(1) :" << binaryToString(second_earStrand.getLocationOf(1)) << endl;


	return 0;
}
