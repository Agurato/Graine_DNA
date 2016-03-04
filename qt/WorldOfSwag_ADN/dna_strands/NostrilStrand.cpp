#include "NostrilStrand.hpp"

using namespace std;

NostrilStrand::NostrilStrand(int limbNb) {

	srand(time(0));
	int nostrilNb = rand()%((int) pow(2,xml->NOSTRIL_NB_LENGTH()));

	/* Nostril number */
	vector<bool> nbVector = decToBinary(nostrilNb, xml->NOSTRIL_NB_LENGTH());
	sequence.insert(sequence.end(), nbVector.begin(), nbVector.end());

}

NostrilStrand::NostrilStrand(int nbNostrils, vector<bool> locations) {

  /* Nostril number */
	if(nbNostrils > pow(2, xml->NOSTRIL_NB_LENGTH())-1) {
		nbNostrils = pow(2, xml->NOSTRIL_NB_LENGTH())-1;
	}
	else if(nbNostrils < 0) {
		nbNostrils = 0;
	}
	vector<bool> binNb = decToBinary(nbNostrils, xml->NOSTRIL_NB_LENGTH());
	sequence.insert(sequence.end(), binNb.begin(), binNb.end());
}

vector<bool> NostrilStrand::getNumberBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+xml->NOSTRIL_NB_LENGTH());
}

int NostrilStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin(), sequence.begin()+xml->NOSTRIL_NB_LENGTH()));
}

vector<bool> NostrilStrand::getLocations() {
	return vector<bool>(sequence.begin()+xml->NOSTRIL_NB_LENGTH(), sequence.end());
}

vector<bool> NostrilStrand::getLocationOf(int index) {
	if(index < 0 || index >= getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+xml->NOSTRIL_NB_LENGTH()+xml->LIMB_NB_LENGTH()*index, sequence.begin()+xml->NOSTRIL_NB_LENGTH()+xml->LIMB_NB_LENGTH()*(index+1));
}
