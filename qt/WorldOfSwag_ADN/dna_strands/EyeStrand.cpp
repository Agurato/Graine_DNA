#include "EyeStrand.hpp"

using namespace std;

EyeStrand::EyeStrand(int limbNb) {
	srand(time(0));
	int i;

	int eyeNb = rand() % ((int) pow(2, xml->EYE_NB_LENGTH()));

	/* Eye color */
	for(i=0 ; i<xml->EYE_COLOR_LENGTH() ; i++) {
		sequence.push_back(rand()%2);
	}

	/* Eye number */
	vector<bool> eyeNbBin = decToBinary(eyeNb, xml->EYE_NB_LENGTH());
	sequence.insert(sequence.end(), eyeNbBin.begin(), eyeNbBin.end());

	/* Eyes positions */
	for(i=0 ; i<eyeNb ; i++) {
		vector<bool> eyeLocationBin = decToBinary(rand()%limbNb+1, xml->LIMB_NB_LENGTH());
		sequence.insert(sequence.end(), eyeLocationBin.begin(), eyeLocationBin.end());
	}

}

EyeStrand::EyeStrand(vector<bool> colorBin, int eyeNb, vector<bool> locations) {
	/* eye color */
	sequence.insert(sequence.end(), colorBin.begin(), colorBin.end());

	/* eye number */
	if(eyeNb > pow(2, xml->EYE_NB_LENGTH())-1) {
		eyeNb = pow(2, xml->EYE_NB_LENGTH())-1;
	}
	else if(eyeNb < 0) {
		eyeNb = 0;
	}
	vector<bool> eyeNbBin = decToBinary(eyeNb, xml->EYE_NB_LENGTH());
	sequence.insert(sequence.end(), eyeNbBin.begin(), eyeNbBin.end());

	/* eyes positions */
	if(locations.size() > eyeNb*xml->LIMB_NB_LENGTH()) {
		locations = vector<bool>(locations.begin(), locations.begin()+eyeNb*xml->LIMB_NB_LENGTH());
	}
	else if(locations.size() < eyeNb*xml->LIMB_NB_LENGTH()) {
		int i;
		for(i=locations.size() ; i<eyeNb*xml->LIMB_NB_LENGTH() ; i++) {
			locations.push_back(0);
		}
	}
	sequence.insert(sequence.end(), locations.begin(), locations.begin()+eyeNb*xml->LIMB_NB_LENGTH());

}

vector<bool> EyeStrand::getColorBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+xml->EYE_COLOR_LENGTH());
}

string EyeStrand::getColor() {
	return string(binaryToHex(vector<bool>(sequence.begin(), sequence.begin()+xml->EYE_COLOR_LENGTH())));
}

vector<bool> EyeStrand::getNumberBin() {
	return vector<bool>(sequence.begin()+xml->EYE_COLOR_LENGTH(), sequence.begin()+xml->EYE_COLOR_LENGTH()+xml->EYE_NB_LENGTH());
}

int EyeStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin()+xml->EYE_COLOR_LENGTH(), sequence.begin()+xml->EYE_COLOR_LENGTH()+xml->EYE_NB_LENGTH()));
}

vector<bool> EyeStrand::getLocations() {
	return vector<bool>(sequence.begin()+xml->EYE_COLOR_LENGTH()+xml->EYE_NB_LENGTH(), sequence.end());
}

vector<bool> EyeStrand::getLocationOf(int index) {
	if(index < 0 || index >= getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+xml->EYE_COLOR_LENGTH()+xml->EYE_NB_LENGTH()+xml->LIMB_NB_LENGTH()*index,
						sequence.begin()+xml->EYE_COLOR_LENGTH()+xml->EYE_NB_LENGTH()+xml->LIMB_NB_LENGTH()*(index+1));
}
