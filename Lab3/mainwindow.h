#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "enablecarwindow.h"
#include "demotecarwindow.h"
#include "disablecarwindow.h"
#include "listactivecarswindow.h"
#include "listallcarswindow.h"
#include "listinactivecarswindow.h"
#include "promotecarwindow.h"
#include "Database.h"
#include "fileoperationswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_EnableCarButton_clicked();

    void on_DisableCarButton_clicked();

    void on_PromoteCarButton_clicked();

    void on_DemoteCarButton_clicked();

    void on_ListAllCarsButton_clicked();

    void on_ListActiveButton_clicked();

    void on_ListInactiveButton_clicked();

    void on_QuitButton_clicked();

    void on_ReadRecordFileButton_clicked();

public slots:
    void EnableSlot(int BrandCode, int RegNum, int BodyNum, int EngineNum,
                    std::string ReleaseDate, int Mileage, int DriverCode,
                    std::string Maintenance, int MechanicCode, std::string Specials);
    void DisableSlot(int CarCode);
    void PromoteSlot(int CarCode, int Promotion);
    void DemoteSlot(int CarCode, int Demotion);
    void ReadSlot();
    void RecordSlot();

private:
    Ui::MainWindow *ui;
    EnableCarWindow *ECW;
    DisableCarWindow *DCW;
    PromoteCarWindow *PCW;
    DemoteCarWindow *DeCW;
    ListAllCarsWindow *LAW;
    ListActiveCarsWindow *LACW;
    ListInactiveCarsWindow *LICW;
    FileOperationsWindow *FOW;
    Database TaxiDB;
    std::string FileName = "CarDb.txt";
};
#endif // MAINWINDOW_H
