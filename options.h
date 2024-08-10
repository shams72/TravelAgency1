#ifndef OPTIONS_H
#define OPTIONS_H
#include<travelagency.h>
#include <QMainWindow>

namespace Ui {
class Options;
}

class Options : public QMainWindow
{
    Q_OBJECT

public:
    explicit Options(Travelagency *travelagency,QWidget *parent = nullptr);
    ~Options();

private slots:


    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::Options *ui;
    Travelagency *travelagency;
};

#endif // OPTIONS_H
