#ifndef LISTACTIVECARSWINDOW_H
#define LISTACTIVECARSWINDOW_H

#include <QDialog>
#include "Database.h"

namespace Ui {
class ListActiveCarsWindow;
}

class ListActiveCarsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ListActiveCarsWindow(QWidget *parent = nullptr, Database *DB = nullptr);
    ~ListActiveCarsWindow();

private slots:
    void on_ReturnButton_clicked();

private:
    Ui::ListActiveCarsWindow *ui;
};

#endif // LISTACTIVECARSWINDOW_H
