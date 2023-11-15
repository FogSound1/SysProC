#include "listactivecarswindow.h"
#include "ui_listactivecarswindow.h"

ListActiveCarsWindow::ListActiveCarsWindow(QWidget *parent, Database *DB) :
    QDialog(parent),
    ui(new Ui::ListActiveCarsWindow)
{
    ui->setupUi(this);

    std::string Temp = DB->DisplayCurrent();
    ui->DisplayBrowser->setText(QString::fromStdString(Temp));
}

ListActiveCarsWindow::~ListActiveCarsWindow()
{
    delete ui;
}

void ListActiveCarsWindow::on_ReturnButton_clicked()
{
    this->hide();
}
