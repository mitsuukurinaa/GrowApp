#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::PrepareCheckboxes()
{
    if (CurrentDay != date.currentDate().toString())
    {

        if (!ui->Task1->isChecked() && isConfigDone==1)
        {
            Task1Failed++;
        }

        if (!ui->Task2->isChecked() && isConfigDone==1)
        {
            Task2Failed++;
        }

        if (!ui->Task3->isChecked() && isConfigDone==1)
        {
            Task3Failed++;
        }

        if (!ui->Task4->isChecked() && isConfigDone==1)
        {
            Task4Failed++;
        }

        if (!ui->Task5->isChecked() && isConfigDone==1)
        {
            Task5Failed++;
        }

        ui->Task1->setCheckState(Qt::Unchecked);
        ui->Task1->setEnabled(true);
        ui->Task2->setCheckState(Qt::Unchecked);
        ui->Task2->setEnabled(true);
        ui->Task3->setCheckState(Qt::Unchecked);
        ui->Task3->setEnabled(true);
        ui->Task4->setCheckState(Qt::Unchecked);
        ui->Task4->setEnabled(true);
        ui->Task5->setCheckState(Qt::Unchecked);
        ui->Task5->setEnabled(true);

        qDebug() << "WYKONANO";
    }
    CurrentDay = date.currentDate().toString();\
    ui->CurrentDateLabel->setText(QString::number(date.currentDate().day()) +
                                  "." + QString::number(date.currentDate().month()) + "." + QString::number(date.currentDate().year()));
    Save();

}

void MainWindow::on_Task1_clicked()
{
    Task1Done++;
   // ui->Task1->setEnabled(false);
    CollectReward();
}

void MainWindow::on_Task2_clicked()
{
    Task2Done++;
    ui->Task2->setEnabled(false);
    CollectReward();
}

void MainWindow::on_Task3_clicked()
{
    Task3Done++;
    ui->Task3->setEnabled(false);
    CollectReward();
}

void MainWindow::on_Task4_clicked()
{
    Task4Done++;
    ui->Task4->setEnabled(false);
    CollectReward();
}

void MainWindow::on_Task5_clicked()
{
    Task5Done++;
    ui->Task5->setEnabled(false);
    CollectReward();
}

