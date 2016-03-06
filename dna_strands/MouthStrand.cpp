#include "MouthStrand.hpp"

using namespace std;

MouthStrand::MouthStrand(int limbNb) {

	int mouthType = rand()%((int) pow(2, xml->MOUTH_WIDTH_LENGTH()));
	int teethNb = rand()%((int) pow(2, xml->TEETH_NB_LENGTH()));
	int teethType = rand()%((int) pow(2, xml->TEETH_TYPE_LENGTH()));


	/* Mouth Type */
	vector<bool> mouthTypeBin = decToBinary(mouthType, xml->MOUTH_WIDTH_LENGTH());
	sequence.insert(sequence.end(), mouthTypeBin.begin(), mouthTypeBin.end());

	/* Teeth Number */
	vector<bool> teethNbBin = decToBinary(teethNb, xml->TEETH_NB_LENGTH());
	sequence.insert(sequence.end(), teethNbBin.begin(), teethNbBin.end());

	/* Teeth Type */
	vector<bool> teethTypeBin = decToBinary(teethType, xml->TEETH_TYPE_LENGTH());
	sequence.insert(sequence.end(), teethTypeBin.begin(), teethTypeBin.end());

	/* Mouth position */
	vector<bool> mouthLocationBin = decToBinary(rand()%limbNb, xml->LIMB_NB_LENGTH());
	sequence.insert(sequence.end(), mouthLocationBin.begin(), mouthLocationBin.end());

}

MouthStrand::MouthStrand(std::vector<bool> mouthType, int teethNb, std::vector<bool> teethType, std::vector<bool> locations) {

	/* Mouth Type */
	sequence.insert(sequence.end(), mouthType.begin(), mouthType.end());

	/* Teeth Number */
	if(teethNb > pow(2, xml->TEETH_NB_LENGTH())-1) {
		teethNb = pow(2, xml->TEETH_NB_LENGTH())-1;
	}
	else if(teethNb < 0) {
		teethNb = 0;
	}
	vector<bool> teethNbBin = decToBinary(teethNb, xml->TEETH_NB_LENGTH());
	sequence.insert(sequence.end(), teethNbBin.begin(), teethNbBin.end());

	/* Teeth Type */
	sequence.insert(sequence.end(), teethType.begin(), teethType.end());

	/* Mouth Position */
	if(locations.size() > (unsigned) teethNb*xml->LIMB_NB_LENGTH()) {
		locations = vector<bool>(locations.begin(), locations.begin()+teethNb*xml->LIMB_NB_LENGTH());
	}
	else if(locations.size() < (unsigned) teethNb*xml->LIMB_NB_LENGTH()) {
		int i;
		for(i=locations.size() ; i < teethNb*xml->LIMB_NB_LENGTH() ; i++) {
			locations.push_back(0);
		}
	}
	sequence.insert(sequence.end(), locations.begin(), locations.begin()+teethNb*xml->LIMB_NB_LENGTH());

}

vector<bool> MouthStrand::getMouthTypeBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+xml->MOUTH_WIDTH_LENGTH());
}

string MouthStrand::getMouthType() {
	/* TODO :
		Return the according type of the mouth in string (i.e. : "small", "large", etc.)
	*/

	return "Not Done Yet.\n";
}

vector<bool> MouthStrand::getTeethNbBin() {
	return vector<bool>(sequence.begin()+xml->MOUTH_WIDTH_LENGTH(), sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH());
}

int MouthStrand::getTeethNb() {
	return binaryToDec(vector<bool>(sequence.begin()+xml->MOUTH_WIDTH_LENGTH(), sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH()));
}

vector<bool> MouthStrand::getTeethTypeeBin() {
	return vector<bool>(sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH(), sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH()+xml->TEETH_TYPE_LENGTH());
}

string MouthStrand::getTeethType() {
	/* TODO :
		Return the according type of the mouth in string (i.e. : "small", "large", etc.)
	*/

	return "Not Done Yet.\n";
}

vector<bool> MouthStrand::getLocation() {
	return vector<bool>(sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH()+xml->TEETH_TYPE_LENGTH(), sequence.end());
}

string MouthStrand::getStrandType() {
	return "MouthStrand";
}
