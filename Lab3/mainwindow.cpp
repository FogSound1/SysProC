#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_EnableCarButton_clicked()
{
    ECW = new EnableCarWindow();
    ECW->show();

    connect(ECW, &EnableCarWindow::EnableForm, this, &MainWindow::EnableSlot);
}
void MainWindow::on_DisableCarButton_clicked()
{
    DCW = new DisableCarWindow(this, TaxiDB.GetQuantity());
    DCW->show();

    connect(DCW, &DisableCarWindow::DisableForm, this, &MainWindow::DisableSlot);
}
void MainWindow::on_PromoteCarButton_clicked()
{
    PCW = new PromoteCarWindow(this, TaxiDB.GetQuantity());
    PCW->show();

    connect(PCW, &PromoteCarWindow::PromoteForm, this, &MainWindow::PromoteSlot);
}
void MainWindow::on_DemoteCarButton_clicked()
{
    DeCW = new DemoteCarWindow(this, TaxiDB.GetQuantity());
    DeCW->show();

    connect(DeCW, &DemoteCarWindow::DemoteForm, this, &MainWindow::DemoteSlot);
}
void MainWindow::on_ListAllCarsButton_clicked()
{
    LAW = new ListAllCarsWindow(this, &TaxiDB);
    LAW->show();
}
void MainWindow::on_ListActiveButton_clicked()
{
    LACW = new ListActiveCarsWindow(this, &TaxiDB);
    LACW->show();
}
void MainWindow::on_ListInactiveButton_clicked()
{
    LICW = new ListInactiveCarsWindow(this, &TaxiDB);
    LICW->show();
}

void MainWindow::on_QuitButton_clicked()
{
    close();
}


void MainWindow::EnableSlot(int BrandCode, int RegNum, int BodyNum, int EngineNum,
                            std::string ReleaseDate, int Mileage, int DriverCode,
                            std::string Maintenance, int MechanicCode, std::string Specials)
{
    TaxiDB.AddCar(BrandCode, RegNum, BodyNum, EngineNum, ReleaseDate, Mileage,
                  DriverCode, Maintenance, MechanicCode, Specials);
}

void MainWindow::DisableSlot(int CarCode)
{
    Car& car = TaxiDB.GetCar(CarCode);
    car.Disable();
}

void MainWindow::PromoteSlot(int CarCode, int Promotion)
{
    Car& car = TaxiDB.GetCar(CarCode);
    car.Promote(Promotion);
}

void MainWindow::DemoteSlot(int CarCode, int Demotion)
{
    Car& car = TaxiDB.GetCar(CarCode);
    car.Demote(Demotion);
}

void MainWindow::ReadSlot()
{
    TaxiDB.ReadFromFile(FileName);
}

void MainWindow::RecordSlot()
{
    TaxiDB.WriteToFile(FileName);
}
void MainWindow::on_ReadRecordFileButton_clicked()
{
    FOW = new FileOperationsWindow(this);
    FOW->show();

    connect(FOW, &FileOperationsWindow::ReadForm, this, &MainWindow::ReadSlot);
    connect(FOW, &FileOperationsWindow::RecordForm, this, &MainWindow::RecordSlot);
}
