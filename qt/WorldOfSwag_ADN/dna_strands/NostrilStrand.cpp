#include <string>
#include <vector>
#include <ctime>
#include <cmath>

#include "NostrilStrand.hpp"
#include "Strand.hpp"
#include "LimbStrand.hpp"
#include "../utils/utils.hpp"

using namespace std;

NostrilStrand::NostrilStrand(int limbNb) {
	
	srand(time(0));
	int NostrilNb = rand()%((int) pow(2,Nostril_NB_SIZE));

	/* Nostril number */
	vector<bool> nbVector = decToBinary(NostrilNb, Nostril_NB_SIZE);
	sequence.insert(sequence.end(), nbVector.begin(), nbVector.end());

}

NostrilStrand::NostrilStrand(int nbNostrils, vector<bool> locations) {

  /* Nostril number */
	if(nbNostrils > pow(2, Nostril_NB_SIZE)-1) {
		nbNostrils = pow(2, Nostril_NB_SIZE)-1;
	}
	else if(nbNostrils < 0) {
		nbNostrils = 0;
	}
	vector<bool> binNb = decToBinary(nbNostrils, Nostril_NB_SIZE);
	sequence.insert(sequence.end(), binNb.begin(), binNb.end());
}

vector<bool> NostrilStrand::getNumberBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+Nostril_NB_SIZE);
}

int NostrilStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin(), sequence.begin()+Nostril_NB_SIZE));
}

vector<bool> NostrilStrand::getLocationsBin() {
	return vector<bool>(sequence.begin()+Nostril_NB_SIZE, sequence.end());
}
