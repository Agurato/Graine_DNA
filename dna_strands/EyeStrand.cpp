#include <string>
#include <vector>
#include <ctime>

#include "EyeStrand.hpp"
#include "Strand.hpp"
#include "LimbStrand.hpp"
#include "../utils/utils.hpp"

using namespace std;

/* Construction du brin d'ADN pour la partie œil :
- 24 bits pour la couleur
- 3 bits pour le nombre
- 2 bits pour chaque œil existant
*/

EyeStrand::EyeStrand() {
	srand(std::time(0));

	//int eyeNb = rand()%8;

}

string EyeStrand::getEyeColor() {
	vector<bool>::const_iterator start = completeStrand.begin()+0;
	vector<bool>::const_iterator end = completeStrand.begin()+24;

	return string(binaryToHex(std::vector<bool>(start, end)));
}

int EyeStrand::getEyeNumber() {
	vector<bool>::const_iterator start = completeStrand.begin()+24;
	vector<bool>::const_iterator end = completeStrand.begin()+27;

	return binaryToDec(std::vector<bool>(start, end));
}
