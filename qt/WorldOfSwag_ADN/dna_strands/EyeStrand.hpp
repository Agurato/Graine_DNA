#ifndef DEF_EYE_STRAND
#define DEF_EYE_STRAND

#include <string>
#include <vector>

#include "Strand.hpp"
#include "LimbStrand.hpp"

#define EYE_COLOR_SIZE 24
#define EYE_NB_SIZE 3

/* Construction du brin d'ADN pour la partie œil :
- 24 bits pour la couleur
- 3 bits pour le nombre
- 2 bits pour chaque œil existant
*/

class EyeStrand : public Strand {
public:
	EyeStrand(int limbNb);
	EyeStrand(std::string color, int nbEyes, std::vector<bool> locations);

	std::vector<bool> getColorBin();
	std::string getColor();

	std::vector<bool> getNumberBin();
	int getNumber();

	std::vector<bool> getLocationsBin();
};

#endif
