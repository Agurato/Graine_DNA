#include "MouthStrand.hpp"

using namespace std;

MouthStrand::MouthStrand(int limbNb) {

	int mouthType = rand()%xml->getMouthWidthTypes().size();
	int teethNb = rand()%((int) pow(2, xml->TEETH_NB_LENGTH()));
	int teethType = rand()%xml->getTeethTypes().size();

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
	vector<bool> mouthLocationBin = decToBinary(rand()%(limbNb+1), xml->LIMB_NB_LENGTH());
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
	return xml->getMouthWidthType(getMouthTypeBin());
}

vector<bool> MouthStrand::getTeethNbBin() {
	return vector<bool>(sequence.begin()+xml->MOUTH_WIDTH_LENGTH(), sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH());
}

int MouthStrand::getTeethNb() {
	return binaryToDec(vector<bool>(sequence.begin()+xml->MOUTH_WIDTH_LENGTH(), sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH()));
}

vector<bool> MouthStrand::getTeethTypeBin() {
	return vector<bool>(sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH(), sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH()+xml->TEETH_TYPE_LENGTH());
}

string MouthStrand::getTeethType() {
	return xml->getTeethType(getTeethTypeBin());
}

vector<bool> MouthStrand::getLocation() {
	return vector<bool>(sequence.begin()+xml->MOUTH_WIDTH_LENGTH()+xml->TEETH_NB_LENGTH()+xml->TEETH_TYPE_LENGTH(), sequence.end());
}

string MouthStrand::getStrandType() {
	return "MouthStrand";
}

string MouthStrand::toString() {
	std::stringstream ss;

	ss << "Mouth sequence : " << binaryToString(sequence) << endl;
	ss << "Mouth type : " << binaryToString(getMouthTypeBin()) << " = " << getMouthType() << endl;
	ss << "Mouth : teeth number : " << binaryToString(getTeethNbBin()) << " = " << getTeethNb() << endl;
	ss << "Mouth : teeth type : " << binaryToString(getTeethTypeBin()) << " = " << getTeethType() << endl;
	ss << "Mouth location : " << binaryToString(getLocation()) << endl;

	return ss.str();
}

string MouthStrand::toString(string name) {
	std::stringstream ss;

	ss << name << " sequence : " << binaryToString(sequence) << endl;
	ss << name << " type : " << binaryToString(getMouthTypeBin()) << " = " << getMouthType() << endl;
	ss << name << " : teeth number : " << binaryToString(getTeethNbBin()) << " = " << getTeethNb() << endl;
	ss << name << " : teeth type : " << binaryToString(getTeethTypeBin()) << " = " << getTeethType() << endl;
	ss << name << " location : " << binaryToString(getLocation()) << endl;

	return ss.str();
}
