#include <iostream>

#include "utils/utils.hpp"
#include "parts/XMLData.hpp"

using namespace std;

int main(int argc, char **argv) {

	XMLData::getInstance();

	string file;
	if(argc < 2) {
		file = "parts/codes.xml";
	}
	else {
		file = argv[1];
	}
	XMLData::parseXML(file);

	return 0;
}
