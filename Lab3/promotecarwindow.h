#ifndef PROMOTECARWINDOW_H
#define PROMOTECARWINDOW_H

#include <QDialog>

namespace Ui {
class PromoteCarWindow;
}

class PromoteCarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PromoteCarWindow(QWidget *parent = nullptr, int Quant = 0);
    ~PromoteCarWindow();

private slots:
    void on_ReturnButton_clicked();

    void on_PromoteButton_clicked();

private:
    Ui::PromoteCarWindow *ui;
    int Quantity;

signals:
    void PromoteForm(int CarCode, int Promotion);
};

#endif // PROMOTECARWINDOW_H
