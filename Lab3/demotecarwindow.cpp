#include "demotecarwindow.h"
#include "ui_demotecarwindow.h"
#include <QMessageBox>

DemoteCarWindow::DemoteCarWindow(QWidget *parent, int Quant) :
    QDialog(parent),
    ui(new Ui::DemoteCarWindow)
{
    ui->setupUi(this);
    Quantity = Quant;
}

DemoteCarWindow::~DemoteCarWindow()
{
    delete ui;
}

void DemoteCarWindow::on_ReturnButton_clicked()
{
    this->hide();

    QWidget *parent = this->parentWidget();
    parent->show();
}

void DemoteCarWindow::on_DemoteButton_clicked()
{
    bool Status1 = false;
    bool Status2 = false;

    ui->CarCodeEdit->text().toInt(&Status1, 10);
    ui->DemotionEdit->text().toInt(&Status2, 10);

    if(Status1 && Status2 && ui->CarCodeEdit->text().toInt() <= Quantity && ui->CarCodeEdit->text().toInt() != 0)
    {
        emit DemoteForm(ui->CarCodeEdit->text().toInt(), ui->DemotionEdit->text().toInt());
        QMessageBox::about(this, "Success", "The car has been demoted");
        this->hide();
    }
    else
    {
        QMessageBox::about(this, "Warning", "Unable to demote a car");
    }
}
