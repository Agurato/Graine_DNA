#include "fencalc.h"
#include "ui_fencalc.h"

FenCalc::FenCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FenCalc)
{
    ui->setupUi(this);connect(ui->equalsButton, SIGNAL(clicked()), this, SLOT(calculate()));
}

void FenCalc::calculate() {
    int result = 0;
    if(ui->operations->currentText().toStdString() == "+") {
        result = ui->num1->value() + ui->num2->value();
    }
    else if(ui->operations->currentText().toStdString() == "-") {
        result = ui->num1->value() - ui->num2->value();
    }
    else if(ui->operations->currentText().toStdString() == "*") {
        result = ui->num1->value() * ui->num2->value();
    }
    else if(ui->operations->currentText().toStdString() == "/") {
        result = ui->num1->value() / ui->num2->value();
    }
    else if(ui->operations->currentText().toStdString() == "%") {
        result = ui->num1->value() % ui->num2->value();
    }
    else {
        result = 0;
    }

    ui->result->setText(QString::number(result));
}

FenCalc::~FenCalc()
{
    delete ui;
}
