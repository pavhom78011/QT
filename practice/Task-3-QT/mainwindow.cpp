#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::GetTextInfo(QVector<QString> &vec)
{
    QEventLoop loop1;
    QObject::connect(ui->toolButton,&QToolButton::clicked,&loop1,&QEventLoop::quit);
    ui->tableWidget->editTriggers();
    ui->progressBar->setValue(0);
    loop1.exec();
    ui->timeEdit->setTime(QTime::currentTime());
    vec.push_back(ui->tableWidget->item(0,0)->text());
    vec.push_back(ui->tableWidget->item(0,1)->text());
    vec.push_back(ui->tableWidget->item(0,2)->text());
    vec.push_back(ui->tableWidget->item(0,3)->text());
    vec.push_back(ui->tableWidget->item(0,4)->text());
    vec.push_back(ui->tableWidget->item(0,5)->text());
    ui->progressBar->setValue(5);
}
bool MainWindow::Checking()
{
    return ui->radioButton->isChecked();
    ui->progressBar->setValue(70);
}
void MainWindow::SetText(QString str)
{
    ui->textEdit->setText(str);
    ui->progressBar->setValue(35);
}
bool MainWindow::Repeat()
{
    QEventLoop loop2;
    QObject::connect(ui->pushButton,&QToolButton::clicked,&loop2,&QEventLoop::quit);
    ui->progressBar->setValue(100);
    loop2.exec();
    ui->textEdit->clear();
    ui->tableWidget->item(0,0)->setText("0");
    ui->tableWidget->item(0,1)->setText("0");
    ui->tableWidget->item(0,2)->setText("0");
    ui->tableWidget->item(0,3)->setText("0");
    ui->tableWidget->item(0,4)->setText("0");
    ui->tableWidget->item(0,5)->setText("0");
    ui->progressBar->setValue(0);
    return 1;
}
MainWindow::~MainWindow()
{
    delete ui;
}
