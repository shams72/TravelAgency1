
#ifndef HOLIDAY_H
#define HOLIDAY_H
#include <QMainWindow>
#include<QListWidgetItem>
#include<travelagency.h>
#include<QTableWidgetItem>
#include<travel.h>
#include<QDate>
#include"options.h"
#include"New_Customer.h"
#include"booking_travel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class holiday; }
QT_END_NAMESPACE

class holiday : public QMainWindow

{
    Q_OBJECT

public:
    holiday(QWidget *parent = nullptr);

    ~holiday();

    void default_file(std::shared_ptr<Booking> d);
    
    void maps(std::shared_ptr<Booking> d, QString geoJson);
    
private slots:
    void on_actionInformation_Anzieigen_triggered();
void readFile();

    void on_actionAnzeigen_nach_ID_triggered();







    void on_ReisenBox_itemClicked(QTableWidgetItem *item);

    void on_BuchungenBox_itemDoubleClicked(QTableWidgetItem *item);





    void on_pushButton_clicked();

    void on_pushButton_2_clicked();






    void on_actionShow_Airport_triggered();

    void on_pushButton_3_clicked();

    void on_actionAlle_Anzeigen_triggered();

    void on_Createfile_clicked();

    void on_actionhello_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::holiday *ui;
    std::shared_ptr<Booking> d=nullptr;
    QDate start_fromDate;
    QDate star_enddtate;
    MainWindow* main;

    Travelagency travelagency;
    Options* option;
    Travel t;
    std::vector<int>id;
    std::vector<int>travelid;
    std::vector<std::string>bokingid;
    std::vector<int>row;
    int reisenbox_row;
    bool sort;

};

#endif // HOLIDAY_H
