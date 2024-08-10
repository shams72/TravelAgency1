#include "abc_analyse.h"
#include "ui_abc_analyse.h"
#include"customer.h"
#include"QTableWidgetItem"
void ABC_Analyse::abcanalyse(Travelagency* travel)
{
    double totalprice = travel->gettotalprice();

    std::shared_ptr<Customer> customer;
    double customerprice;int row=0;



    double anteil=0;double kumuliert=0;
    for(auto each_customer:travel->getAllcustomers()){

        QTableWidgetItem* item1 = new QTableWidgetItem();
        QTableWidgetItem* item2 = new QTableWidgetItem();
        QTableWidgetItem* item3 = new QTableWidgetItem();
        QTableWidgetItem* item4 = new QTableWidgetItem();
        QTableWidgetItem* item5 = new QTableWidgetItem();
        QTableWidgetItem* item6 = new QTableWidgetItem();


        ui->tableWidget->setRowCount(travel->getAllcustomers().size());

        ui->tableWidget->setColumnCount(7);

        customer=each_customer;
        customerprice=customer->getcustomertotalprice();

        QString name = QString::number(each_customer->getid());
        item1->setText(name);

        QString c_id=QString::fromStdString(each_customer->getname());
        item2->setText(c_id);

        QString price =QString::number(customerprice);
        item3->setText(price);

        ui->tableWidget->setItem(row,0,item1);
        ui->tableWidget->setItem(row,1,item2);
        ui->tableWidget->setItem(row,2,item3);


        std::vector<std::shared_ptr<Customer>> sortedcustomer;
        /*
        for(auto customer : travel->getAllcustomers()){

            if()

        }*/



        anteil = (customerprice)/(totalprice);

        item4->setText(QString::number(anteil*100));
        ui->tableWidget->setItem(row,3,item4);

        kumuliert = kumuliert + anteil;

        item5->setText(QString::number(kumuliert*100));
        ui->tableWidget->setItem(row,4,item5);



        if(kumuliert <= 0.8){
            item6->setText("A");
            ui->tableWidget->setItem(row,5,item6);
            ui->tableWidget->item(row,5)->setBackground(QBrush(QColor("green")));
        }else if (kumuliert <= 0.9){
            item6->setText("b");
            ui->tableWidget->setItem(row,5,item6);
            ui->tableWidget->item(row,5)->setBackground(QBrush(QColor("yellow")));
        }else {
            item6->setText("c");
            ui->tableWidget->setItem(row,5,item6);
            ui->tableWidget->item(row,5)->setBackground(QBrush(QColor("red")));
        }

        row++;

    }
}

ABC_Analyse::ABC_Analyse(Travelagency* travel,QWidget *parent) :travel(travel),
    QMainWindow(parent),
    ui(new Ui::ABC_Analyse)
{
     ui->setupUi(this);

    abcanalyse(travel);




}

ABC_Analyse::~ABC_Analyse()
{
    delete ui;
}
