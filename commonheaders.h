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

class EBNode
{
    public:
        short value;
        EBNode * right;
        EBNode * left;
        EBNode * parent;
        EBNode()
        {
            parent = NULL;
            value = 0;
            left = NULL;
            right = NULL;
        }
        EBNode * getRight()
        {
            return this->right;
        }
        EBNode * getLeft()
        {
            return this->left;

        }
        void appendLeft(short value)
        {
           //qDebug()<<"appendLeft"<<value;
           this->left  = new EBNode();
           this->left->value = value;
           this->left->parent = this;

        }
        void appendRight(short value)
        {
           //qDebug()<<"appendRight"<<value;
           this->right  = new EBNode();
           this->right->value = value;
           this->right->parent = this;
        }
        bool isRight()
        {
            if(this->parent&&this == parent->right)
            {
                return true;
            }
            return false;
        }

};

class EBTree
{
    public:
        EBNode * root;
        EBNode * currentNode;
        bool lineFinished;
        EBTree()
        {
            root = NULL;
            currentNode = NULL;
        }
        bool removeEBNode();
       // void startNewLine();

        //декларасьон===============================================================
bool createRoot(short value)
{
        root  = new EBNode();
        root->parent = NULL;
        root->value = value;
}
bool append(short value)
{
    if(root == NULL)
    {
        this->createRoot(value);
        currentNode = root;
       // qDebug()<<"root append"<<root->value;
        //qDebug()<<"currentNode->value"<<currentNode->value;
        return true;
    }
    else if(currentNode->left==NULL)
    {
        currentNode->appendLeft(value);
        return true;
    }
    else if(currentNode->right==NULL)
    {
        currentNode->appendRight(value);
        if(isLineEnd())
        {
            startNewLine();
        }
        else
        {
            while(currentNode==currentNode->parent->right)
            {
                currentNode = currentNode->parent;
            }
            currentNode = currentNode->parent->right;
        }
        //qDebug()<<"currentNode->value"<<currentNode->value;
        return true;
    }
    else if(currentNode->left&&currentNode->right)
    {
        goDown();
        currentNode->appendLeft(value);
        //qDebug()<<"currentNode->value"<<currentNode->value;
        return true;

    }


    //qDebug()<<"currentNode->value"<<currentNode->value;
    return false;
}

bool isLineEnd()
{
    while(currentNode->parent!=NULL)
    {
        if(!currentNode->isRight())
        {
            return false;
        }
        currentNode = currentNode->parent;
    }
    return true;
}
void startNewLine()
{

    currentNode = this->root;
    while(currentNode->left!=NULL)
    {
        currentNode = currentNode->left;
    }
    qDebug()<<"startNewLine"<<currentNode->value;
    return;
}
void goDown()
{
    while(currentNode->left)
    {
        currentNode = currentNode->left;
    }
}
void showLineValues(short lineNumber)
{
    const int z = 12;
    const int * c = &z;
}

};

class chainNode
{
public:

    chainNode(){
        maxValue = 0;
        value = 0;
        nextNode = NULL;
        previousNode = NULL;
    }
    chainNode(short val, short mVal):value(val), maxValue(mVal)
    {
        nextNode = NULL;
        previousNode = NULL;
    }

    short maxValue;
    short value;
    chainNode *nextNode;
    chainNode *previousNode;
};
class Chain
{
public:
    Chain()
    {
        elementCount =0;
        first = new chainNode(0,0);
        last = new chainNode(0,0);
        first->nextNode = last;
        last->previousNode = first;
        current = NULL;
        indPath.clear();
    }
    void append(short value, short maxValue)
    {
        elementCount++;
        chainNode * tempNode = new chainNode(value, maxValue);
        if(last->previousNode  == first)
        {
            last->previousNode = tempNode;
            tempNode->previousNode = first;
            tempNode->nextNode = last;
            first->nextNode = tempNode;
        }
        else
        {
            tempNode->previousNode = last->previousNode;
            last->previousNode->nextNode =  tempNode;
            tempNode->nextNode = last;
            last->previousNode = tempNode;
        }
    }

    void combCount()
    {
        int counter = 0;
        chainNode *n = this->last->previousNode;
        while(valuesInRange())
        {
                //showValues();
                valuesToShortList();
                n->value++;
                normalize();
                counter++;
        }
        qDebug()<<"COUNTER"<<counter;
    }

    void showValues()
    {
        chainNode * z  = this->first->nextNode;
        QString temp = "";
        while(z!=this->last)
        {
           temp.append(QString::number(z->value)+"=>");
           z = z->nextNode;
        }
        temp.remove(temp.length()-2,2);
        qDebug()<<temp;
    }

    void normalize()
    {
        chainNode * z = this->last->previousNode;
        chainNode * x;
        while(z!=this->first)
        {
            if(z->value-z->previousNode->value>1)
            {
                z->previousNode->value++;
                for(x = z->previousNode; x!= this->last; x = x->nextNode)
                {
                    x->value = z->previousNode->value;
                }
            }
            z = z->previousNode;
        }

    }

    bool valuesInRange()
    {
        chainNode * z = this->last->previousNode;
        while(z!=this->first)
        {
            if(z->value>z->maxValue)
            {
                return false;
            }
            z = z->previousNode;
        }
        return true;
    }

void valuesToShortList()
{
    chainNode * z  = this->first->nextNode;
    QList<short> temp;
    while(z!=this->last)
    {
       temp.append(z->value);
       z = z->nextNode;
    }
    indPath.append(temp);
}
    int elementCount ;
    chainNode *first;
    chainNode *last;
    chainNode *current;
    QList<QList<short> > indPath;

};


#endif // COMMONHEADERS_H

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
