#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
std::string MainWindow::TextInfo()
{
    i=k;
    QEventLoop loop;
    QObject::connect(ui->pushButton,&QPushButton::clicked,&loop,&QEventLoop::quit);
    QObject::connect(ui->pushButton_4,&QPushButton::clicked,&loop,[&](){loop.quit();++k;});
    loop.exec();
    ui->DateAndTime->setDateTime(QDateTime::currentDateTime());
    return (ui->textEdit->toPlainText()).toStdString();
}
void MainWindow::SetText(std::string s)
{
    ui->textEdit->setText(QString::fromStdString(s));
}
int MainWindow::GetK()
{
    return k;
}
int MainWindow::GetI()
{
    return i;
}
MainWindow::~MainWindow()
{
    delete ui;
}
