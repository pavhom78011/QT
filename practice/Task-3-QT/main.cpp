//Хомицевич Павел
#include "mainwindow.h"
#include <QApplication>
#include <queue>
#include <string>
#include <QFile>
void input(queue <string> &q1)
{
    QFile FILE(":/resources/Input.txt");
    if (FILE.open(QIODevice::ReadOnly))
    {
        string str;
        QTextStream in(&FILE);
        while (!in.atEnd())
        {
            str.clear();
            str=in.readLine().toStdString();
            q1.emplace(str);
        }
    }
    FILE.close();
}
QString Solution(QVector<QString> &vec,queue <string> q1)
{
    int m=stoi((vec[0]).toStdString());
    int n=stoi((vec[1]).toStdString());
    int mc=stoi((vec[2]).toStdString());
    int k=stoi((vec[3]).toStdString());
    int T=stoi((vec[4]).toStdString());
    int t=stoi((vec[5]).toStdString());
    int allcars = (n / 60.) * T + m;
    int carwashed = ((t + T) / mc) * k;
    int carnotwashed = allcars - carwashed;
    int carnotwashedcopy=carnotwashed;
    if(carnotwashed>0)
    {
        string NotWashedCars{'\n'};
        while (carnotwashed != 0)
        {
            NotWashedCars+=q1.front()+='\n';
            q1.pop();
            --carnotwashed;
        }
        return "Машины не успеют помыть " + QString::fromStdString(to_string(carnotwashedcopy)) + " автомобилей."+'\n'+"Машины оставшиеся в очереди:"+QString::fromStdString(NotWashedCars);
    }
    else
    {
        return "Все машины будут помыты.";
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    repeat:
    QVector<QString> vec;
    queue<string> q;
    QString str;
    input(q);
    w.show();
    w.GetTextInfo(vec);
    if(stoi((vec[2]).toStdString())!=0)
    {
        str=Solution(vec,q);
        w.SetText(str);
    }
    QFile FILE2("Output.txt");
    if (FILE2.open(QIODevice::WriteOnly))
    {
        QTextStream out(&FILE2);
        if(w.Checking())
        {
            if(str=="Все машины будут помыты.")
            {
            out<<"Yes";
            }
            else
            {
                out<<"No";
            }
        }
    }
    FILE2.close();
    if(w.Repeat()==1)
    {
        goto repeat;
    }
    return a.exec();
}
