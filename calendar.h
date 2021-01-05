#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMainWindow>
#include <QWidget>
#include <QDate>
#include <QDateTime>
#include <QLocale>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>

namespace Ui {
class calendar;
}

class calendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit calendar(QWidget *parent = nullptr);
    ~calendar();

    friend class MainWindow;

    //konfiguracja
      void config();
    //ustawia nadte na górze okna
      void setUpLblDate();



private slots:

    void on_prevmonth_clicked();

    void on_nextmonth_clicked();

    void on_pushButton_clicked();


private:

    //tworzy buttony
      void createButtons();
    //set number in line edit
      void setNumber(int);

    //angielskie nazewnictwo dat
      QLocale locale = QLocale(QLocale::Polish);
    //obiekt data
      QDate date = QDate::currentDate();

    //zmienne na dzien, miesiac i rok
      short TodaysDay = date.day();
      short DayInWeek = date.dayOfWeek();
      short Month = date.month();
      short Year = date.year();

      QString const Normalday = "background-color: rgb(44,44,44); color: #ffffff; font:87 15px Arial Black; border: 1px solid rgba(245, 203, 92, 0.9); border-radius: 5px;";
      QString const Currentday = "background-color: rgb(44,44,44); color: #ffffff; font:87 15px Arial Black; border: 1px solid rgba(37, 180, 255, 1); border-radius: 5px;";
      QString const Otherday = "background-color: rgb(44,44,44); color: #ffffff; font:87 15px Arial Black; border-radius: 5px;";

      QPushButton *le[7];
       QPushButton *le2[7];
        QPushButton *le3[7];
         QPushButton *le4[7];
          QPushButton *le5[7];
           QPushButton *le6[7];

           //QString nameDay[7] ={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

           // M = date.month();
           int M = date.month();
           int D = date.daysInMonth();
           int Y = date.year();
           QDate *prevdate;

    Ui::calendar *ui;
};

#endif // CALENDAR_H
