#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "utils/utils.hpp"

using namespace std;

int main() {
	srand(time(0));

	int r = rand()%10;
	cout << r << endl;

	vector<bool> bits = decToBinary(714, 10);

	vector<bool>::const_iterator start = bits.begin();
	vector<bool>::const_iterator end1 = bits.begin()+3;
	vector<bool>::const_iterator end2 = bits.begin()+6;


	cout << "binaryToString(bits) : " << binaryToString(bits) << endl;

	cout << "end1 : bits.begin()+3" << endl;
	cout << "end2 : bits.begin()+6" << endl;
	cout << "vector<bool>(start, end1) : " << binaryToString(vector<bool>(start, end1)) << endl;
	cout << "vector<bool>(end1, end2) : " << binaryToString(vector<bool>(end1, end2)) << endl;

	cout << "binaryToDec(std::vector<bool>(start, end1)) : " << binaryToDec(std::vector<bool>(start, end1)) << endl;
	cout << "binaryToDec(std::vector<bool>(end1, end2)) : " << binaryToDec(std::vector<bool>(end1, end2)) << endl;
	cout << "binaryToDec(bits) : " << binaryToDec(bits) << endl;
	cout << "binaryToHex(bits) : " << binaryToHex(bits) << endl;
	cout << "hexToBinary(\"FD56A0\") : " << binaryToString(hexToBinary("FD56A0")) << endl;
	cout << "binaryToHex(hexToBinary(\"FD56A0\")) : " << binaryToHex(hexToBinary("FD56A0")) << endl;

	for(int i=0 ; i<17 ; i++) {
		cout << "nbBits(" << i << ") : " << nbBitsMin(i) << endl;
	}

	return 0;
}
