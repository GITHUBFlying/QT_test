#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("First QT GUI");
    this->setMaximumSize(300,300);
    this->setMinimumSize(300,300);
    this->move(100,100);
    this->setStyleSheet("background::red");
    QLabel *label=new QLabel(this);
    label->setText("hello world");
    label->setGeometry((QRect(50,50,200,25)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
