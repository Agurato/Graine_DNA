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

	vector<bool> location = decToBinary(2, 4);
	vector<bool> location2 = decToBinary(3, 4);
	location.insert(location.end(), location2.begin(), location2.end());
	int i;

	/* Ears Test */

	cout << "First Ear" << endl;
	EarStrand first_earStrand(4);

	int first_earStrandNb = first_earStrand.getNumber();

	cout << "First Ear Sequence : " << binaryToString(first_earStrand.getSequence()) << endl;
	cout << "First Ear getNumber() : " << first_earStrandNb << endl;
	cout << "First Ear getNumberBin() : " << binaryToString(first_earStrand.getNumberBin()) << endl;
	cout << "First Ear getLocations() : " <<  binaryToString(first_earStrand.getLocations()) << endl;
	for(i = 0; i < first_earStrandNb; i++) {
		cout << "First Ear getLocationOf(" << i << ") :" << binaryToString(first_earStrand.getLocationOf(i)) << endl;
	}

	cout << "Second Ear" << endl;
//	EarStrand second_earStrand(2, location);


	return 0;
}
