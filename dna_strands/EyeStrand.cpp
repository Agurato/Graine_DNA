#include <string>
#include <vector>
#include <ctime>
#include <cmath>

#include "EyeStrand.hpp"
#include "Strand.hpp"
#include "LimbStrand.hpp"
#include "../utils/utils.hpp"

using namespace std;

EyeStrand::EyeStrand() {
	srand(time(0));
	int i;
	int eyeNb = rand()%(2*EYE_NB_SIZE);

	/* eye color */
	for(i=0 ; i<EYE_COLOR_SIZE ; i++) {
		sequence.push_back(rand()%2);
	}

	/* eye number */
	vector<bool> nbVector = decToBinary(eyeNb, EYE_NB_SIZE);
	sequence.insert(sequence.end(), nbVector.begin(), nbVector.end());

	/* eye positions */
	for(i=0 ; i<eyeNb ; i++) {
		vector<bool> locVector = decToBinary(rand()%4, 2);
		sequence.insert(sequence.end(), locVector.begin(), locVector.end());
	}

}

EyeStrand::EyeStrand(string hexColor, int nbEyes, vector<bool> locations) {
	/* eye color */
	vector<bool> binColor = hexToBinary(hexColor);
	sequence.insert(sequence.end(), binColor.begin(), binColor.end());

	/* eye number */
	if(nbEyes > pow(2, EYE_NB_SIZE)-1) {
		nbEyes = pow(2, EYE_NB_SIZE)-1;
	}
	else if(nbEyes < 0) {
		nbEyes = 0;
	}
	vector<bool> binNb = decToBinary(nbEyes, EYE_NB_SIZE);
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
	return vector<bool>(sequence.begin(), sequence.begin()+EYE_COLOR_SIZE);
}

string EyeStrand::getColor() {
	return string(binaryToHex(vector<bool>(sequence.begin(), sequence.begin()+EYE_COLOR_SIZE)));
}

vector<bool> EyeStrand::getNumberBin() {
	return vector<bool>(sequence.begin()+EYE_COLOR_SIZE, sequence.begin()+EYE_COLOR_SIZE+EYE_NB_SIZE);
}

int EyeStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin()+EYE_COLOR_SIZE, sequence.begin()+EYE_COLOR_SIZE+EYE_NB_SIZE));
}

vector<bool> EyeStrand::getLocationsBin() {
	return vector<bool>(sequence.begin()+EYE_COLOR_SIZE+EYE_NB_SIZE, sequence.end());
}
