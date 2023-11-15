#include "fileoperationswindow.h"
#include "ui_fileoperationswindow.h"

FileOperationsWindow::FileOperationsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileOperationsWindow)
{
    ui->setupUi(this);
}

FileOperationsWindow::~FileOperationsWindow()
{
    delete ui;
}

void FileOperationsWindow::on_ReadButton_clicked()
{
    emit ReadForm();
    this->hide();
}

void FileOperationsWindow::on_RecordButton_clicked()
{
    emit RecordForm();
    this->hide();
}
