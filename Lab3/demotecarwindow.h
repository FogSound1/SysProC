#ifndef DEMOTECARWINDOW_H
#define DEMOTECARWINDOW_H

#include <QDialog>

namespace Ui {
class DemoteCarWindow;
}

class DemoteCarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DemoteCarWindow(QWidget *parent = nullptr, int Quant = 0);
    ~DemoteCarWindow();

private slots:
    void on_ReturnButton_clicked();

    void on_DemoteButton_clicked();

private:
    Ui::DemoteCarWindow *ui;
    int Quantity;

signals:
    void DemoteForm(int CarCode, int Demotion);
};

#endif // DEMOTECARWINDOW_H
