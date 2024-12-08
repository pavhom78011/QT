#include "tasks.h"

tasks::tasks(QObject *parent) : QObject(parent), settings("Hello", "World")
{
    record = settings.value("MyRecord",0).toInt();
}
QString tasks::getTask()
{
    difficulty += 1;
    int a = QRandomGenerator::global()->bounded(1,difficulty);
    int b = QRandomGenerator::global()->bounded(1,difficulty);
    int c = QRandomGenerator::global()->bounded(4);
    if (c == 0)
    {
        answer = QString::number(a + b);
        task = QString::number(a) + " + " + QString::number(b) + " = ";
    }
    else if (c == 1)
    {
        answer = QString::number(a - b);
        task = QString::number(a) + " - " + QString::number(b) + " = ";
    }
    else if (c == 2)
    {
        answer = QString::number(a * b);
        task = QString::number(a) + " * " + QString::number(b) + " = ";
    }
    else if (c == 3)
    {
        while (a % b != 0)
        {
            b = QRandomGenerator::global()->bounded(1,difficulty);
        }
        answer = QString::number(a / b);
        task = QString::number(a) + " / " + QString::number(b) + " = ";
    }
    return task;
}
QString tasks::getAnswer()
{
    return answer;
}
QString tasks::getScore()
{
    return QString::number(score);
}
QString tasks::getTime()
{
    return QString::number(time);
}
QString tasks::getRecord()
{
    return QString::number(record);
}
void tasks::decTime()
{
    -- time;
}
void tasks::incScore()
{
    ++ score;
}
void tasks::returnValues()
{
    time = 60;
    score = 0;
    difficulty = 10;
}
void tasks::setScoreInRecord()
{
    if(record < score)
    {
        record = score;
    }
}
void tasks::saveRecord()
{
    settings.setValue("MyRecord",record);
    settings.sync();
}
void tasks::playSoundYes()
{
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/vyibor-nujnogo-deystviya.mp3"));
    player->play();
}
void tasks::playSoundNo()
{
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/zvuk-oshibki-vyibora.mp3"));
    player->play();
}
void tasks::playStartSound()
{
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/igrovaya-sreda-audio-energoobespechenie-audio-material-39368.mp3"));
    player->play();
}
