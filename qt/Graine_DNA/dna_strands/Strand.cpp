#include "Strand.hpp"

using namespace std;

string Strand::getStrandType() {
	return "Strand";
}

string Strand::toString() {
	return "Strand\n";
}

string Strand::toString(string name) {
	return name+"\n";
}
