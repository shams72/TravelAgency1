#ifndef CHECKUI_H
#define CHECKUI_H
#include"travelagency.h"
#include <QMainWindow>

namespace Ui {
class CheckUI;
}

class CheckUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckUI( Travelagency* travelagency,QWidget *parent = nullptr);
    ~CheckUI();
    void Drawtable();

private:
    Travelagency* travelagency;
    Ui::CheckUI *ui;
};

#endif // CHECKUI_H
