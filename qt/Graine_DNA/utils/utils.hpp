#ifndef DEF_UTILS
#define DEF_UTILS

#include <iostream>
#include <vector>
#include <cmath>

std::vector<bool> decToBinary(int input, int nbBits);
int binaryToDec(std::vector<bool> bits);
std::vector<bool> hexToBinary(std::string hex);
std::string binaryToHex(std::vector<bool> bits);
int nbBitsMin(int input);
std::string binaryToString(std::vector<bool> bits);

#endif
