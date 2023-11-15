#include "promotecarwindow.h"
#include "ui_promotecarwindow.h"
#include <QMessageBox>

PromoteCarWindow::PromoteCarWindow(QWidget *parent, int Quant) :
    QDialog(parent),
    ui(new Ui::PromoteCarWindow)
{
    ui->setupUi(this);
    Quantity = Quant;
}

PromoteCarWindow::~PromoteCarWindow()
{
    delete ui;
}

void PromoteCarWindow::on_ReturnButton_clicked()
{
    this->hide();
}

void PromoteCarWindow::on_PromoteButton_clicked()
{
    bool Status1 = false;
    bool Status2 = false;

    ui->CarCodeEdit->text().toInt(&Status1, 10);
    ui->PromotionEdit->text().toInt(&Status2, 10);

    if(Status1 && Status2 && ui->CarCodeEdit->text().toInt() <= Quantity && ui->CarCodeEdit->text().toInt() != 0)
    {
        emit PromoteForm(ui->CarCodeEdit->text().toInt(), ui->PromotionEdit->text().toInt());
        QMessageBox::about(this, "Success", "The car has been promoted");
        this->hide();
    }
    else
    {
        QMessageBox::about(this, "Warning", "Unable to promote a car");
    }
}
