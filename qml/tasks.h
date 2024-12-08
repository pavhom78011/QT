#ifndef TASKS_H
#define TASKS_H

#include <QObject>
#include <QString>
#include <QRandomGenerator>
#include <QSettings>
#include <QtMultimedia>
#include <QAudioOutput>

class tasks : public QObject
{
    Q_OBJECT
    int score{};
    int time{60};
    int record{};
    int difficulty{10};
    QString task{};
    QString answer{};
    QSettings settings;
    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;
public:
    explicit tasks(QObject *parent = nullptr);
public slots:
    QString getTask();
    QString getAnswer();
    QString getScore();
    QString getTime();
    QString getRecord();
    void decTime();
    void incScore();
    void returnValues();
    void setScoreInRecord();
    void saveRecord();
    void playSoundYes();
    void playSoundNo();
    void playStartSound();
};

#endif // TASKS_H
