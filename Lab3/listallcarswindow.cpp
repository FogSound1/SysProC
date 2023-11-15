#include "listallcarswindow.h"
#include "ui_listallcarswindow.h"

ListAllCarsWindow::ListAllCarsWindow(QWidget *parent, Database *DB) :
    QDialog(parent),
    ui(new Ui::ListAllCarsWindow)
{
    ui->setupUi(this);

    std::string Temp = DB->DisplayAll();
    ui->DisplayBrowser->setText(QString::fromStdString(Temp));
}

ListAllCarsWindow::~ListAllCarsWindow()
{
    delete ui;
}

void ListAllCarsWindow::on_ReturnButton_clicked()
{
    this->hide();
}
