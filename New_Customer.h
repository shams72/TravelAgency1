#ifndef NEW_CUSTOMER_H
#define NEW_CUSTOMER_H
#include"travelagency.h"
#include <QMainWindow>
#include<memory>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Travelagency* travelagency,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

private:
    bool customerid_needed;
    int customersid;
    bool addbooking;
    bool addtravel;
    Travelagency* travelagency;
    //std::shared_ptr<Travelagency> travelagency=std::make_shared<Travelagency>();
    Ui::MainWindow *ui;
};

#endif // NEW_CUSTOMER_H
