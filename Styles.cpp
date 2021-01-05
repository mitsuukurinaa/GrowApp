#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>


void MainWindow::SetStyles()
{
    QPixmap background(":/images/background.jpg");
    //background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    //palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    QPixmap HomePixmap("://images/HomeIco.png");
    QIcon HomeIcon(HomePixmap);
    ui->HomeTabButton->setIcon(HomeIcon);
    ui->HomeTabButton->setIconSize(HomePixmap.rect().size());

    QPixmap SettingsPixmap("://images/SettingsIco.png");
    QIcon SettingsIcon(SettingsPixmap);
    ui->SettingsTabButton->setIcon(SettingsIcon);
    ui->SettingsTabButton->setIconSize(SettingsPixmap.rect().size());

    QPixmap CashPixmap("://images/CashIco.png");
    QIcon CashIcon(CashPixmap);
    ui->CashTabButton->setIcon(CashIcon);
    ui->CashTabButton->setIconSize(CashPixmap.rect().size());

    //Translation
    QPixmap PolishPixmap("://images/PolandIco.png");
    QIcon PolishIco(PolishPixmap);

    QPixmap EnglishPixmap("://images/UsaIco.png");
    QIcon EnglishIco(EnglishPixmap);

    QPixmap GermanyPixmap("://images/GermanyIco.png");
    QIcon GermanyIco(GermanyPixmap);

    ui->languageBox->setItemIcon(0, PolishIco);
    ui->languageBox->setItemIcon(1,EnglishIco);
    ui->languageBox->setItemIcon(2, GermanyIco);
    ui->languageBox->setIconSize(PolishPixmap.rect().size());

    //Set app name
    QMainWindow::setWindowTitle("GrowApp 2020");

    //Tasks
    ui->SetTaskName1->setPlaceholderText("Wpisz nazwę swojego zadania");
    ui->SetTaskName2->setPlaceholderText("[opcjonalnie]");
    ui->SetTaskName3->setPlaceholderText("[opcjonalnie]");
    ui->SetTaskName4->setPlaceholderText("[opcjonalnie]");
    ui->SetTaskName5->setPlaceholderText("[opcjonalnie]");
}

