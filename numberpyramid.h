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
    NumberPyramid(QString filename);
    NumberPyramid(const NumberPyramid &);
    void readData(QString filename);
    void showMaxSum();
private:
    QList<QList<short>> content;
    QMap <short, short> maxValueIndices;


    NumberPyramid slice(const NumberPyramid &np, short line, short index, short height);



};

#endif // NUMBERPYRAMID_H
