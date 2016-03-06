#ifndef DEF_DNA_STRAND
#define DEF_DNA_STRAND

#include "../parts/XMLData.hpp"
#include <string>
#include <vector>

class Strand {
protected:
	XMLData* xml = XMLData::getInstance();
	std::vector<bool> sequence;
public:
	std::vector<bool> getSequence() {
		return sequence;
	}

	virtual std::string getStrandType();
	//virtual void getInfos();
};


#endif
