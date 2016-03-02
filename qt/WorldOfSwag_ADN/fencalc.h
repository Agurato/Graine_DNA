#ifndef FENCALC_H
#define FENCALC_H

#include <QMainWindow>

namespace Ui {
class FenCalc;
}

class FenCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit FenCalc(QWidget *parent = 0);
    ~FenCalc();

private:
    Ui::FenCalc *ui;

private slots:
    void calculate();
};

#endif // FENCALC_H
