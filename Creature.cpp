#include <cmath>
#include <ctime>

#include "Creature.hpp"
#include "../utils/utils.hpp"

Creature::Creature(int newid, DNA newdna) {
	id = newid;
	dna = newdna;
}

int Creature::getID() {
	return id;
}

DNA Creature::getDNA() {
	return dna;
}
