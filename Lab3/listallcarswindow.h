#ifndef LISTALLCARSWINDOW_H
#define LISTALLCARSWINDOW_H

#include <QDialog>
#include "Database.h"

namespace Ui {
class ListAllCarsWindow;
}

class ListAllCarsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ListAllCarsWindow(QWidget *parent = nullptr, Database *DB = nullptr);
    ~ListAllCarsWindow();

private slots:
    void on_ReturnButton_clicked();

private:
    Ui::ListAllCarsWindow *ui;
};

#endif // LISTALLCARSWINDOW_H
