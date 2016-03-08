#include "SkinStrand.hpp"

using namespace std;

SkinStrand::SkinStrand() {
	int i;

	/* Skin color */
	for(i=0 ; i<xml->SKIN_COLOR_LENGTH() ; i++) {
		sequence.push_back(rand()%2);
	}

	/* Skin hairiness */
	vector<bool> hairTypeBin = decToBinary(rand()%xml->getHairTypes().size(), xml->HAIR_TYPE_LENGTH());
	sequence.insert(sequence.end(), hairTypeBin.begin(), hairTypeBin.end());
}

SkinStrand::SkinStrand(vector<bool> colorBin, vector<bool> hairiness) {
	/* Skin color */
	if(colorBin.size() > (unsigned) xml->SKIN_COLOR_LENGTH()) {
		colorBin = vector<bool>(colorBin.begin(), colorBin.begin()+xml->SKIN_COLOR_LENGTH());
	}
	else if(colorBin.size() < (unsigned) xml->SKIN_COLOR_LENGTH()) {
		int i;
		for(i=colorBin.size() ; i<xml->SKIN_COLOR_LENGTH() ; i++) {
			colorBin.push_back(0);
		}
	}
	sequence.insert(sequence.end(), colorBin.begin(), colorBin.end()+xml->SKIN_COLOR_LENGTH());

	/* Skin hairiness */
	if(hairiness.size() > (unsigned) xml->HAIR_TYPE_LENGTH()) {
		hairiness = vector<bool>(hairiness.begin(), hairiness.begin()+xml->HAIR_TYPE_LENGTH());
	}
	else if(hairiness.size() < (unsigned) xml->HAIR_TYPE_LENGTH()) {
		int i;
		for(i=hairiness.size() ; i<xml->HAIR_TYPE_LENGTH() ; i++) {
			hairiness.push_back(0);
		}
	}
	sequence.insert(sequence.end(), hairiness.begin(), hairiness.begin()+xml->HAIR_TYPE_LENGTH());

}

vector<bool> SkinStrand::getColorBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+xml->SKIN_COLOR_LENGTH());
}

string SkinStrand::getColor() {
	return binaryToHex(getColorBin());
}

vector<bool> SkinStrand::getHairBin() {
	return vector<bool>(sequence.begin()+xml->SKIN_COLOR_LENGTH(), sequence.begin()+xml->SKIN_COLOR_LENGTH()+xml->HAIR_TYPE_LENGTH());
}

string SkinStrand::getHair() {
	return xml->getHairType(getHairBin());
}

string SkinStrand::getStrandType() {
	return "SkinStrand";
}

string SkinStrand::toString() {
	std::stringstream ss;

	ss << "Skin sequence : " << binaryToString(sequence) << endl;
	ss << "Skin color : " << binaryToString(getColorBin()) << " = " << getColor() << endl;
	ss << "Skin hair : " << binaryToString(getHairBin()) << " = " << getHair() << endl;

	return ss.str();
}

string SkinStrand::toString(string name) {
	std::stringstream ss;

	ss << name << " sequence : " << binaryToString(sequence) << endl;
	ss << name << " color : " << binaryToString(getColorBin()) << " = " << getColor() << endl;
	ss << name << " hair : " << binaryToString(getHairBin()) << " = " << getHair() << endl;

	return ss.str();
}
