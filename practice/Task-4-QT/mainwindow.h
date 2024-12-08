#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int i{},k{},state{},state2{},state3{};
public:
    MainWindow(QWidget *parent = nullptr);
    void WaitForClick();
    void SetText(string s);
    int CheckI();
    int CheckK();
    int CheckState();
    int CheckState2();
    string GetName();
    string GetYear();
    string GetAuthor();
    void Clear();
    void CheckBoxConnect();
    void RadioButtonConnect();
    void RadioButton2Connect();
    void reset();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
