#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "facade.h"

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
    changeTemp();
private:
    Ui::MainWindow *ui;
    Facade *facade;
    QTimer* timer;
};

#endif // MAINWINDOW_H
