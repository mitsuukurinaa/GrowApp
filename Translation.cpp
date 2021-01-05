#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::SelectLanguage()
{

    if(ui->languageBox->currentIndex() == 0)
    {
        language = Polish;
    }
    if(ui->languageBox->currentIndex() == 1)
    {
        language = English;
    }
    if(ui->languageBox->currentIndex() ==2)
    {
        language = Germany;
    }
    switch(language)
    {
    case Polish:
    {

        ui->payoutLabel->setText("Ostatnia wypłata:");
        ui->earnLabel->setText("Zarobione €:");
        ConfirmTitle = "Potwierdzić?";
        ConfirmMessage = "Na pewno chcesz ukończyć zadanie?";
        AlertTitle = "Błąd!";
        AlertMessage = "Wybierz zadanie!";
        TaskAlertTitle = "Błąd";
        TaskAlertMessage = "Nazwa zadania nie może być pusta!";

        break;
    }
    case English :
    {
        ui->payoutLabel->setText("Latest payout");
        ui->earnLabel->setText("Earned €:");
        ConfirmTitle = "Confirm?";
        ConfirmMessage = "Are you sure to done this task?";
        AlertTitle = "Warning!";
        AlertMessage = "Select a task!";
        TaskAlertTitle = "Warning!";
        TaskAlertMessage = "You need to name your task!";

        break;
    }
    case Germany :
    {
        ui->payoutLabel->setText("Letzter Lohn:");
        ui->earnLabel->setText("Verdienen €:");
        ConfirmTitle = "Sicher?";
        ConfirmMessage = "Möchten Sie diese Aufgabe als fertig machen?";
        AlertTitle = "Fehler!";
        AlertMessage = "Wählen Sie eine Aufgabe aus!";
        TaskAlertTitle = "Felher";
        TaskAlertMessage = "Sie müssen Ihrer Aufgabe einen Namen geben!";

        break;
    }
    }
}
