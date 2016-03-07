#include "simwindow.h"
#include "sim/XMLData.hpp"
#include "sim/functions.hpp"
#include "DNA.hpp"
#include "Creature.hpp"

#include <ctime>
#include <map>
#include <sstream>
#include <vector>

#include <QApplication>
#include <QFile>
#include <QFileInfo>

using namespace std;

string displayGenFur(int gen, map<int, Creature> creatures);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    srand(time(0));

    XMLData* xml = XMLData::getInstance();
    xml->parseXML("../Graine_DNA/sim/codes.xml");

    SimWindow w;

    w.show();

    return a.exec();
}
