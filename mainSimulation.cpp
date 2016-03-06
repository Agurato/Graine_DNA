#include <iostream>
#include <sstream>
#include <map>
#include "parts/XMLData.hpp"
#include "simfunctions/functions.hpp"
#include "DNA.hpp"
#include "Creature.hpp"

#define DEATH_CHANCE 500
#define ENV_FACTOR 5

using namespace std;

string displayGenFur(int gen, map<int, Creature> creatures);

int main(int argc, char **argv) {
	srand(time(0));

	XMLData* xml = XMLData::getInstance();
	xml->parseXML("parts/codes.xml");

	int nbInit = 50, counter = 0, gen = 1;
	map<int, Creature> creatures;

	if(argc > 1) {
		nbInit = stoi(argv[1]);
	}

	for(counter=0 ; counter<nbInit ; counter++) {
		DNA dna = createRandomDNA();
		Creature c(counter, dna);
		creatures.insert(pair<int, Creature>(counter, c));
	}

	cout << displayGenFur(gen, creatures);

	string command;

	/* Main loop */
	do {
		cout << "> ";
		cin >> command;
		if(command == "h" || command == "help") {
			cout << "Enter \"+\" followed by a number x to advance of x generations" << endl;
			cout << "Enter \"q\" or \"quit\" to quit the simulation" << endl;
		}
		else if(command.c_str()[0] == '+') {
			/* Number of generations to go further */
			int nbGen = stoi(command);
			for(int i=0 ; i<nbGen ; i++) {

				/* nextGen is the new map of creatues */
				map<int, Creature> nextGen;
				map<int, Creature>::iterator it;
				int j = 1, size = creatures.size();

				/* For each creature */
				for(it=creatures.begin() ; it != creatures.end() ; ++it, j++) {
					int id1 = it->first;
					Creature c1 = it->second;

					SkinStrand *skin1 = (SkinStrand*) c1.getDNA().getDNAStrand().at(0);
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

						SkinStrand *skin2 = (SkinStrand*) c2.getDNA().getDNAStrand().at(0);
						int deathBonus2;
						if(skin2->getHair() == "fur") {
							deathBonus2 = -ENV_FACTOR;
						}
						else {
							deathBonus2 = ENV_FACTOR;
						}

						DNA newDNA = mating(c1.getDNA(), c2.getDNA());
						Creature c(counter, newDNA);
						nextGen.insert(pair<int, Creature>(counter, c));
						counter++;

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
				creatures = nextGen;
				gen++;

				cout << displayGenFur(gen, creatures);
			}
		}
	} while(command != "quit" && command != "q");

	return 0;
}

string displayGenFur(int gen, map<int, Creature> creatures) {
	stringstream ss;

	ss << "Génération n°" << gen << " : " << creatures.size() << " créatures vivantes ";

	float nbFur = 0;
	for(auto const& x : creatures) {
		Creature c = x.second;
		SkinStrand *skin = (SkinStrand*) c.getDNA().getDNAStrand().at(0);
		if(skin->getHair() == "fur") {
			nbFur ++;
		}
	}
	float percentage = nbFur/creatures.size()*100;
	ss.precision(5);
	ss << "(" << percentage << " % have fur)" << endl;

	return ss.str();
}
