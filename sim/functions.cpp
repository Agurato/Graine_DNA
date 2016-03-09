#include "functions.hpp"

using namespace std;

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

	dna.addStrand("skin", skinStrand);
	dna.addStrand("limb", limbStrand);
	dna.addStrand("ear", earStrand);
	dna.addStrand("eye", eyeStrand);
	dna.addStrand("mouth", mouthStrand);
	dna.addStrand("nostril", nostrilStrand);

	return dna;
}

DNA mating(DNA dna1, DNA dna2) {

	int choice;
	DNA newDNA;

	map<string, Strand*> dnaStrand1 = dna1.getDNAStrand();
	map<string, Strand*>::iterator it1 = dnaStrand1.begin();
	map<string, Strand*> dnaStrand2 = dna2.getDNAStrand();
	map<string, Strand*>::iterator it2 = dnaStrand2.begin();

	if(dnaStrand1.size() != dnaStrand2.size()) {
		cerr << "Can't mate, creatures have mismatched DNA" << endl;
		return newDNA;
	}

	while(it1 != dnaStrand1.end()) {
		string key = it1->first;
		choice = rand()%2;
		if(choice == 0) {
			newDNA.addStrand(key, it1->second);
		}
		else {
			newDNA.addStrand(key, it2->second);
		}

		++it1;
		++it2;
	}

	return newDNA;

}

DNA matingMut(DNA dnaStrand1, DNA dnaStrand2) {

	int choice;
	int mutation;
	MutationTypes mutationType;
	int mutationPlace;
	vector<Strand*> mutatedDNAStrand;
	DNA newDNA, mutatedDNA;

	map<string, Strand*> vectorDNAStrand1 = dnaStrand1.getDNAStrand();
	map<string, Strand*> vectorDNAStrand2 = dnaStrand2.getDNAStrand();

	if(vectorDNAStrand1.size() != vectorDNAStrand2.size()) {
		cerr << "Can't mate, creatures have mismatched DNA" << endl;
		return newDNA;
	}

	for(unsigned i = 0; i < vectorDNAStrand1.size(); i++) {
		choice = rand()%2;
		if(choice == 0) {
			//newDNA.addStrand(vectorDNAStrand1[i]);
			//cout << "DNA taken from first Strand" << endl;
		}
		else {
			//newDNA.addStrand(vectorDNAStrand2[i]);
			//cout << "DNA taken from second Strand" << endl;
		}
	}

	mutation = rand()%15000;
	if(mutation == 1) {

		mutatedDNA = newDNA.getDNAStrand();
		mutationPlace = rand()%mutatedDNA.getDNAStrand().size();
		mutationType = MutationTypes(rand()%3);

		if(mutationType == add) {
			newDNA.setDNAStrand(AddMutation(mutatedDNA, mutationPlace, mutationType));
		}
		else if(mutationType == del) {
			newDNA.setDNAStrand(DelMutation(mutatedDNA, mutationPlace, mutationType));
		}
		else {
			newDNA.setDNAStrand(SubMutation(mutatedDNA, mutationPlace, mutationType));
		}
	}
	return newDNA;
}

map<string, Strand*> AddMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType) {
	return mutatedDNA.getDNAStrand();
}

map<string, Strand*> DelMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType) {
	return mutatedDNA.getDNAStrand();
}

map<string, Strand*> SubMutation(DNA mutatedDNA, int mutationPlace, MutationTypes mutationType) {
	return mutatedDNA.getDNAStrand();
}

map<int, Creature> mateAndKill(map<int, Creature> creatures, int* counter) {
	int j = 1, size = creatures.size();

	map<int, Creature>::iterator it;
	map<int, Creature> nextGen;

	/* For each creature */
	for(it=creatures.begin() ; it != creatures.end() ; ++it, j++) {
		int id1 = it->first;
		Creature c1 = it->second;

		SkinStrand *skin1 = (SkinStrand*) c1.getDNA().getDNAStrand().find("skin")->second;

		int deathBonus1;
		if(skin1->getHair() == "fur") {
			deathBonus1 = -ENV_FACTOR;
		}
		else {
			deathBonus1 = ENV_FACTOR;
		}
		/* If the number of creatures is uneven */
		if(size%2 != 1 || j != size) {
			it++;
			j++;
			int id2 = it->first;
			Creature c2 = it->second;

			SkinStrand *skin2 = (SkinStrand*) c2.getDNA().getDNAStrand().find("skin")->second;
			int deathBonus2;
			if(skin2->getHair() == "fur") {
				deathBonus2 = -ENV_FACTOR;
			}
			else {
				deathBonus2 = ENV_FACTOR;
			}

			DNA newDNA = mating(c1.getDNA(), c2.getDNA());
			Creature c(*counter, newDNA);
			nextGen.insert(pair<int, Creature>(*counter, c));
			(*counter)++;

			/* Creature 2 lives */
			if(rand()%1000 > DEATH_CHANCE+deathBonus2) {
				nextGen.insert(pair<int, Creature>(id2, c2));
			}
		}
		/* Creature 1 lives */
		if(rand()%1000 > DEATH_CHANCE+deathBonus1) {
			nextGen.insert(pair<int, Creature>(id1, c1));
		}
	}

	return nextGen;
}

void registerGen(int gen, map<int, Creature> creatures, vector<string>* saveLines) {
	stringstream save;
	save.precision(5);

	float nbFur = 0;
	for(auto const& x : creatures) {
		Creature c = x.second;
		SkinStrand *skin = (SkinStrand*) c.getDNA().getDNAStrand().find("skin")->second;
		if(skin->getHair() == "fur") {
			nbFur ++;
		}
	}
	float percentage = nbFur/creatures.size()*100;

	save << gen << " " << creatures.size() << " " << nbFur << " " << percentage << endl;
	saveLines->push_back(save.str());
}

void saveCsv(vector<string> saveLines) {
	time_t now = time(0);
	tm* date = localtime(&now);

	stringstream ss;

	ss << "results/";

	ss << 1900+date->tm_year;
	if(date->tm_mon+1 < 10) {
		ss << "0" << date->tm_mon+1;
	}
	else {
		ss << date->tm_mon+1;
	}

	if(date->tm_mday < 10) {
		ss << "0" << date->tm_mday;
	}
	else {
		ss << date->tm_mday;
	}

	if(date->tm_hour+1 < 10) {
		ss << "0" << date->tm_hour+1;
	}
	else {
		ss << date->tm_hour+1;
	}

	if(date->tm_min+1 < 10) {
		ss << "0" << date->tm_min+1;
	}
	else {
		ss << date->tm_min+1;
	}

	if(date->tm_sec+1 < 10) {
		ss << "0" << date->tm_sec+1;
	}
	else {
		ss << date->tm_sec+1;
	}

	ss << ".csv";
	saveCsv(saveLines, ss.str());
}

void saveCsv(vector<string> saveLines, string filename) {
	ofstream saveFile;
	saveFile.open(filename);

	for(auto const& x : saveLines) {
		saveFile << x;
	}
	cout << "Saved as " << filename << endl;
	saveFile.close();
}
