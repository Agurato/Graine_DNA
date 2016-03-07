#include "simwindow.h"
#include "ui_simwindow.h"

#include <QAbstractItemView>
#include <QString>
#include <QTableWidgetItem>

using namespace std;

SimWindow::SimWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimWindow)
{
    ui->setupUi(this);
    connect(ui->advanceButton, SIGNAL(clicked()), this, SLOT(advanceGen()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveGen()));

    ui->nbGenSpinBox->setMinimum(1);
    ui->nbGenSpinBox->setMaximum(100000);

    ui->tableGen->verticalHeader()->hide();
    ui->tableGen->autoScrollMargin();

    for(counter=0 ; counter<nbInit ; counter++) {
        DNA dna;
        dna = createRandomDNA();
        Creature c(counter, dna);
        creatures.insert(pair<int, Creature>(counter, c));
    }

    registerGen(gen, creatures, &saveLines);
    writeTable(gen, saveLines.at(gen-1));
}

void SimWindow::advanceGen() {
    int nbGen = ui->nbGenSpinBox->value();

    for(int i=0 ; i<nbGen ; i++) {
        creatures = mateAndKill(creatures, &counter);

        gen++;
        registerGen(gen, creatures, &saveLines);
        writeTable(gen, saveLines.at(gen-1));
        ui->tableGen->scrollToBottom();
    }
}

void SimWindow::saveGen() {
    saveCsv(saveLines);
}

void SimWindow::writeTable(int gen, string infos) {
    stringstream ss(infos);
    string tok;
    int i = 0;
    ui->tableGen->insertRow(gen-1);

    while(std::getline(ss, tok, ' ')) {
        QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(tok));
        item->setTextAlignment(Qt::AlignHCenter | Qt::AlignCenter);
        ui->tableGen->setItem(gen-1, i, item);
        i++;
    }
}

SimWindow::~SimWindow()
{
    delete ui;
}
