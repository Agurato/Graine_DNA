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

	/* Ears Test */

	cout << "First Ear";
	EarStrand first_earStrand(4);

	cout << "First Ear getNumber() : " << first_earStrand.getNumber();
	cout << "First Ear getNumberBin() : " << first_earStrand.getNumberBin();
	cout << "First Ear getLocations() : " <<  first_earStrand.getLocations();
	cout << "First Ear getLocation(0) : " << first_earStrand.getLocation(0);
	cout << "First Ear getLocation(1) : " << first_earStrand.getLocation(1);

	cout << "Second Ear";
//	EarStrand second_earStrand = new EarStrand(2, location);


	return 0;
}
