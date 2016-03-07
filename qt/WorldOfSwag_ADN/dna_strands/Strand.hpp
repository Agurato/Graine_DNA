#ifndef DEF_STRAND
#define DEF_STRAND

#include "../sim/XMLData.hpp"
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <sstream>

class Strand {
protected:
	XMLData* xml = XMLData::getInstance();
	std::vector<bool> sequence;
public:
	std::vector<bool> getSequence() {
		return sequence;
	}

	virtual std::string getStrandType();
	virtual std::string toString();
	virtual std::string toString(std::string name);
};

#endif
