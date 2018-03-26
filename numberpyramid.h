#ifndef NUMBERPYRAMID_H
#define NUMBERPYRAMID_H
#pragma once
#include <QPair>
#include <QFile>
#include "chain.h"

class NumberPyramid
{
public:
    NumberPyramid();
    NumberPyramid(QString filename): NumberPyramid(){this->readData(filename);}
    NumberPyramid(const char* string) : NumberPyramid(QString(string)) {}
    NumberPyramid(const NumberPyramid &);
    void readData(QString filename);
    void showMaxSum();
    Chain innerChain;
    short contentLineCount();
    void showPath(int maxSumInd);
    void slice();
private:
    QList<QList<short>> content;
    QMap <short, short> maxValueIndices;


    NumberPyramid slice(const NumberPyramid &np, short line, short index, short height);
    int findMaxPath();
    void fillInnerChain();




};

#endif // NUMBERPYRAMID_H
