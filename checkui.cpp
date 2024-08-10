#include "checkui.h"
#include "ui_checkui.h"
#include"QTableWidgetItem"
#include"travelagency.h"
#include<QStringList>
CheckUI::CheckUI(Travelagency* travelagency,QWidget *parent) :travelagency(travelagency),
    QMainWindow(parent),
    ui(new Ui::CheckUI)
{

    ui->setupUi(this);
    Drawtable();
}

CheckUI::~CheckUI()
{
    delete ui;
}

void CheckUI::Drawtable()
{

    bool checkroundtrip();
    bool checkenoughhotels();
    bool checknouselessrentalcar();
    bool checkoverflowhotel();

    ui->TableUI->setHorizontalHeaderLabels(QStringList()<<"Travelid"<<"Missing Hotel"<<"OverLappingHotel"<<"OverlappingCar"<<"Roundtrip");
    ui->TableUI->setRowCount(travelagency->getAlltravels().size());
    ui->TableUI->setColumnCount(5);
    int row=0;
    for(auto& travel:travelagency->getAlltravels()){

        QTableWidgetItem* item1 = new QTableWidgetItem();
        QTableWidgetItem* item2= new QTableWidgetItem();
        QTableWidgetItem* item3= new QTableWidgetItem();
        QTableWidgetItem* item4= new QTableWidgetItem();
        QTableWidgetItem* item5= new QTableWidgetItem();

        item1->setText(QString::number(travel->gettravelid()));
        ui->TableUI->setItem(row,0,item1);

        if(travel->checkenoughhotels()==false){
            item2->setText("✅");
        }else{
            item2->setText("❌");
        }
        ui->TableUI->setItem(row,1,item2);


        if(travel->checkoverflowhotel()){
            item3->setText("✅");
        }else{
            item3->setText("❌");
        }

        ui->TableUI->setItem(row,2,item3);

        if(travel->checknouselessrentalcar()){
            item4->setText("✅");
        }else{
            item4->setText("❌");
        }
        ui->TableUI->setItem(row,3,item4);

        if(travel->checkroundtrip()){
            item5->setText("✅");
        }else{
            item5->setText("❌");
        }
        ui->TableUI->setItem(row,4,item5);



        row++;

    }

}
