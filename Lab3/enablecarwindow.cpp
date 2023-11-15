#include "enablecarwindow.h"
#include "ui_enablecarwindow.h"
#include <QMessageBox>

EnableCarWindow::EnableCarWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnableCarWindow)
{
    ui->setupUi(this);
}

EnableCarWindow::~EnableCarWindow()
{
    delete ui;
}

void EnableCarWindow::on_ReturnButton_clicked()
{
    this->hide();
}

void EnableCarWindow::on_EnableButton_clicked()
{
    bool Status = false;
    int BrandCode;
    int RegNum;
    int BodyNum;
    int EngineNum;
    std::string ReleaseDate;
    int Mileage;
    int DriverCode;
    std::string Maintenance;
    int MechanicCode;
    std::string Specials;

    ui->BrandCodeEdit->text().toInt(&Status, 10);
    ui->RegNumEdit->text().toInt(&Status, 10);
    ui->BodyNumEdit->text().toInt(&Status, 10);
    ui->EngineNumEdit->text().toInt(&Status, 10);
    ui->MileageEdit->text().toInt(&Status, 10);
    ui->DriverEdit->text().toInt(&Status, 10);
    ui->MechanicEdit->text().toInt(&Status, 10);

    if (Status)
    {
        BrandCode = ui->BrandCodeEdit->text().toInt();
        RegNum = ui->RegNumEdit->text().toInt();
        BodyNum = ui->BodyNumEdit->text().toInt();
        EngineNum = ui->EngineNumEdit->text().toInt();
        ReleaseDate = ui->DateEdit->text().toStdString();
        Mileage = ui->MileageEdit->text().toInt();
        DriverCode = ui->DriverEdit->text().toInt();
        Maintenance = ui->MaintenanceEdit->text().toStdString();
        MechanicCode = ui->MechanicEdit->text().toInt();
        Specials = ui->SpecialsEdit->text().toStdString();

        emit EnableForm(BrandCode, RegNum, BodyNum, EngineNum,
                        ReleaseDate, Mileage, DriverCode,
                        Maintenance, MechanicCode, Specials);

        QMessageBox::about(this, "Success", "The car has been added");
        this->hide();
    }
    else
    {
        QMessageBox::about(this, "Warning", "Unable to add new car");
    }
}
