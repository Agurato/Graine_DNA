#include <cmath>
#include <ctime>

#include "LimbStrand.hpp"
#include "../utils/utils.hpp"

using namespace std;

LimbStrand::LimbStrand() {
	int i=0;
	srand(time(0));

	int limbNb = rand()%((int) pow(2, LIMB_NB_LENGTH));

	/* Limb number */
	vector<bool> limbNbBin = decToBinary(limbNb, LIMB_NB_LENGTH);
	sequence.insert(sequence.end(), limbNbBin.begin(), limbNbBin.end());

	/* Limb sizes */
	for(i=0 ; i<limbNb ; i++) {
		vector<bool> limbSizeBin = decToBinary(rand()%((int) pow(2, LIMB_SIZE_LENGTH)), LIMB_SIZE_LENGTH);
		sequence.insert(sequence.end(), limbSizeBin.begin(), limbSizeBin.end());
	}

	/* Limb types (extremities) */
	for(i=0 ; i<limbNb ; i++) {
		vector<bool> limbTypeBin = decToBinary(rand()%((int) pow(2, LIMB_TYPES_LENGTH)), LIMB_TYPES_LENGTH);
		sequence.insert(sequence.end(), limbTypeBin.begin(), limbTypeBin.end());
	}
}

LimbStrand::LimbStrand(int limbNb, vector<bool> limbSizes, vector<bool> limbTypes) {
	/* Limb number */
	vector<bool> limbNbBin = decToBinary(limbNb, LIMB_NB_LENGTH);
	sequence.insert(sequence.end(), limbNbBin.begin(), limbNbBin.end());

	/* Limb sizes */
	sequence.insert(sequence.end(), limbSizes.begin(), limbSizes.end());

	/* Limb types (extremities) */
	sequence.insert(sequence.end(), limbTypes.begin(), limbTypes.end());
}

vector<bool> LimbStrand::getNumberBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+LIMB_NB_LENGTH);
}

int LimbStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin(), sequence.begin()+LIMB_NB_LENGTH));
}

/* Renvoie la chaîne de booléens correspondant à la totalité des tailles */
vector<bool> LimbStrand::getSizes() {
	return vector<bool>(sequence.begin()+LIMB_NB_LENGTH, sequence.begin()+LIMB_NB_LENGTH+LIMB_SIZE_LENGTH*getNumber());
}

/* Renvoie la chaîne de booléens correspondanst à la taille du n° du membre passé en paramètre */
vector<bool> LimbStrand::getSizeOf(int index) {
	if(index < 1 || index > getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+LIMB_NB_LENGTH+LIMB_SIZE_LENGTH*(index-1), sequence.begin()+LIMB_NB_LENGTH+LIMB_SIZE_LENGTH*index);
}

/* Renvoie la chaîne de booléens correspondant à la totalité des types */
vector<bool> LimbStrand::getTypes() {
	return vector<bool>(sequence.begin()+LIMB_NB_LENGTH+LIMB_SIZE_LENGTH*getNumber(), sequence.end());
}

/* Renvoie la chaîne de booléens correspondanst au type du n° du membre passé en paramètre */
vector<bool> LimbStrand::getTypeOf(int index) {
	if(index <1 || index > getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+LIMB_NB_LENGTH+LIMB_SIZE_LENGTH*getNumber()+LIMB_TYPES_LENGTH*(index-1),
		sequence.begin()+LIMB_NB_LENGTH+LIMB_SIZE_LENGTH*getNumber()+LIMB_TYPES_LENGTH*index);
}
