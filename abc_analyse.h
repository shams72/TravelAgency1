#ifndef ABC_ANALYSE_H
#define ABC_ANALYSE_H
#include"travelagency.h"
#include <QMainWindow>

namespace Ui {
class ABC_Analyse;
}

class ABC_Analyse : public QMainWindow
{
    Q_OBJECT

public:
    explicit ABC_Analyse(Travelagency* travel,QWidget *parent = nullptr);
    ~ABC_Analyse();
    
    void abcanalyse(Travelagency* travel);
    
private:
    Travelagency* travel;
    Ui::ABC_Analyse *ui;
};

#endif // ABC_ANALYSE_H
