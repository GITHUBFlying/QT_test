#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork/QHostInfo>
#include <QtNetwork/QNetworkInterface>
#include <QDebug>
#include <QProcess>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioHost->setChecked(true);
    ui->radioMaster->setChecked(false);
    ui->textremoteIP->setEnabled(false);
   QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface interface,list)
    {
        if((interface.name().contains("eth0"))||(interface.name().contains("wlan0")))
        {
            QList<QNetworkAddressEntry> entryList = interface.addressEntries();
            if(!entryList.isEmpty())
            {

                ui->textlocalIP->setText(entryList[0].ip().toString());
                break;
            }
        }
    }


}
void MainWindow::on_startButton_clicked()
{
     ui->startButton->setText("已启动");
     if(ui->radioHost->isChecked())
     {
        system("gnome-terminal -x bash -c 'source /opt/ros/indigo/setup.bash;roscore'&");
     }
     QString str1="'export ROS_MASTER_URI=http://"+ui->textremoteIP->text().simplified()+":11311'";
     qDebug()<<str1;
     if(ui->radioMaster->isChecked())
     {
        QString str2="gnome-terminal -x bash -c "+str1+"&";
        qDebug()<<str2;
        // system("gnome-terminal -x bash -c "+str1+"&");
     }

}
void MainWindow::on_radioHost_clicked()
{
    ui->textremoteIP->setEnabled(false);
}
void MainWindow::on_radioMaster_clicked()
{
    ui->textremoteIP->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
