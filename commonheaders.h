#ifndef COMMONHEADERS_H
#define COMMONHEADERS_H
#include <QCoreApplication>
#include <QDebug>
#include <QTime>
#include <QVector>
#include <QtMath>
#include <QMutableListIterator>
#include <QLinkedList>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QPen>
#include <QPainter>
#include <QImage>
QFile answerFile;
QTextStream ts;
void attachFileOuput(QString filename)
{
    answerFile.setFileName(filename);
    ts.setDevice(&answerFile);
    answerFile.open(QFile::WriteOnly | QFile::Truncate);
    qDebug()<<"Don't forget detach output file";
}
void detachFileOutput()
{
    answerFile.close();
    qDebug()<<"output file detached";
}
QList<int> simpleNumbers(int limit)
{
    QList<int> simpleNumbers;
    simpleNumbers.append(2);
    simpleNumbers.append(3);
    int checkSimpleNumber = 5;
    bool simple = true;
    while(checkSimpleNumber<limit)
    {
        for(auto i: simpleNumbers)
        {
            if(checkSimpleNumber%i ==0)
            {
                simple = false;
                break;
            }
        }
        if(simple)
        {
            simpleNumbers.append(checkSimpleNumber);
        }
        checkSimpleNumber+=2;
        simple = true;
    }
    return simpleNumbers;
}
#endif // COMMONHEADERS_H
