#include "listinactivecarswindow.h"
#include "ui_listinactivecarswindow.h"

ListInactiveCarsWindow::ListInactiveCarsWindow(QWidget *parent, Database *DB) :
    QDialog(parent),
    ui(new Ui::ListInactiveCarsWindow)
{
    ui->setupUi(this);

    std::string Temp = DB->DisplayFormer();
    ui->DisplayBrowser->setText(QString::fromStdString(Temp));
}

ListInactiveCarsWindow::~ListInactiveCarsWindow()
{
    delete ui;
}

void ListInactiveCarsWindow::on_ReturnButton_clicked()
{
    this->hide();
}
