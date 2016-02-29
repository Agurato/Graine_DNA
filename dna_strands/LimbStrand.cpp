#include <string>
#include <vector>
#include <cmath>

#include "Strand.hpp"
#include "LimbStrand.hpp"
#include "../utils/utils.hpp"

using namespace std;

LimbStrand::LimbStrand() {
	int i=0;
	srand(time(0));

	int limbNb = rand()%((int) pow(2, LIMB_NUMBER_LENGTH));

	/* Limb number */
	vector<bool> limbNbVector = decToBinary(limbNb, LIMB_NUMBER_LENGTH);
	sequence.insert(sequence.end(), limbNbVector.begin(), limbNbVector.end());

	/* positions
	for(i=0 ; i<limbNb ; i++) {
		vector<bool> locVector = decToBinary(rand()%4, 2);
		sequence.insert(sequence.end(), locVector.begin(), locVector.end());
	}
	*/

	/* sizes */
	for(i=0 ; i<limbNb ; i++) {
		vector<bool> sizeVect = decToBinary(rand()%(int) pow(2, LIMB_SIZE_LENGTH), LIMB_SIZE_LENGTH);
		sequence.insert(sequence.end(), sizeVect.begin(), sizeVect.end());
	}

	/* types (extremities) */
	for(i=0 ; i<limbNb ; i++) {
		vector<bool> typesVect = decToBinary(rand()%(int) pow(2, LIMB_TYPES_LENGTH), LIMB_TYPES_LENGTH);
		sequence.insert(sequence.end(), typesVect.begin(), typesVect.end());
	}
}

LimbStrand::LimbStrand(int nb, vector<bool> locations, vector<bool> sizes, vector<bool> types) {

}

vector<bool> LimbStrand::getNumberBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+LIMB_NUMBER_LENGTH);
}

int LimbStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin(), sequence.begin()+LIMB_NUMBER_LENGTH));
}

/* Renvoie la chaîne de booléens correspondant à la totalité des tailles */
vector<bool> LimbStrand::getSizes() {
	return vector<bool>(sequence.begin()+LIMB_NUMBER_LENGTH, sequence.begin()+LIMB_NUMBER_LENGTH+LIMB_SIZE_LENGTH*getNumber());
}

/* Renvoie la chaîne de booléens correspondanst à la taille du n° du membre passé en paramètre */
vector<bool> LimbStrand::getSizeOfIndex(int index) {
	if(index >= getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+LIMB_NUMBER_LENGTH+LIMB_SIZE_LENGTH*index, sequence.begin()+LIMB_NUMBER_LENGTH+LIMB_SIZE_LENGTH*(index+1));
}

/* Renvoie la chaîne de booléens correspondant à la totalité des types */
vector<bool> LimbStrand::getTypes() {
	return  vector<bool>(sequence.begin()+LIMB_NUMBER_LENGTH+LIMB_SIZE_LENGTH*getNumber(), sequence.end());
}

/* Renvoie la chaîne de booléens correspondanst au type du n° du membre passé en paramètre */
vector<bool> LimbStrand::getTypeOfIndex(int index) {
	if(index >= getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.end()-LIMB_TYPES_LENGTH*(getNumber()-index), sequence.end()-LIMB_TYPES_LENGTH*(getNumber()-index+1));
}
