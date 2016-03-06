#include "functions.hpp"

using namespace std;

enum MutationTypes {add = 0, del, sub};

DNA createRandomDNA() {
	DNA dna;
	int limbNb;

	LimbStrand* limbStrand = new LimbStrand();
	limbNb = limbStrand->getNumber();

	// Merci Bastien <3
	SkinStrand* skinStrand = new SkinStrand();
	EarStrand* earStrand = new EarStrand(limbNb);
	EyeStrand* eyeStrand = new EyeStrand(limbNb);
	MouthStrand* mouthStrand = new MouthStrand(limbNb);
	NostrilStrand* nostrilStrand = new NostrilStrand(limbNb);

	dna.addStrand(skinStrand);
	dna.addStrand(limbStrand);
	dna.addStrand(earStrand);
	dna.addStrand(eyeStrand);
	dna.addStrand(mouthStrand);
	dna.addStrand(nostrilStrand);

	return dna;
}

DNA mating(DNA dnaStrand1, DNA dnaStrand2) {

	int choice;
	DNA newDNA;

	vector<Strand*> vectorDNAStrand1 = dnaStrand1.getDNAStrand();
	vector<Strand*> vectorDNAStrand2 = dnaStrand2.getDNAStrand();

	if(vectorDNAStrand1.size() != vectorDNAStrand2.size()) {
		cerr << "Can't mate, creatures have mismatched DNA" << endl;
		return newDNA;
	}

	for(unsigned i = 0; i < vectorDNAStrand1.size(); i++) {
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

DNA matingMut(DNA dnaStrand1, DNA dnaStrand2) {

	int choice;
	int mutation;
	MutationTypes mutationType;
	int mutationPlace;
	vector<Strand*> mutatedDNAStrand;
	DNA newDNA;

	vector<Strand*> vectorDNAStrand1 = dnaStrand1.getDNAStrand();
	vector<Strand*> vectorDNAStrand2 = dnaStrand2.getDNAStrand();

	if(vectorDNAStrand1.size() != vectorDNAStrand2.size()) {
		cerr << "Can't mate, creatures have mismatched DNA" << endl;
		return newDNA;
	}

	for(unsigned i = 0; i < vectorDNAStrand1.size(); i++) {
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

	mutation = rand()%15000;
	if(mutation == 1) {

		mutatedDNA = newDNA.getDNAStrand();
		mutationPlace = rand()%mutatedDNA.size();
		mutationType = MutationTypes(rand()%3);

		if(mutationType == add) {
			newDNA.setDNAStrand(AddMutation(mutatedDNA, mutationPlace, mutationType));
		}
		else if(mutationType == del) {
			newDNA.setDNAStrand(Delmutation(mutatedDNA, mutationPlace, mutationType));
		}
		else {
			newDNA.setDNAStrand(SubMutation(mutatedDNA, mutationPlace, mutationType));
		}
	}
	return newDNA;
}

vector<Strand*> AddMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType) {
	return mutatedDNA;
}

vector<Strand*> DelMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType) {
	return mutatedDNA;
}

vector<Strand*> SubMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType) {
	return mutatedDNA;
}
