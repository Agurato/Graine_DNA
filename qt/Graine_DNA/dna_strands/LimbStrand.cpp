#include "LimbStrand.hpp"

using namespace std;

LimbStrand::LimbStrand() {
	int i=0;

    int limbNb = rand()%((int) pow(2, xml->LIMB_NB_LENGTH()));

	/* Limb number */
	vector<bool> limbNbBin = decToBinary(limbNb, xml->LIMB_NB_LENGTH());
	sequence.insert(sequence.end(), limbNbBin.begin(), limbNbBin.end());

	/* Limb sizes */
	for(i=0 ; i<limbNb ; i++) {
		vector<bool> limbSizeBin = decToBinary(rand()%((int) pow(2, xml->LIMB_SIZE_LENGTH())), xml->LIMB_SIZE_LENGTH());
		sequence.insert(sequence.end(), limbSizeBin.begin(), limbSizeBin.end());
	}

	/* Limb types (extremities) */
	for(i=0 ; i<limbNb ; i++) {
		vector<bool> limbTypeBin = decToBinary(rand()%((int) pow(2, xml->LIMB_TYPE_LENGTH())), xml->LIMB_TYPE_LENGTH());
		sequence.insert(sequence.end(), limbTypeBin.begin(), limbTypeBin.end());
	}
}

LimbStrand::LimbStrand(int limbNb, vector<bool> limbSizes, vector<bool> limbTypes) {
	/* Limb number */
	vector<bool> limbNbBin = decToBinary(limbNb, xml->LIMB_NB_LENGTH());
	sequence.insert(sequence.end(), limbNbBin.begin(), limbNbBin.end());

	/* Limb sizes */
	sequence.insert(sequence.end(), limbSizes.begin(), limbSizes.end());

	/* Limb types (extremities) */
	sequence.insert(sequence.end(), limbTypes.begin(), limbTypes.end());
}

vector<bool> LimbStrand::getNumberBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+xml->LIMB_NB_LENGTH());
}

int LimbStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin(), sequence.begin()+xml->LIMB_NB_LENGTH()));
}

/* Renvoie la chaîne de booléens correspondant à la totalité des tailles */
vector<bool> LimbStrand::getSizes() {
	return vector<bool>(sequence.begin()+xml->LIMB_NB_LENGTH(), sequence.begin()+xml->LIMB_NB_LENGTH()+xml->LIMB_SIZE_LENGTH()*getNumber());
}

/* Renvoie la chaîne de booléens correspondanst à la taille du n° du membre passé en paramètre */
vector<bool> LimbStrand::getSizeBinOf(int index) {
	if(index < 0 || index >= getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+xml->LIMB_NB_LENGTH()+xml->LIMB_SIZE_LENGTH()*index, sequence.begin()+xml->LIMB_NB_LENGTH()+xml->LIMB_SIZE_LENGTH()*(index+1));
}

int LimbStrand::getSizeOf(int index) {
	return binaryToDec(getSizeBinOf(index));
}

/* Renvoie la chaîne de booléens correspondant à la totalité des types */
vector<bool> LimbStrand::getTypesBin() {
	return vector<bool>(sequence.begin()+xml->LIMB_NB_LENGTH()+xml->LIMB_SIZE_LENGTH()*getNumber(), sequence.end());
}

/* Renvoie la chaîne de booléens correspondanst au type du n° du membre passé en paramètre */
vector<bool> LimbStrand::getTypeBinOf(int index) {
	if(index < 0 || index >= getNumber()) {
		return vector<bool>();
	}
	return vector<bool>(sequence.begin()+xml->LIMB_NB_LENGTH()+xml->LIMB_SIZE_LENGTH()*getNumber()+xml->LIMB_TYPE_LENGTH()*index,
		sequence.begin()+xml->LIMB_NB_LENGTH()+xml->LIMB_SIZE_LENGTH()*getNumber()+xml->LIMB_TYPE_LENGTH()*(index+1));
}

string LimbStrand::getTypeOf(int index) {
	return xml->getLimbType(getTypeBinOf(index));
}

string LimbStrand::getStrandType() {
	return "LimbStrand";
}

string LimbStrand::toString() {
	std::stringstream ss;

	int i = 0 , nb = getNumber();

	ss << "Limb sequence : " << binaryToString(sequence) << endl;
	ss << "Limb number : " << binaryToString(getNumberBin()) << " = " << nb << endl;
	ss << "Limb sizes : " << binaryToString(getSizes()) << endl;
	ss << "Limb types : " << binaryToString(getTypesBin()) << endl;
	for(i=0 ; i<nb ; i++) {
		ss << "Limb size of n°" << i << " : " << binaryToString(getSizeBinOf(i)) << " = " << getSizeOf(i) << endl;
		ss << "Limb type of n°" << i << " : " << binaryToString(getTypeBinOf(i)) << " = " << getTypeOf(i) << endl;
	}

	return ss.str();
}

string LimbStrand::toString(string name) {
	std::stringstream ss;

	int i = 0 , nb = getNumber();

	ss << name << " sequence : " << binaryToString(sequence) << endl;
	ss << name << " number : " << binaryToString(getNumberBin()) << " = " << nb << endl;
	ss << name << " sizes : " << binaryToString(getSizes()) << endl;
	ss << name << " types : " << binaryToString(getTypesBin()) << endl;
	for(i=0 ; i<nb ; i++) {
		ss << name << " size of n°" << i << " : " << binaryToString(getSizeBinOf(i)) << " = " << getSizeOf(i) << endl;
		ss << name << " type of n°" << i << " : " << binaryToString(getTypeBinOf(i)) << " = " << getTypeOf(i) << endl;
	}

	return ss.str();
}
