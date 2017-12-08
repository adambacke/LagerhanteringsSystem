#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ProductRegister.h"
#include "storage.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Product ab;
    ProductRegister productregister;
    Storage storage;
};

#endif // MAINWINDOW_H
