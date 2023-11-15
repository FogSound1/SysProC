#ifndef DISABLECARWINDOW_H
#define DISABLECARWINDOW_H

#include <QDialog>

namespace Ui {
class DisableCarWindow;
}

class DisableCarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DisableCarWindow(QWidget *parent = nullptr, int Quant = 0);
    ~DisableCarWindow();

private slots:
    void on_ReturnButton_clicked();

    void on_DisableButton_clicked();

private:
    Ui::DisableCarWindow *ui;
    int Quantity;

signals:
    void DisableForm(int CarCode);
};

#endif // DISABLECARWINDOW_H
