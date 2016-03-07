#include "simwindow.h"
#include "ui_simwindow.h"
#include "sim/XMLData.hpp"
#include "sim/functions.hpp"
#include "DNA.hpp"
#include "Creature.hpp"
#include <ctime>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

SimWindow::SimWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimWindow)
{
    ui->setupUi(this);
    connect(ui->advanceButton, SIGNAL(clicked()), this, SLOT(advanceGen()));
    /*
    int counter = 0, nbInit = 100, gen = 1;
    map<int, Creature> creatures;
    DNA dna = createRandomDNA();
    SkinStrand* skin = (SkinStrand*) dna.getDNAStrand().find("skin")->second;
    cout << skin->getHair() << endl;

    for(counter=0 ; counter<nbInit ; counter++) {
        DNA dna;
        dna = createRandomDNA();
        Creature c(counter, dna);
        creatures.insert(pair<int, Creature>(counter, c));
    }

    vector<string> saveLines;

    registerGen(gen, creatures, &saveLines);
    */
    //cout << displayGenFur(gen, creatures);
}

void SimWindow::advanceGen() {
    //int nbGen = ui->nbGenSpinBox->value();
}

SimWindow::~SimWindow()
{
    delete ui;
}
