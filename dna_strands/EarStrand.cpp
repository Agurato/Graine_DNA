#include <cmath>
#include <ctime>

#include "EarStrand.hpp"
#include "LimbStrand.hpp"
#include "../utils/utils.hpp"

using namespace std;

EarStrand::EarStrand(int limbNb) {
	srand(time(0));
	int i;

	int earNb = rand() % ((int) pow(2, EAR_NB_LENGTH));

	/* Ear number */
	vector<bool> earNbBin = decToBinary(earNb, EAR_NB_LENGTH);
	sequence.insert(sequence.end(), earNbBin.begin(), earNbBin.end());

	/* Ears positions */
	for(i=0 ; i<earNb ; i++) {
		vector<bool> earLocationBin = decToBinary(rand()%limbNb+1, LIMB_NB_LENGTH);
		sequence.insert(sequence.end(), earLocationBin.begin(), earLocationBin.end());
	}

}

EarStrand::EarStrand(int earNb, vector<bool> locations) {

	/* ear number */
	if(earNb > pow(2, EAR_NB_LENGTH)-1) {
		earNb = pow(2, EAR_NB_LENGTH)-1;
	}
	else if(earNb < 0) {
		earNb = 0;
	}
	vector<bool> earNbBin = decToBinary(earNb, EAR_NB_LENGTH);
	sequence.insert(sequence.end(), earNbBin.begin(), earNbBin.end());

	/* ears positions */
	if(locations.size() > earNb*LIMB_NB_LENGTH) {
		locations = vector<bool>(locations.begin(), locations.begin()+earNb*LIMB_NB_LENGTH);
	}
	else if(locations.size() < earNb*LIMB_NB_LENGTH) {
		int i;
		for(i=locations.size() ; i<earNb*LIMB_NB_LENGTH ; i++) {
			locations.push_back(0);
		}
	}
	sequence.insert(sequence.end(), locations.begin(), locations.begin()+earNb*LIMB_NB_LENGTH);

}

vector<bool> EarStrand::getNumberBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+EAR_NB_LENGTH);
}

int EarStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin(), sequence.begin()+EAR_NB_LENGTH));
}

vector<bool> EarStrand::getLocations() {
	return vector<bool>(sequence.begin()+EAR_NB_LENGTH, sequence.end());
}

vector<bool> EarStrand::getLocationOf(int index) {
	if(index < 0 || index >= getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+EAR_NB_LENGTH+LIMB_NB_LENGTH*index, sequence.begin()+EAR_NB_LENGTH+LIMB_NB_LENGTH*(index+1));
}
