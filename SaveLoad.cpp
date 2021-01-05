#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QStandardPaths"

void MainWindow::Save()
{
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/GrowAppSave.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        qDebug() << "SAVED";

        stream << CurrentDay << "\n";
        stream << isConfigDone <<"\n";
        stream << Euro << "\n";
        stream << EuroGeneral <<"\n";

        stream << ui->Task1->text() <<"\n";
        stream << ui->Task1->isEnabled() <<"\n";
        stream << ui->Task1->isChecked() <<"\n";
        stream << ui->Task1Level->text() <<"\n";
        stream << ui->Task1Done->text() <<"\n";
        stream << ui->Task1Failed->text() <<"\n";

        stream << ui->Task2->text() <<"\n";
        stream << ui->Task2->isEnabled() <<"\n";
        stream << ui->Task2->isChecked() <<"\n";
        stream << ui->Task2Level->text() <<"\n";
        stream << ui->Task2Done->text() <<"\n";
        stream << ui->Task2Failed->text() <<"\n";

        stream << ui->Task3->text() <<"\n";
        stream << ui->Task3->isEnabled() <<"\n";
        stream << ui->Task3->isChecked() <<"\n";
        stream << ui->Task3Level->text() <<"\n";
        stream << ui->Task3Done->text() <<"\n";
        stream << ui->Task3Failed->text() <<"\n";

        stream << ui->Task4->text() <<"\n";
        stream << ui->Task4->isEnabled() <<"\n";
        stream << ui->Task4->isChecked() <<"\n";
        stream << ui->Task4Level->text() <<"\n";
        stream << ui->Task4Done->text() <<"\n";
        stream << ui->Task4Failed->text() <<"\n";

        stream << ui->Task5->text() <<"\n";
        stream << ui->Task5->isEnabled() <<"\n";
        stream << ui->Task5->isChecked() <<"\n";
        stream << ui->Task5Level->text() <<"\n";
        stream << ui->Task5Done->text() <<"\n";
        stream << ui->Task5Failed->text() <<"\n";

        stream << ui->Task2->isHidden() << "\n";
        stream << ui->Task2Level->isHidden()<< "\n";
        stream << ui->Task2Done->isHidden()<< "\n";
        stream << ui->Task2Failed->isHidden()<< "\n";
        stream << ui->label4->isHidden()<< "\n";
        stream << ui->label5->isHidden()<< "\n";
        stream << ui->label6->isHidden()<< "\n";

        stream << ui->Task3->isHidden() << "\n";
        stream << ui->Task3Level->isHidden()<< "\n";
        stream << ui->Task3Done->isHidden()<< "\n";
        stream << ui->Task3Failed->isHidden()<< "\n";
        stream << ui->label7->isHidden()<< "\n";
        stream << ui->label8->isHidden()<< "\n";
        stream << ui->label9->isHidden()<< "\n";

        stream << ui->Task4->isHidden() << "\n";
        stream << ui->Task4Level->isHidden()<< "\n";
        stream << ui->Task4Done->isHidden()<< "\n";
        stream << ui->Task4Failed->isHidden()<< "\n";
        stream << ui->label10->isHidden()<< "\n";
        stream << ui->label11->isHidden()<< "\n";
        stream << ui->label12->isHidden()<< "\n";

        stream << ui->Task5->isHidden() << "\n";
        stream << ui->Task5Level->isHidden()<< "\n";
        stream << ui->Task5Done->isHidden()<< "\n";
        stream << ui->Task5Failed->isHidden()<< "\n";
        stream << ui->label13->isHidden()<< "\n";
        stream << ui->label14->isHidden()<< "\n";
        stream << ui->label15->isHidden()<< "\n";
    }
}
void MainWindow::Load()
{

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/GrowAppSave.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        //   in.setCodec("UTF-8");

        CurrentDay = in.readLine();
        isConfigDone = in.readLine().toInt();
        Euro= in.readLine().toDouble();
        EuroGeneral = in.readLine().toDouble();

        ui->Task1->setText(in.readLine());
        ui->Task1->setEnabled(in.readLine().toInt());
        int checked = in.readLine().toInt();
        ui->Task1->setCheckState(checked ? Qt::Checked : Qt::Unchecked);
        ui->Task1Level->setText(in.readLine());
        Task1Done = in.readLine().toShort();
        Task1Failed = in.readLine().toShort();

        ui->Task2->setText(in.readLine());
        ui->Task2->setEnabled(in.readLine().toInt());
        checked = in.readLine().toInt();
        ui->Task2->setCheckState(checked ? Qt::Checked : Qt::Unchecked);
        ui->Task2Level->setText(in.readLine());
        Task2Done = in.readLine().toShort();
        Task2Failed = in.readLine().toShort();

        ui->Task3->setText(in.readLine());
        ui->Task3->setEnabled(in.readLine().toInt());
        checked = in.readLine().toInt();
        ui->Task3->setCheckState(checked ? Qt::Checked : Qt::Unchecked);
        ui->Task3Level->setText(in.readLine());
        Task3Done = in.readLine().toShort();
        Task3Failed = in.readLine().toShort();

        ui->Task4->setText(in.readLine());
        ui->Task4->setEnabled(in.readLine().toInt());
        checked = in.readLine().toInt();
        ui->Task4->setCheckState(checked ? Qt::Checked : Qt::Unchecked);
        ui->Task4Level->setText(in.readLine());
        Task4Done = in.readLine().toShort();
        Task4Failed = in.readLine().toShort();

        ui->Task5->setText(in.readLine());
        ui->Task5->setEnabled(in.readLine().toInt());
        checked = in.readLine().toInt();
        ui->Task5->setCheckState(checked ? Qt::Checked : Qt::Unchecked);
        ui->Task5Level->setText(in.readLine());
        Task5Done = in.readLine().toShort();
        Task5Failed = in.readLine().toShort();

        ui->Task2->setHidden(in.readLine().toInt());
        ui->Task2Level->setHidden(in.readLine().toInt());
        ui->Task2Done->setHidden(in.readLine().toInt());
        ui->Task2Failed->setHidden(in.readLine().toInt());
        ui->label4->setHidden(in.readLine().toInt());
        ui->label5->setHidden(in.readLine().toInt());
        ui->label6->setHidden(in.readLine().toInt());

        ui->Task3->setHidden(in.readLine().toInt());
        ui->Task3Level->setHidden(in.readLine().toInt());
        ui->Task3Done->setHidden(in.readLine().toInt());
        ui->Task3Failed->setHidden(in.readLine().toInt());
        ui->label7->setHidden(in.readLine().toInt());
        ui->label8->setHidden(in.readLine().toInt());
        ui->label9->setHidden(in.readLine().toInt());

        ui->Task4->setHidden(in.readLine().toInt());
        ui->Task4Level->setHidden(in.readLine().toInt());
        ui->Task4Done->setHidden(in.readLine().toInt());
        ui->Task4Failed->setHidden(in.readLine().toInt());
        ui->label10->setHidden(in.readLine().toInt());
        ui->label11->setHidden(in.readLine().toInt());
        ui->label12->setHidden(in.readLine().toInt());

        ui->Task5->setHidden(in.readLine().toInt());
        ui->Task5Level->setHidden(in.readLine().toInt());
        ui->Task5Done->setHidden(in.readLine().toInt());
        ui->Task5Failed->setHidden(in.readLine().toInt());
        ui->label13->setHidden(in.readLine().toInt());
        ui->label14->setHidden(in.readLine().toInt());
        ui->label15->setHidden(in.readLine().toInt());

        file.close();
    }
    UpdateData();
}

void MainWindow::SavePayout(QString saveString)
{
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/PayoutSave.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        QTextStream out(&file);
        out<<saveString<<"\n";
    }

    file.close();
}

void MainWindow::LoadPayout()
{
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/PayoutSave.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QTextStream in(&file);
        QString lastPayout;

        while(!in.atEnd()){
            lastPayout = in.readLine();
        }

        ui->showpayoutLabel->setText(lastPayout);
    }

    file.close();
}
