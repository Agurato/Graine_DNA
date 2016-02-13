#include "utils.hpp"

using namespace std;

vector<bool> decToBinary(int input, int nbBits) {
	vector<bool> bits;
	int value = pow(2, nbBits-1);

	while(value > 0) {
		if(input >= value) {
			bits.push_back(1);
			input -= value;
		}
		else {
			bits.push_back(0);
		}

		value /= 2;
	}

	return bits;
}

int binaryToDec(vector<bool> bits) {
	int value = 0, index = 1;

	for(bool b : bits) {
		if(b == 1) {
			value += pow(2, bits.size()-index);
		}
		index++;
	}

	return value;
}

string binaryToHex(vector<bool> bits) {
	vector<bool> vec;
	unsigned int i;
	string result;

	for(i=0 ; i<bits.size()%4 ; i++) {
		vec.push_back(0);
	}
	for(i=0 ; i<bits.size() ; i++) {
		vec.push_back(bits[i]);
	}

	for(i=0 ; i<vec.size() ; i+=4) {
		int decValue = binaryToDec(std::vector<bool>(vec.begin()+i, vec.begin()+i+4));
		switch (decValue) {
			case 15:
				result += "F";
				break;
			case 14:
				result += "E";
				break;
			case 13:
				result += "D";
				break;
			case 12:
				result += "C";
				break;
			case 11:
				result += "B";
				break;
			case 10:
				result += "A";
				break;
			default:
				result += to_string(decValue);
				break;
		}
	}

	return result;
}

string binaryToString(vector<bool> bits) {
	string s = "";
	for(bool b : bits) {
		s += to_string(b);
	}

	return s;
}
