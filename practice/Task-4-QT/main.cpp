/*Разработать класс «Книга»  для хранения регистрационной информации о книге.
Реализовать функции добавления, удаления, поиска, замены.
Определить private-, public- производный класс ««Печатные издания» имеющий дополнительную информацию.
Определить конструкторы, деструкторы и функцию печати.*/
//Хомицевич Павел
#include "mainwindow.h"

#include <QApplication>
class Book
{
    int i{};
    string name[1000];
    int year[1000];
    string author[1000];
public:
    Book()
    {

    }
    void AddNameYearAuthor(string str,int a,string str2)
    {
        name[i] = str;
        year[i] = a;
        author[i]=str2;
        QFile FILE3("File.txt");
        if (FILE3.open(QIODevice::WriteOnly|QIODevice::Append))
        {
            QTextStream out(&FILE3);
            out<<"Name:"<<'\n';
            out<<QString::fromStdString(name[i]);
            out<<"Year:"<<'\n';
            out<<QString::fromStdString(to_string(year[i]))<<'\n';
            out<<"Author:"<<'\n';
            out<<QString::fromStdString(author[i]);
        }
        FILE3.close();
        ++i;
    }
    int GetI()
    {
        return i;
    }
    string GetName(int k)
    {
        return name[k];
    }
    int GetYear(int k)
    {
        return year[k];
    }
    void ReadFile(int state2)
    {
        if(state2)
        {
        QFile FILE(":/resources/File.txt");
        if (FILE.open(QIODevice::ReadOnly))
        {
            QTextStream in(&FILE);
            for (;!in.atEnd();++i)
            {
                in.readLine();
                name[i]=in.readLine().toStdString();
                in.readLine();
                year[i]=stoi(in.readLine().toStdString());
                in.readLine();
                author[i]=in.readLine().toStdString();
            }
        }
        FILE.close();
        }
        QFile FILE2("File.txt");
        if (FILE2.open(QIODevice::ReadOnly))
        {
            QTextStream in2(&FILE2);
            in2.seek(0);
            for (;!in2.atEnd();++i)
            {
                in2.readLine();
                name[i]=in2.readLine().toStdString();
                in2.readLine();
                year[i]=stoi(in2.readLine().toStdString());
                in2.readLine();
                author[i]=in2.readLine().toStdString();
            }
        }
        FILE2.close();
    }
    string print()
    {
        string s{""};
        int t{};
        if(name[0]==(name[i-1]+"\n"))
        {
            ++t;
        }
        for (int i = GetI(); t < i; ++t)
        {
            s+= "Название: "  + GetName(t) + " Год: " + to_string(GetYear(t))+" "+"Автор:"+author[t]+'\n';
        }
        return s;
    }
    ~Book()
    {

    }
};
void ClearFiles()
{
    QFile file2("File.txt");
    QTextStream out2(&file2);
    file2.open(QIODevice::WriteOnly);
    file2.resize(0);
    file2.close();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.RadioButtonConnect();
    w.CheckBoxConnect();
    w.RadioButton2Connect();
    int y(1);
    repeat:
    Book b;
    w.WaitForClick();
    if(w.CheckI()!=w.CheckK())
    {
        b.AddNameYearAuthor(w.GetName(),stoi(w.GetYear()),w.GetAuthor());
        w.Clear();
    }
    if(w.CheckState() or w.CheckState2())
    {
        ClearFiles();
    }
    if(!w.CheckState2())
    {
    b.ReadFile(y);
    w.SetText(b.print());
    }
    else
    {
        y=0;
    }
    w.reset();
    goto repeat;
    return a.exec();
}
