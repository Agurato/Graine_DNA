#include "NostrilStrand.hpp"

using namespace std;

NostrilStrand::NostrilStrand(int limbNb) {
	int i;

	int nostrilNb = rand()%((int) pow(2,xml->NOSTRIL_NB_LENGTH()));

	/* Nostril number */
	vector<bool> nbVector = decToBinary(nostrilNb, xml->NOSTRIL_NB_LENGTH());
	sequence.insert(sequence.end(), nbVector.begin(), nbVector.end());

	/* Nostrils positions */
	for(i=0 ; i<nostrilNb ; i++) {
		vector<bool> nostrilLocationBin = decToBinary(rand()%limbNb+1, xml->LIMB_NB_LENGTH());
		sequence.insert(sequence.end(), nostrilLocationBin.begin(), nostrilLocationBin.end());
	}
}

NostrilStrand::NostrilStrand(int nostrilNb, vector<bool> locations) {

	/* Nostril number */
	if(nostrilNb > pow(2, xml->NOSTRIL_NB_LENGTH())-1) {
		nostrilNb = pow(2, xml->NOSTRIL_NB_LENGTH())-1;
	}
	else if(nostrilNb < 0) {
		nostrilNb = 0;
	}
	vector<bool> binNb = decToBinary(nostrilNb, xml->NOSTRIL_NB_LENGTH());
	sequence.insert(sequence.end(), binNb.begin(), binNb.end());

	/* Nostrils positions */
	if(locations.size() > (unsigned) nostrilNb*xml->LIMB_NB_LENGTH()) {
		locations = vector<bool>(locations.begin(), locations.begin()+nostrilNb*xml->LIMB_NB_LENGTH());
	}
	else if(locations.size() < (unsigned) nostrilNb*xml->LIMB_NB_LENGTH()) {
		int i;
		for(i=locations.size() ; i<nostrilNb*xml->LIMB_NB_LENGTH() ; i++) {
			locations.push_back(0);
		}
	}
	sequence.insert(sequence.end(), locations.begin(), locations.begin()+nostrilNb*xml->LIMB_NB_LENGTH());

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

string NostrilStrand::getStrandType() {
	return "NostrilStrand";
}
