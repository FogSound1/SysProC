#ifndef LISTINACTIVECARSWINDOW_H
#define LISTINACTIVECARSWINDOW_H

#include <QDialog>
#include "Database.h"

namespace Ui {
class ListInactiveCarsWindow;
}

class ListInactiveCarsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ListInactiveCarsWindow(QWidget *parent = nullptr, Database *DB = nullptr);
    ~ListInactiveCarsWindow();

private slots:
    void on_ReturnButton_clicked();

private:
    Ui::ListInactiveCarsWindow *ui;
};

#endif // LISTINACTIVECARSWINDOW_H
