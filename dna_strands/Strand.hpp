#ifndef DEF_DNA_STRAND
#define DEF_DNA_STRAND

#include <string>
#include <vector>

class Strand {
protected:
	std::vector<bool> sequence;
public:
	std::vector<bool> getSequence() {
		return sequence;
	}

	virtual int getNumber() = 0;
};


#endif
