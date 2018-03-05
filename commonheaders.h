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
QPair< QMap<short, short> , QList<QList<short> > > processNumberList(QString filename)
{
    QPair< QMap<short, short> , QList<QList<short> > > cloverfield;
    quint8 currInd = 0;
    quint8 linesCounter = 0;
    short maxValue=0;
    QList<short> temp;
    QList<QList<short>> pyramid;
    QMap<short, short> indicesOfMaxValues;
    QFile sourceFile(filename);
    sourceFile.open(QFile::ReadOnly);
    for (auto item: QString(sourceFile.readAll()).split("\n"))
    {
        currInd = 0;
        temp.clear();
        for(auto intSource: item.split(" "))
        {
            if(currInd == 0)
            {
                maxValue = intSource.toShort();
                indicesOfMaxValues.insert(linesCounter, currInd);
            }
            else if(intSource.toShort()==maxValue)
            {

                indicesOfMaxValues.insertMulti(linesCounter, currInd);
            }
            else if (intSource.toShort()>maxValue)
            {
                maxValue = intSource.toShort();
                indicesOfMaxValues.remove(linesCounter);
                indicesOfMaxValues.insert(linesCounter, currInd);
            }
            temp.append(intSource.toShort());
            currInd++;
        }
        pyramid.append(temp);
        maxValue = 0;
        linesCounter++;
    }
    sourceFile.close();
    cloverfield.first = indicesOfMaxValues;
    cloverfield.second = pyramid;

    return cloverfield;
}
void printIndPath()
{
    int followLength = 15;
    QString str = "";
    QVector<int> indList, cList;

    for(int i =0 ; i<followLength; i++)
    {
        indList.append(0);
        cList.append(i);
    }


    int counter = cList.last();
    int c = 0;
    int processingLine = followLength - 1;
    int deltaLine = 0;
    while(indList[3]!=cList[3]&&c<70)
    {

        if(indList[processingLine-deltaLine]-indList[processingLine-(deltaLine+1)]>1)
        {
            indList[processingLine-(deltaLine)]++;
            for(int i = followLength-1; i>processingLine-(deltaLine+1); i--)
            {
                indList[processingLine] = indList[processingLine-(deltaLine+1)];
            }
            deltaLine++;
        }

        for(auto i: indList)
        {
            str+=QString::number(i)+" ";
        }
        qDebug()<<"printIndPath"<<str;
        indList[followLength - 1]++;
        str.clear();



        //processingLine--;
        c++;

    }
}
class EBNode
{
    short value;
    EBNode * right, left;
}
/*
quint64 eulerFifteen()
{
    QPair<int, int> coord, final, start;
    start.first = 0;
    start.second = 0;
    QList<QPair<int, int>> route;
    QList<QList<QPair<int, int>>> routesList;
    int dimension = 5;
    uint currentCounter = 0 ;
    final.first = dimension;
    final.second = dimension;

    attachFileOuput("fifteen_"+QString::number(dimension)+".txt");
    qsrand(QDateTime::currentDateTime().toMSecsSinceEpoch());

    for(int i = 0; i<100000; i++)
    {
        coord = start;
        route.append(start);
        while(coord!=final)
        {
            if(qrand()%2 == 0)
            {
                if(coord.first<dimension)
                {
                    coord.first++;
                    route.append(coord);
                    currentCounter++;
                }
                currentCounter++;

            }
            else
            {
                if(coord.second<dimension)
                {
                    coord.second++;
                    route.append(coord);
                    currentCounter++;

                }
                currentCounter;
            }
        }
        if(!routesList.contains(route)) routesList.append(route);
        route.clear();
        qsrand(currentCounter);

    }

    foreach(auto temp, routesList)
    {

        for(auto i: temp)
        {

           ts<<"("<<i.first<<" ; "<<i.second<<")"<<"=>";

        }
        ts<<"\r\n";

    }

    answerFile.close();
    return routesList.count();
}*/
#endif // COMMONHEADERS_H

