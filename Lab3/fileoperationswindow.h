#ifndef FILEOPERATIONSWINDOW_H
#define FILEOPERATIONSWINDOW_H

#include <QDialog>
#include <fstream>

namespace Ui {
class FileOperationsWindow;
}

class FileOperationsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FileOperationsWindow(QWidget *parent = nullptr);
    ~FileOperationsWindow();

private slots:
    void on_ReadButton_clicked();

    void on_RecordButton_clicked();

private:
    Ui::FileOperationsWindow *ui;

signals:
    void ReadForm();
    void RecordForm();
};

#endif // FILEOPERATIONSWINDOW_H
