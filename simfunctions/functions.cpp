#include "functions.hpp"

DNA mating(DNA dnaStrand1, DNA dnaStrand2) {

	int choice;
	vector<Strand*> vectorDNAStrand1;
	vector<Strand*> vectorDNAStrand2;
	DNA newDNA();

	srand(time(0));

	if(dnaStrand1.size() != dnaStrand2.size()) {
		cerr << "Can't mate, creatures have mismatched DNA" << endl;
		return NULL;
	}

	vectorDNAStrand1 = dnaStrand1.getDNAStrand();
	vectorDNAStrand2 = dnaStrand2.getDNAStrand();

	for(int i = 0; i < dnaStrand1.size(); i++) {
		choice = rand()%2;
		if(choice == 0) {
			newDNA.addStrand(vectorDNAStrand1[i]);
			cout << "DNA taken from first Strand" << endl;
		}
		else {
			newDNA.addStrand(vectorDNAStrand2[i]);
			cout << "DNA taken from second Strand" << endl;
		}
	}

	return newDNA;

}
