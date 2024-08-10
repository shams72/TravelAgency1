#include "options.h"
#include "ui_options.h"
#include"sortfunktor.h"
#include<QMessageBox>
Options::Options(Travelagency *travelagency,QWidget *parent) :travelagency(travelagency),
    QMainWindow(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}




void Options::on_pushButton_clicked()
{

    SortFunktor sortfunktor("price");
    std::sort(travelagency->getBookings().begin(), travelagency->getBookings().end(), sortfunktor);
    QMessageBox msgbox;
    msgbox.setText("sorted");
    msgbox.exec();

}


void Options::on_radioButton_clicked()
{

}


void Options::on_radioButton_3_clicked()
{

}

