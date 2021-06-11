#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "buildcomputer.h"
#include "gpu.h"
#include "database.h"
#include <QString>
using namespace std;

MainWindow::MainWindow(Database database, QWidget *parent)

    : database(database),QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::gpuUpdate()
{
    if(ui->RTX3070Button->isChecked()) {
        ui->ChosenGpu->setText("RTX3070");
    }
    if(ui->RTX2070Button->isChecked()) {
        ui->ChosenGpu->setText("RTX2070");
    }
    if(ui->RX5600Button->isChecked()) {
        ui->ChosenGpu->setText("RX5600-XT");
    }
}

void MainWindow::cpuUpdate()
{
    if(ui->I78700kButton->isChecked()) {
        ui->ChosenCpu->setText("i7-8700k");
    }
    if(ui->Ryzen7Button->isChecked()) {
        ui->ChosenCpu->setText("Ryzen5800x");
    }
}

void MainWindow::ramUpdate()
{
    if(ui->ramButton1->isChecked()) {
        ui->ChosenRAM->setText("16GB");
    }
    if(ui->ramButton2->isChecked()) {
        ui->ChosenRAM->setText("32GB");
    }
}

void MainWindow::psUpdate()
{
    if(ui->EVGA450WButton->isChecked()) {
        ui->ChosenPS->setText("450 Watts");
    }
    if(ui->EVGA550WButton->isChecked()) {
        ui->ChosenPS->setText("550 Watts");
    }
    if(ui->Corsair600WButton->isChecked()) {
        ui->ChosenPS->setText("600 Watts");
    }
    if(ui->GAMEMAX800WButton->isChecked()) {
        ui->ChosenPS->setText("800 Watts");
    }
}


void MainWindow::compCaseUpdate()
{
    if(ui->LowRangeCaseButton->isChecked()) {
        ui->ChosenCase->setText("Low Range");
    }
    if(ui->MidRangeCaseButton->isChecked()) {
        ui->ChosenCase->setText("Mid Range");
    }
    if(ui->HighRangeCaseButton->isChecked()) {
        ui->ChosenCase->setText("High Range");
    }
}

void MainWindow::totalClicked()
{
    bool finish = false;
    int endTotal = 0;

    while (finish == false) {

        QString gpu = ui->ChosenGpu->text();
        QString cpu = ui->ChosenCpu->text();
        QString ram = ui->ChosenRAM->text();
        QString powersupply = ui->ChosenPS->text();
        QString compcase = ui->ChosenCase->text();

        if (gpu == "") {
            ui->ChosenGpu->setText("Please enter a choice");
        }

        if (cpu == "") {
            ui->ChosenCpu->setText("Please enter a choice");
        }

        if (ram == "") {
            ui->ChosenRAM->setText("Please enter a choice");
        }

        if (powersupply == "") {
            ui->ChosenPS->setText("Please enter a choice");
        }

        if (compcase == "") {
            ui->ChosenCase->setText("Please enter a choice");
        }

        endTotal = database.getCpuPrice(cpu).toInt();
        endTotal += database.getGpuPrice(gpu).toInt();
        endTotal += database.getRamPrice(ram).toInt();
        endTotal += database.getPowSupplyPrice(powersupply).toInt();
        endTotal += database.getCasePrice(compcase).toInt();

        finish = true;
        ui->EndPrice->setText("Price: $" + QString::number(endTotal));
    }




}
