#include "simwindow.h"
#include "sim/XMLData.hpp"
#include "sim/functions.hpp"
#include "DNA.hpp"
#include "Creature.hpp"
#include <ctime>
#include <sstream>
#include <QApplication>
#include <map>
#include <vector>

using namespace std;

string displayGenFur(int gen, map<int, Creature> creatures);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(0));

    DNA dna = createRandomDNA();
    SkinStrand* skin = (SkinStrand*) dna.getDNAStrand().find("skin")->second;
    cout << skin->getHair() << endl;

    SimWindow w;
    w.show();

    return a.exec();
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
