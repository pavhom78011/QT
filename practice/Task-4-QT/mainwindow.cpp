#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::RadioButtonConnect()
{
    QObject::connect(ui->radioButton,&QRadioButton::clicked,[&](){if(ui->radioButton->isChecked()){state=1;}});
}
void MainWindow::RadioButton2Connect()
{
    QObject::connect(ui->radioButton_2,&QRadioButton::clicked,[&](){if(ui->radioButton_2->isChecked()){state2=1;}});
}
void MainWindow::CheckBoxConnect()
{
    ui->checkBox->setChecked(1);
    QObject::connect(ui->checkBox,&QCheckBox::stateChanged,[&](){++state;ui->lineEdit->setVisible(state%2==0);ui->lineEdit_2->setVisible(state%2==0);ui->lineEdit_3->setVisible(state%2==0);ui->label_2->setVisible(state%2==0);ui->label_3->setVisible(state%2==0);ui->label_4->setVisible(state%2==0);});
}
void MainWindow::WaitForClick()
{
    i=k;
    state=0;
    state2=0;
    QEventLoop loop;
    QObject::connect(ui->pushButton,&QPushButton::clicked,&loop,[&](){loop.quit();});
    QObject::connect(ui->toolButton,&QToolButton::clicked,&loop,[&](){loop.quit();++k;});
    loop.exec();
}
void MainWindow::SetText(string s)
{
    ui->textEdit->setText(QString::fromStdString(s));
}
int MainWindow::CheckI()
{
    return i;
}
int MainWindow::CheckK()
{
    return k;
}
int MainWindow::CheckState()
{
    return state;
}
int MainWindow::CheckState2()
{
    return state2;
}
string MainWindow::GetName()
{
    return (ui->lineEdit_3->text()+'\n').toStdString();
}
string MainWindow::GetYear()
{
    return (ui->lineEdit_2->text()+'\n').toStdString();
}
string MainWindow::GetAuthor()
{
    return (ui->lineEdit->text()+'\n').toStdString();
}
void MainWindow::Clear()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}
void MainWindow::reset()
{
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton->setAutoExclusive(true);
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton_2->setAutoExclusive(true);
    ui->radioButton_3->setAutoExclusive(false);
    ui->radioButton_3->setChecked(false);
    ui->radioButton_3->setAutoExclusive(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}

