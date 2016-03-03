#include <cmath>
#include <ctime>

#include "EyeStrand.hpp"
#include "LimbStrand.hpp"
#include "../utils/utils.hpp"

using namespace std;

EyeStrand::EyeStrand(int limbNb) {
	srand(time(0));
	int i;
	int eyeNb = rand()%((int) pow(2, EYE_NB_LENGTH));

	/* Eye color */
	for(i=0 ; i<EYE_COLOR_LENGTH ; i++) {
		sequence.push_back(rand()%2);
	}

	/* Eye number */
	vector<bool> eyeNbBin = decToBinary(eyeNb, EYE_NB_LENGTH);
	sequence.insert(sequence.end(), eyeNbBin.begin(), eyeNbBin.end());

	/* Eyes positions */
	for(i=0 ; i<eyeNb ; i++) {
		vector<bool> eyeLocationBin = decToBinary(rand()%limbNb, LIMB_NB_LENGTH);
		sequence.insert(sequence.end(), eyeLocationBin.begin(), eyeLocationBin.end());
	}

}

EyeStrand::EyeStrand(string hexColor, int nbEyes, vector<bool> locations) {
	/* eye color */
	vector<bool> binColor = hexToBinary(hexColor);
	sequence.insert(sequence.end(), binColor.begin(), binColor.end());

	/* eye number */
	if(nbEyes > pow(2, EYE_NB_LENGTH)-1) {
		nbEyes = pow(2, EYE_NB_LENGTH)-1;
	}
	else if(nbEyes < 0) {
		nbEyes = 0;
	}
	vector<bool> binNb = decToBinary(nbEyes, EYE_NB_LENGTH);
	sequence.insert(sequence.end(), binNb.begin(), binNb.end());

	/* eyes positions */
	if(locations.size() > nbEyes*2) {
		locations = vector<bool>(locations.begin(), locations.begin()+nbEyes*2);
	}
	else if(locations.size() < nbEyes*2) {
		int i;
		for(i=locations.size() ; i<nbEyes*2 ; i++) {
			locations.push_back(0);
		}
	}
	sequence.insert(sequence.end(), locations.begin(), locations.begin()+nbEyes*2);

}

vector<bool> EyeStrand::getColorBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+EYE_COLOR_LENGTH);
}

string EyeStrand::getColor() {
	return string(binaryToHex(vector<bool>(sequence.begin(), sequence.begin()+EYE_COLOR_LENGTH)));
}

vector<bool> EyeStrand::getNumberBin() {
	return vector<bool>(sequence.begin()+EYE_COLOR_LENGTH, sequence.begin()+EYE_COLOR_LENGTH+EYE_NB_LENGTH);
}

int EyeStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin()+EYE_COLOR_LENGTH, sequence.begin()+EYE_COLOR_LENGTH+EYE_NB_LENGTH));
}

vector<bool> EyeStrand::getLocations() {
	return vector<bool>(sequence.begin()+EYE_COLOR_LENGTH+EYE_NB_LENGTH, sequence.end());
}

vector<bool> EyeStrand::getLocationOf(int index) {
	if(index < 0 || index >= getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+EYE_COLOR_LENGTH+LIMB_NB_LENGTH*index, sequence.begin()+EYE_COLOR_LENGTH+LIMB_NB_LENGTH*(index+1));
}
