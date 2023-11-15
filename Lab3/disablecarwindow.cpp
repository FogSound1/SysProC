#include "disablecarwindow.h"
#include "ui_disablecarwindow.h"
#include <QMessageBox>

DisableCarWindow::DisableCarWindow(QWidget *parent, int Quant) :
    QDialog(parent),
    ui(new Ui::DisableCarWindow)
{
    ui->setupUi(this);
    Quantity = Quant;
}

DisableCarWindow::~DisableCarWindow()
{
    delete ui;
}

void DisableCarWindow::on_ReturnButton_clicked()
{
    this->hide();
}

void DisableCarWindow::on_DisableButton_clicked()
{
    bool Status = false;
    ui->CarCodeEdit->text().toInt(&Status, 10);

    if (Status)
    {
        if (ui->CarCodeEdit->text().toInt() > Quantity || ui->CarCodeEdit->text().toInt() == 0)
        {
            QMessageBox::about(this, "Warning", "There is no car with this car code");
        }
        else
        {
            emit DisableForm(ui->CarCodeEdit->text().toInt());
            QMessageBox::about(this, "Success", "The car has been terminated.");
            this->hide();
        }
    }
    else
    {
       QMessageBox::about(this, "Warning", "Provide a proper code");
    }
}
