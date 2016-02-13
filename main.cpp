#include <iostream>
#include <bitset>

#include "utils/utils.hpp"

using namespace std;

int main() {
	srand(time(0));

	int r = std::rand()%10;
	cout << r << endl;

	vector<bool> bits = decToBinary(714, 10);

	vector<bool>::const_iterator start = bits.begin();
	vector<bool>::const_iterator end1 = bits.begin()+3;
	vector<bool>::const_iterator end2 = bits.begin()+6;

	cout << "binaryToString(bits) : " << binaryToString(bits) << endl;
	cout << "binaryToDec(std::vector<bool>(start, end1)) : " << binaryToDec(std::vector<bool>(start, end1)) << endl;
	cout << "binaryToDec(std::vector<bool>(end1, end2)) : " << binaryToDec(std::vector<bool>(end1, end2)) << endl;
	cout << "binaryToDec(bits) : " << binaryToDec(bits) << endl;
	cout << "binaryToHex(bits) : " << binaryToHex(bits) << endl;

	return 0;
}
