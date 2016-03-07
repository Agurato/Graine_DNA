#ifndef DEF_DNA
#define DEF_DNA

#include <string>
#include <vector>
#include <map>
#include "dna_strands/Strand.hpp"

class DNA {
private:
	/* Il faut suivre cette suite dans dnaStrand :
	- SkinStrand
	- LimbStrand
	- EarStrand
	- EyeStrand
	- MouthStrand
	- NostrilStrand
	*/
	//std::vector<Strand*> dnaStrand;
	std::map<std::string, Strand*> dnaStrand;

public:
	DNA();
	DNA(std::map<std::string, Strand*> strands);

	void addStrand(std::string key, Strand* strand);

	std::map<std::string, Strand*> getDNAStrand();

	void setDNAStrand(std::map<std::string, Strand*> strands);

};


#endif
