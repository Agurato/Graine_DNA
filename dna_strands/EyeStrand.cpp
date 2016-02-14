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
	srand(time(0));
	int i;
	int eyeNb = rand()%8;

	/* eye color */
	for(i=0 ; i<24 ; i++) {
		sequence.push_back(rand()%2);
	}

	/* eye number */
	vector<bool> nbVector = decToBinary(eyeNb, 3);
	sequence.insert(sequence.end(), nbVector.begin(), nbVector.end());

	/* eye positions */
	for(i=0 ; i<eyeNb ; i++) {
		vector<bool> locVector = decToBinary(rand()%4, 2);
		sequence.insert(sequence.end(), locVector.begin(), locVector.end());
	}

}

EyeStrand::EyeStrand(string hexColor, int nbEyes, vector<bool> locations) {
	/* eye color */
	vector<bool> binColor = hexToBinary(hexColor);
	sequence.insert(sequence.end(), binColor.begin(), binColor.end());

	/* eye number */
	if(nbEyes > 7) {
		nbEyes = 7;
	}
	else if(nbEyes < 0) {
		nbEyes = 0;
	}
	vector<bool> binNb = decToBinary(nbEyes, 3);
	sequence.insert(sequence.end(), binNb.begin(), binNb.end());

	/* eyes positions */
	if(locations.size() > nbEyes*2) {
		locations = vector<bool>(locations.begin(), locations.begin()+nbEyes*2);
	}
	else if(locations.size() < nbEyes*2) {
		int i;
		for(i=locations.size() ; i<nbEyes*2 ; i++) {
			locations.push_back(0);
		}
	}
	sequence.insert(sequence.end(), locations.begin(), locations.begin()+nbEyes*2);

}

vector<bool> EyeStrand::getColorBin() {
	return vector<bool>(sequence.begin(), sequence.begin()+24);
}

string EyeStrand::getColor() {
	return string(binaryToHex(vector<bool>(sequence.begin(), sequence.begin()+24)));
}

vector<bool> EyeStrand::getNumberBin() {
	return vector<bool>(sequence.begin()+24, sequence.begin()+27);
}

int EyeStrand::getNumber() {
	return binaryToDec(vector<bool>(sequence.begin()+24, sequence.begin()+27));
}

vector<bool> EyeStrand::getLocationsBin() {
	return vector<bool>(sequence.begin()+27, sequence.end());
}
