
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPair"
void MainWindow::CreateLabels()
{
    int x = 10, y = 10;
    for (int i = 0; i < 7; i++) {
        if(language == Polish)
        {
            lbl[i] = new QLabel(polishName[i], ui->groupBox);
        }
        else if(language == English)
        {
            lbl[i] = new QLabel(englishName[i], ui->groupBox);
        }

        else if(language == Germany)
        {
            lbl[i] = new QLabel(germanyName[i], ui->groupBox);
        }
        lbl[i]->resize(50, 30);
        lbl[i]->move(x, y);
        lbl[i]->setStyleSheet("color: #C8C8C8; font:87 18pt Bahnschrift;");
        lbl[i]->show();
        lbl[i]->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        x += 66;
    }
}

void MainWindow::config()
{
    QDate *foo = new QDate(Y, M, 1);

    switch(foo->dayOfWeek())
    {
    case 1:
        setNumber(0);
        break;

    case 2:
        setNumber(1);
        break;
    case 3:
        setNumber(2);
        break;
    case 4:
        setNumber(3);
        break;
    case 5:
        setNumber(4);
        break;
    case 6:
        setNumber(5);
        break;
    case 7:
        setNumber(6);
        break;

    default:
        break;
    }
    delete foo;
}
void MainWindow::createButtons()
{
    int x = 12, y = 50;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){

            btn[i][j] = new QPushButton("", ui->groupBox);
            btn[i][j]->resize(45,45);
            btn[i][j]->move(x,y);
            btn[i][j]->show();
            btn[i][j]->setEnabled(true);
            connect(btn[i][j], &QPushButton::clicked, this, [=]{ QString b = btn[i][j]->text(); GetClickedDay(b); });
            x += 66;
        }
        y+=60;
        x = 12;
    }
}

void MainWindow::setNumber(int day)
{
    int count = 1;
    int countafter = 1, countbefore = prevdate->daysInMonth();

    D = date.daysInMonth();

    countbefore -= day - 1;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {

            if((j >= day) && (i == 0)){
                btn[0][j]->setText(QString::number(count++));
                btn[0][j]->setStyleSheet(normalday);
            }

            else if((j < day) && (i == 0)){
                btn[0][j]->setStyleSheet(otherday);
                btn[0][j]->setText(QString::number(countbefore++));
                btn[0][j]->setEnabled(false);
            }

            else if(i > 0){
                btn[i][j]->setText(QString::number(count++));
                btn[i][j]->setStyleSheet(normalday);
            }

            if(TodaysDay == count-1 && Month == M && Year == Y){
                btn[i][j]->setStyleSheet(currentday);
            }

            if(count-1 > D){
                btn[i][j]->setStyleSheet(otherday);
                btn[i][j]->setText(QString::number(countafter++));
                btn[i][j]->setEnabled(false);
            }

            if(!btn[i][j]->isEnabled())
                btn[i][j]->setStyleSheet(otherday);

        }
    }
    ui->lbldate2->setText(QString::number(date.month())+ " / " + QString::number(date.year()));
    ui->lbldate2->setStyleSheet("color: #C8C8C8; font:87 22pt Bahnschrift;");
}

void MainWindow::on_prevmonth_clicked()
{
    prevdate->setDate(Y,M,1);

    M -= 1;
    if(M == 0){
        M = 12;
        Y -= 1;
    }
    date.setDate(Y,M,1);
    D = date.daysInMonth();

    if(M == 1)
        prevdate->setDate(Y-1, 12,1);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            btn[i][j]->setEnabled(true);
        }
    }
    config();
}

void MainWindow::on_nextmonth_clicked()
{
    prevdate->setDate(Y,M,1);

    M += 1;
    if(M == 13){
        M = 1;
        Y += 1;
    }
    date.setDate(Y,M,1);
    D = date.daysInMonth();

    if(M == 1)
        prevdate->setDate(Y, 12,1);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            btn[i][j]->setEnabled(true);
        }
    }
    config();
}

void MainWindow::GetClickedDay(QString get)
{
    QString month = QString::number(date.month());

    if(month.length() == 1){
        month = "0" + month;
    }

    if(get.length() == 1){
        get = "0" + get;
    }
    nametodisplay = get + "." + month + "." + QString::number(date.year());

    ui->dailyTaskLabel2->setText(nametodisplay);

    ui->dailyTasksWidget->clear();

    for(auto key: DailyTaskMap.keys())
    {
        if(key == nametodisplay)
        {
            ui->dailyTasksWidget->clear();

            for(auto task : DailyTaskMap.values(key))
            {
                ui->dailyTasksWidget->addItem(task);
            }
        }
    }
    ListWidgetSettings();
    ui->stackedWidget->setCurrentIndex(0);
    ui->dailyEditButton->show();

notify.show();

}
