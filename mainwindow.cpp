#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    facade = new Facade();
    facade->Operation();

    timer = new QTimer();
    timer->setInterval(1000);
    timer->start();

    ui->plantEdit->setText(QString::fromStdString(facade->getGreenHouse()->getPlant()->getName()));
    ui->lineEdit_2->setText(QString::number(facade->getGreenHouse()->getPlant()->getMaxT()));
    ui->lineEdit->setText(QString::number(facade->getGreenHouse()->getPlant()->getMinT()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(changeTemp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::changeTemp()
{
    //ui->timeEdit->setText(QString::number(greenHouse->GetCurrentTime()));

    ui->dayEdit->setText(QString::number(facade->getGreenHouse()->GetDay()));
    ui->hourEdit->setText(QString::number(facade->getGreenHouse()->GetHour()));
    ui->minuteEdit->setText(QString::number(facade->getGreenHouse()->GetMinute()));

    ui->tempEdit->setText(QString::number(facade->getGreenHouse()->GetTemperature()));
    ui->heaterEdit->setText(QString::fromStdString(facade->getGreenHouse()->GetState()));

    //ui->heaterEdit->setText(QString::fromStdString(greenHouse->GetHeaterState()));

    //ui->coolerEdit->setText(QString::fromStdString(greenHouse->GetCoolerState()));
    ui->lightEdit->setText(QString::fromStdString(facade->getGreenHouse()->getMessage()));
}
