#ifndef ENABLECARWINDOW_H
#define ENABLECARWINDOW_H

#include <QDialog>
namespace Ui {
class EnableCarWindow;
}

class EnableCarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnableCarWindow(QWidget *parent = nullptr);
    ~EnableCarWindow();

private slots:
    void on_ReturnButton_clicked();

    void on_EnableButton_clicked();

private:
    Ui::EnableCarWindow *ui;

signals:
    void EnableForm(int BrandCode, int RegNum, int BodyNum, int EngineNum,
                    std::string ReleaseDate, int Mileage, int DriverCode,
                    std::string Maintenance, int MechanicCode, std::string Specials);
};

#endif // ENABLECARWINDOW_H
