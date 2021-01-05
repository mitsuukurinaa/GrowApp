#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QCheckBox"
#include "QDate"
#include "QSettings"
#include "QFile"
#include "QFileDialog"
#include "QStandardPaths"
#include "QStyle"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Load all settings
    Settings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Settings()
{
    //Load save data
    Load();

    //Set all stylesheets
    SetStyles();

    //Connections and Signals
    CreateConnections();

    //Running config page or skip it if already created
    FirstAppRun();

    //This function changing checkboxes from Qt::Checked to Qt::Unchecked when a new day
    PrepareCheckboxes();

    //Update all labels
    UpdateData();
}

void MainWindow::CreateConnections()
{
    connect(ui->languageBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectLanguage()));

}

void MainWindow::UpdateData()
{
    QString str;
    ui->ShowTotalEuro->setText(str.asprintf("%.1f", Euro) + " €");
    ui->showEarnLabel->setText(str.asprintf("%.1f", EuroGeneral) + " €");

    ui->Task1Done->setText(QString::number(Task1Done));
    ui->Task1Level->setText(QString::number(Task1Level));
    ui->Task1Failed->setText(QString::number(Task1Failed));

    ui->Task2Done->setText(QString::number(Task2Done));
    ui->Task2Level->setText(QString::number(Task2Level));
    ui->Task2Failed->setText(QString::number(Task2Failed));

    ui->Task3Done->setText(QString::number(Task3Done));
    ui->Task3Level->setText(QString::number(Task3Level));
    ui->Task3Failed->setText(QString::number(Task3Failed));

    ui->Task4Done->setText(QString::number(Task4Done));
    ui->Task4Level->setText(QString::number(Task4Level));
    ui->Task4Failed->setText(QString::number(Task4Failed));

    ui->Task5Done->setText(QString::number(Task5Done));
    ui->Task5Level->setText(QString::number(Task5Level));
    ui->Task5Failed->setText(QString::number(Task5Failed));


    if (Task1Done == Exp1)
    {
        Exp1+=5;
        Task1Level++;
        UpdateData();
    }

    if (Task2Done == Exp2)
    {
        Exp2+=5;
        Task2Level++;
        UpdateData();
    }

    if (Task3Done >= Exp3)
    {
        Exp3+=5;
        Task3Level++;
        UpdateData();
    }

    if (Task4Done >= Exp4)
    {
        Exp4+=5;
        Task4Level++;
        UpdateData();
    }

    if (Task5Done >= Exp5)
    {
        Exp5+=5;
        Task5Level++;
        UpdateData();
    }

    Save();
}

void MainWindow::MessageBoxes()
{
    SelectLanguage();

    confirm = QMessageBox::warning(this,ConfirmTitle, ConfirmMessage, QMessageBox::Yes | QMessageBox::Cancel);

}

void MainWindow::CollectReward()
{
    Euro+=CurrentEuro;
    EuroGeneral+=CurrentEuro;
    UpdateData();
}

void MainWindow::FirstAppRun()
{
    if (isConfigDone==1)
    {
        ui->PageWidget->setCurrentIndex(0);
    }
    else
    {

        ui->PageWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_DoneConfigButton_clicked()
{
    ui->Task1->setText(ui->SetTaskName1->text());
    ui->Task1->show();

    if(ui->SetTaskName2->text() != "")
    {
        ui->Task2->setText(ui->SetTaskName2->text());
        ui->Task2->show();
    }
    else
    {
        ui->Task2->hide();
        ui->Task2Level->hide();
        ui->Task2Done->hide();
        ui->Task2Failed->hide();
        ui->label4->hide();
        ui->label5->hide();
        ui->label6->hide();
    }

    if(ui->SetTaskName3->text() != "")
    {
        ui->Task3->setText(ui->SetTaskName3->text());
        ui->Task3->show();
    }
    else
        ui->Task3->hide();
    ui->Task3Level->hide();
    ui->Task3Done->hide();
    ui->Task3Failed->hide();
    ui->label7->hide();
    ui->label8->hide();
    ui->label9->hide();

    if(ui->SetTaskName4->text() != "")
    {
        ui->Task4->setText(ui->SetTaskName4->text());
        ui->Task4->show();
    }
    else
    {
        ui->Task4->hide();
        ui->Task4Level->hide();
        ui->Task4Done->hide();
        ui->Task4Failed->hide();
        ui->label10->hide();
        ui->label11->hide();
        ui->label12->hide();
    }

    if(ui->SetTaskName5->text() != ""){
        ui->Task5->setText(ui->SetTaskName5->text());
        ui->Task5->show();
    }
    else
    {
        ui->Task5->hide();
        ui->Task5Level->hide();
        ui->Task5Done->hide();
        ui->Task5Failed->hide();
        ui->label13->hide();
        ui->label14->hide();
        ui->label15->hide();
    }


    ui->PageWidget->setCurrentIndex(0);
    isConfigDone = 1;
    Save();
}
void MainWindow::on_SettingsTabButton_clicked()
{
    ui->PageWidget->setCurrentIndex(3);
}

void MainWindow::on_HomeTabButton_clicked()
{
    ui->PageWidget->setCurrentIndex(0);
}

void MainWindow::on_CashTabButton_clicked()
{
    ui->PageWidget->setCurrentIndex(2);
    LoadPayout();
}

void MainWindow::on_PayoutButton_clicked()
{
    QString SPLstring = date.currentDate().toString("dd.MM.yyyy") + "    " + QString::number(Euro) + "€";

    ui->showpayoutLabel->setText(SPLstring);
    EuroPayout += Euro;
    Euro = 0.0;
    UpdateData();
    Save();
    SavePayout(SPLstring);

}

void MainWindow::on_EuroSpinBox_valueChanged()
{
    CurrentEuro = ui->EuroSpinBox->value();
}

void MainWindow::on_ChangeEuroButton_clicked()
{
    on_EuroSpinBox_valueChanged();
}
