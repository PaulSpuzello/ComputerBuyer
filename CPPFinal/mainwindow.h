#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QRadioButton>
#include <QGraphicsRectItem>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    MainWindow(Database database, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void gpuUpdate();
    void cpuUpdate();
    void ramUpdate();
    void psUpdate();
    void compCaseUpdate();
    void totalClicked();

private:
    Database database;
    Ui::MainWindow *ui;
    void updateValues(QLineEdit* edit, QRadioButton* radiobutton);
    void updateProduct();
};
#endif // MAINWINDOW_H
