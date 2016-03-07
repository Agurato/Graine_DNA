#ifndef SIMWINDOW_H
#define SIMWINDOW_H

#include "sim/XMLData.hpp"
#include "sim/functions.hpp"
#include "DNA.hpp"
#include "Creature.hpp"

#include <ctime>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include <QMainWindow>

namespace Ui {
class SimWindow;
}

class SimWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimWindow(QWidget *parent = 0);
    ~SimWindow();

private:
    Ui::SimWindow *ui;
    std::map<int, Creature> creatures;
    int counter = 0, nbInit = 2000, gen = 1;
    std::vector<std::string> saveLines;

    void writeTable(int gen, std::string infos);

private slots:
    void advanceGen();
    void saveGen();
};

#endif // SIMWINDOW_H
