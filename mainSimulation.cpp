#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <map>
#include <ctime>
#include <iterator>
#include "sim/XMLData.hpp"
#include "sim/functions.hpp"
#include "DNA.hpp"
#include "Creature.hpp"

using namespace std;

string stdoutFromCommand(string cmd);
string displayGenFur(int gen, map<int, Creature> creatures);

int main(int argc, char **argv) {
	srand(time(0));

	XMLData* xml = XMLData::getInstance();
	xml->parseXML("sim/codes.xml");

	int nbInit = 1000, counter = 0, gen = 1;
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

		getline(cin, command);

		istringstream iss(command);
		vector<string> args{istream_iterator<string>{iss}, istream_iterator<string>{}};

		if(args.at(0) == "h" || args.at(0) == "help") {
			cout << "Enter \"+\" followed by a number x to advance of x generations" << endl;
			cout << "Enter \"save\" to save the simulation as a .csv file" << endl;
			cout << "Enter \"restart\" to restart the simulation. It can be followed by the number of creatures to start with" << endl;
			cout << "Enter \"h\" or \"help\" to print the help page" << endl;
			cout << "Enter \"q\" or \"quit\" to quit the simulation" << endl;
		}
		else if(args.at(0).c_str()[0] == '+') {
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
		else if(args.at(0) == "save") {
			if(args.size() > 1) {
				saveCsv(saveLines, args.at(1));
			}
			else {
				saveCsv(saveLines);
			}
		}
		else if(args.at(0) == "graph") {
			string file(stdoutFromCommand("ls -t | grep .csv | head -1"));
			file.pop_back();
			if(args.size() > 1) {
				file = args.at(1);
			}
			cout << "Opening " << file << endl;
			/* TODO : vérifier existence file + script python à lancer sous cette forme pour les here document

			system("cat > bonjour.txt <<EOF\n"
			"This is a here document\n"
			"being executed in system()\n"
			"EOF\n");

			*/
		}
		else if(args.at(0) == "restart") {
			xml->parseXML("sim/codes.xml");
			counter = 0;
			gen = 1;
			nbInit = 1000;

			if(args.size() > 1) {
				nbInit = stoi(args.at(1));
			}

			creatures.clear();
			saveLines.clear();

			for(counter=0 ; counter<nbInit ; counter++) {
				DNA dna = createRandomDNA();
				Creature c(counter, dna);
				creatures.insert(pair<int, Creature>(counter, c));
			}

			registerGen(gen, creatures, &saveLines);
			cout << displayGenFur(gen, creatures);
		}
	} while(command != "quit" && command != "q");

	return 0;
}

string stdoutFromCommand(string cmd) {
	string data;
	FILE * stream;
	const int max_buffer = 256;
	char buffer[max_buffer];
	cmd.append(" 2>&1");

	stream = popen(cmd.c_str(), "r");
	if (stream) {
		while (!feof(stream))
		if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		pclose(stream);
	}
	return data;
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
