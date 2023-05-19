
#ifndef HOLIDAY_H
#define HOLIDAY_H

#include <QMainWindow>
#include<QListWidgetItem>
#include<travelagency.h>
#include<QTableWidgetItem>
#include<travel.h>
QT_BEGIN_NAMESPACE
namespace Ui { class holiday; }
QT_END_NAMESPACE

class holiday : public QMainWindow

{
    Q_OBJECT

public:
    holiday(QWidget *parent = nullptr);

    ~holiday();

private slots:
    void on_actionInformation_Anzieigen_triggered();



    void on_actionAnzeigen_nach_ID_triggered();



    void readFile();



    void on_ReisenBox_itemClicked(QTableWidgetItem *item);

    void on_BuchungenBox_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::holiday *ui;

    Travelagency travel;
    Travel t;
    std::vector<int>id;
};

#endif // HOLIDAY_H
