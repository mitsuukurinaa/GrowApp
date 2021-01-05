#include "calendar.h"
#include "ui_calendar.h"

calendar::calendar(QWidget *parent) :
    QMainWindow(parent , Qt::FramelessWindowHint),
    ui(new Ui::calendar)
{
    ui->setupUi(this);
    prevdate = new QDate(Y, M-1,1);
    setUpLblDate();
    createButtons();
    config();
}

calendar::~calendar()
{
    delete ui;
}


void calendar::config()
{

    QDate *foo = new QDate(Y, M, 1);

    switch(foo->dayOfWeek())
    {
    case 1:
       setNumber(1);
    break;

    case 2:
       setNumber(2);
    break;
    case 3:
       setNumber(3);
    break;
    case 4:
       setNumber(4);
    break;
    case 5:
       setNumber(5);
        break;
    case 6:
       setNumber(6);
    break;
    case 7:
       setNumber(7);
    break;

    default:
        break;
    }

delete foo;
}

void calendar::setUpLblDate()
{
    QString * foo = new QString;
    *foo = locale.toString(QDate::currentDate());
    ui->uplbl->setText(*foo);
    delete foo;
}


void calendar::createButtons()
{

    int x = 10, y = 90;


        for(int j = 0; j < 7; j++){

            le[j] = new QPushButton("", this);
            le[j]->resize(30,30);
            le[j]->move(x,y);
            le[j]->show();
            x += 46;

        }
        y+=46;
        x = 10;
        for(int j = 0; j < 7; j++){

            le2[j] = new QPushButton("", this);
            le2[j]->resize(30,30);
            le2[j]->move(x,y);
            le2[j]->show();
            x += 46;

        }
        y+=46;
        x = 10;
        for(int j = 0; j < 7; j++){

            le3[j] = new QPushButton("", this);
            le3[j]->resize(30,30);
            le3[j]->move(x,y);
            le3[j]->show();
            x += 46;

        }
        y+=46;
        x = 10;
        for(int j = 0; j < 7; j++){

            le4[j] = new QPushButton("", this);
            le4[j]->resize(30,30);
            le4[j]->move(x,y);
            le4[j]->show();
            x += 46;

        }
        y+=46;
        x = 10;
        for(int j = 0; j < 7; j++){

            le5[j] = new QPushButton("", this);
            le5[j]->resize(30,30);
            le5[j]->move(x,y);
            le5[j]->show();
            x += 46;
        }
        y+=46;
        x = 10;
        for(int j = 0; j < 7; j++){

            le6[j] = new QPushButton("", this);
            le6[j]->resize(30,30);
            le6[j]->move(x,y);
            le6[j]->show();
            x += 46;

        }
}



void calendar::setNumber(int a)
{

    int i, count = 1;
    int countafter = 1, countbefore = prevdate->daysInMonth();

   switch(a){
   case 1:
       i=0;
   break;
   case 2:
       i=1;
   break;
   case 3:
       i=2;
   break;
   case 4:
       i=3;
   break;
   case 5:
       i=4;
   break;
   case 6:
       i=5;
   break;
   case 7:
       i=6;
   break;
       }

   countbefore -= i - 1;



for(int j = 0;j < 7; j++){

            if(j == i){
                le[j]->setText(QString::number(count++));
                le[j]->setStyleSheet(Normalday);
                le[j]->setEnabled(true);
                      }
            else if(j > i){
                le[j]->setText(QString::number(count++));
                le[j]->setStyleSheet(Normalday);
                le[j]->setEnabled(true);
                      }
            else{
                le[j]->setEnabled(false);
                le[j]->setStyleSheet(Otherday);
                le[j]->setText(QString::number(countbefore++));
                      }

            if(TodaysDay == count-1 && Month == M && Year == Y){
                le[j]->setStyleSheet(Currentday);
                le[j]->setEnabled(true);
            }

}


for(int j = 0; j < 7; j++){

          le2[j]->setText(QString::number(count++));
          le2[j]->setStyleSheet(Normalday);


          if(TodaysDay == count-1 && Month == M && Year == Y){
              le2[j]->setStyleSheet(Currentday);
              le2[j]->setEnabled(true);
          }
}



for(int j = 0; j < 7; j++){

            le3[j]->setText(QString::number(count++));
            le3[j]->setStyleSheet(Normalday);


            if(TodaysDay == count-1 && Month == M && Year == Y){
                le3[j]->setStyleSheet(Currentday);
                le3[j]->setEnabled(true);
            }
}



for(int j = 0; j < 7; j++){

         le4[j]->setText(QString::number(count++));
         le4[j]->setStyleSheet(Normalday);


         if(TodaysDay == count-1 && Month == M && Year == Y){
             le4[j]->setStyleSheet(Currentday);
             le4[j]->setEnabled(true);
         }
}



for(int j = 0; j < 7; j++){

         if(count > D){
            le5[j]->setEnabled(false);
            le5[j]->setStyleSheet(Otherday);
            le5[j]->setText(QString::number(countafter++));
                      }
            else{
            le5[j]->setText(QString::number(count++));
            le5[j]->setStyleSheet(Normalday);
            le5[j]->setEnabled(true);
                }


         if(TodaysDay == count-1 && Month == M && Year == Y){
             le5[j]->setStyleSheet(Currentday);
             le5[j]->setEnabled(true);
         }

}



for(int j = 0; j < 7; j++){

            if(count > D){
                le6[j]->setEnabled(false);
                le6[j]->setStyleSheet(Otherday);
                le6[j]->setText(QString::number(countafter++));
                          }
            else{
            le6[j]->setText(QString::number(count++));
            le6[j]->setStyleSheet(Normalday);
            le6[j]->setEnabled(true);
                }


            if(TodaysDay == count-1 && Month == M && Year == Y){
                le6[j]->setStyleSheet(Currentday);
                le6[j]->setEnabled(true);
            }

}



ui->lbl->setText(QString::number(date.month())+ " " + QString::number(date.year()));


}

void calendar::on_prevmonth_clicked()
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

    config();
}

void calendar::on_nextmonth_clicked()
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

    config();
}



void calendar::on_pushButton_clicked()
{
    this->close();
}




















