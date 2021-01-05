#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QDate"
#include "QMap"
#include "QDebug"
#include <QLocale>
#include "QListWidget"
#include <QPushButton>
#include "QSignalMapper"
#include "QLabel"
#include "QVBoxLayout"
#include "task.h"
#include "QMessageBox"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //Basic functions
    void UpdateData();
    void Settings();
    void Save();
    void Load();
    void SetStyles();
    void SelectLanguage();
    void MessageBoxes();
    void CollectReward();
    void PrepareCheckboxes();
    void FirstAppRun();
    void CreateConnections();


    //Payout
    void SavePayout(QString);
    void LoadPayout();


    //Buttons
    void on_DoneConfigButton_clicked();
    void on_SettingsTabButton_clicked();
    void on_HomeTabButton_clicked();
    void on_CashTabButton_clicked();
    void on_PayoutButton_clicked();

    //Tasks Checboxes
    void on_Task1_clicked();
    void on_Task2_clicked();
    void on_Task3_clicked();
    void on_Task4_clicked();
    void on_Task5_clicked();

    //To setup a new value for reward
    void on_EuroSpinBox_valueChanged();
    void on_ChangeEuroButton_clicked();

private:
    Ui::MainWindow *ui;

    //Basic variables
    double Euro = 0.0;
    double EuroPayout = 0.0;
    double EuroGeneral = 0.0;
    double CurrentEuro = 0.5;
    signed short int CompleteTasks = 0;
    signed short int NotCompleteTasks= 0;

    QString CurrentDay;
    short int isConfigDone;
    QDate date;

    //Tasks
    short int Task1Level = 1, Task1Done = 0, Task1Failed = 0, Exp1 = 5;
    short int Task2Level = 1, Task2Done = 0, Task2Failed = 0, Exp2 = 5;
    short int Task3Level = 1, Task3Done = 0, Task3Failed = 0, Exp3 = 5;
    short int Task4Level = 1, Task4Done = 0, Task4Failed = 0, Exp4 = 5;
    short int Task5Level = 1, Task5Done = 0, Task5Failed = 0, Exp5 = 5;

    //Translation
    enum Language { Polish, English, Germany } language = Polish;

    //Message boxes
    QMessageBox::StandardButton confirm;
    QString ConfirmTitle, ConfirmMessage;
    QString AlertTitle, AlertMessage;
    QString TaskAlertTitle, TaskAlertMessage;
};
#endif // MAINWINDOW_H
