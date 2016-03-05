#include <iostream>

#include "parts/XMLData.hpp"

using namespace std;

int main(int argc, char **argv) {

	XMLData* xml = XMLData::getInstance();

	string file;
	if(argc < 2) {
		file = "parts/codes.xml";
	}
	else {
		file = argv[1];
	}
	xml->parseXML(file);

	cout << "Hairiness : ";
	cout << "types=" << xml->HAIR_TYPE_LENGTH() << " (";
	for(auto const& value : xml->getHairTypes()) {
		cout << value << ";";
	}
	cout << ")" << endl;

	cout << endl << "Limbs : ";
	cout << "nb=" << xml->LIMB_NB_LENGTH() << " - size=" << xml->LIMB_SIZE_LENGTH() << " - types=" << xml->LIMB_TYPE_LENGTH() << " (";
	for(auto const& value : xml->getLimbTypes()) {
		cout << value << ";";
	}
	cout << ")" << endl;

	cout << endl << "Ears : ";
	cout << "nb=" << xml->EAR_NB_LENGTH() << endl;

	cout << endl << "Eyes : ";
	cout << "nb=" << xml->EYE_NB_LENGTH() << endl;

	cout << endl << "Nostrils : ";
	cout << "nb=" << xml->NOSTRIL_NB_LENGTH() << endl;

	cout << endl << "Mouth : ";
	cout << "types=" << xml->MOUTH_WIDTH_LENGTH() << " (";
	for(auto const& value : xml->getMouthWidthTypes()) {
		cout << value << ";";
	}
	cout << ")" << endl;
	cout << "Teeth : ";
	cout << "nb=" << xml->TEETH_NB_LENGTH() << " - types=" << xml->TEETH_TYPE_LENGTH() << " (";
	for(auto const& value : xml->getTeethTypes()) {
		cout << value << ";";
	}
	cout << ")" << endl;


	return 0;
}
