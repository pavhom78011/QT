// Условие: Строка состоит из слов. Слова в исходной строке разделяются некоторым множеством разделителей.  Среди слов, состоящих только из цифр, найти слово, содержащее максимальное число нулей.
// Если таких слов больше одного, найти предпоследнее из них. Слова в исходной строке разделяются некоторым множеством разделителей. Слова в новой строке должны разделяться ровно одним пробелом.
// Хомицевич Павел
#include "mainwindow.h"
#include <QWidget>
#include <QApplication>
#include <regex>
#include <string>
using namespace std;
string TextConvert(string &str)
{
    string str2;
    string str3;
    int maxnumber{};
    regex rgx("[\\da-zA-Z]+");
    sregex_iterator it(str.begin(), str.end(), rgx);
    sregex_iterator iend;
    while (it != iend)
    {
        string s = it->str();
        str2 += s;
        str2 += " ";
        ++it;
    }
            //cout << "строка,в которой все слова разделены ровно одним пробелом:" << str2 << endl;
    string str2copy=str2;
    string space = " ";
    int number{}, t{};
    while (str2[0] != '\0')
    {
        for (int j = 0; (str2[j] != ' ') and (str2[j] != '\0'); ++j)
        {
            ++number;
        }
        for (int i = 0; i < number; i++)
        {
            if (isdigit(str2[i]))
            {
                ++t;
            }
        }
                if (t == number)
                {
                    for (int y = 0; y < number; ++y)
                    {
                        str3 += str2[y];
                    }
                    str3.append(space);
                }
                str2.erase(0, number);
                if (str2[0] == ' ')
                {
                    str2.erase(0, 1);
                }
                number = 0;
                t = 0;
            }
            //cout << "Строка,в которой находятся слова состоящие только из цифр и разделённые ровно одним пробелом:";
            //cout << str3 << endl;
            string str3copy=str3;
            rgx = ("[1-9]+");
            str3 = regex_replace(str3, rgx, "");
            //cout << "Строка из нулей:" << str3;
            vector <string> vec;
            rgx = ("[0]+");
            sregex_iterator it2(str3.begin(), str3.end(), rgx);
            sregex_iterator iend2;
            while (it2 != iend2)
            {
                string s = it2->str();
                vec.push_back(s);
                ++it2;
            }
            auto it3 = vec.begin();
            for (; it3 != vec.end(); ++it3)
            {
                if (maxnumber < (*it3).size())
                {
                    maxnumber = (*it3).size();
                }
            }
            //cout << "Максимальное количество нулей:" << maxnumber;
            return "Строка,в которой все слова разделены ровно одним пробелом:" + str2copy+'\n'+"Строка,в которой находятся слова состоящие только из цифр и разделённые ровно одним пробелом:"+str3copy+'\n'+"Максимальное количество нулей: "+to_string(maxnumber);
}
string BankCard(string str)
{
    regex rgx("[0-9]{4}[\\s]{1}[0-9]{4}[\\s]{1}[0-9]{4}[\\s]{1}[0-9]{4}");
    if (regex_match(str, rgx))
    {
        return "Номер кредитной карты действителен.";
    }
    else
    {
        return "Номер кредитной карты не действителен.";
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    for(;;)
    {
    string str = w.TextInfo();
    string str2;
    if(w.GetK()==w.GetI())
        {
        str2 = TextConvert(str);
        }
        else
        {
        str2= BankCard(str);
        }
    w.SetText(str2);
    }
    return a.exec();
}
