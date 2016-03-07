#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <ctime>
#include "sim/XMLData.hpp"
#include "sim/functions.hpp"
#include "DNA.hpp"
#include "Creature.hpp"

using namespace std;

string displayGenFur(int gen, map<int, Creature> creatures);

int main(int argc, char **argv) {
	srand(time(0));

	XMLData* xml = XMLData::getInstance();
	xml->parseXML("sim/codes.xml");

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

	vector<string> saveLines;

	registerGen(gen, creatures, &saveLines);
	cout << displayGenFur(gen, creatures);

	string command;

	/* Main loop */
	do {
		cout << "> ";
		cin >> command;
		if(command == "h" || command == "help") {
			cout << "Enter \"+\" followed by a number x to advance of x generations" << endl;
			cout << "Enter \"save\" to save the simulation as a .csv file" << endl;
			cout << "Enter \"h\" or \"help\" to print the help page" << endl;
			cout << "Enter \"q\" or \"quit\" to quit the simulation" << endl;
		}
		else if(command.c_str()[0] == '+') {
			/* Number of generations to go further */
			int nbGen = stoi(command);
			for(int i=0 ; i<nbGen ; i++) {

				/* nextGen is the new map of creatues */
				creatures = mateAndKill(creatures, &counter);

				gen++;
				registerGen(gen, creatures, &saveLines);
				cout << displayGenFur(gen, creatures);
			}
		}
		else if(command == "save") {
			saveCsv(saveLines);
		}
	} while(command != "quit" && command != "q");

	return 0;
}

string displayGenFur(int gen, map<int, Creature> creatures) {
	stringstream ss, save;
	ss.precision(5);
	save.precision(5);

	ss << "Génération n°" << gen << " : " << creatures.size() << " créatures vivantes ";

	float nbFur = 0;
	for(auto const& x : creatures) {
		Creature c = x.second;
		SkinStrand *skin = (SkinStrand*) c.getDNA().getDNAStrand().find("skin")->second;
		if(skin->getHair() == "fur") {
			nbFur ++;
		}
	}
	float percentage = nbFur/creatures.size()*100;
	ss << "(" << percentage << " % have fur)" << endl;

	save << gen << " " << creatures.size() << " " << nbFur << " " << percentage << endl;

	return ss.str();
}
