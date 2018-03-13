#ifndef CHAIN_H
#define CHAIN_H
#include <QList>
#include <QDebug>
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
    Chain(int height)
    {
        Chain();
        for(int i = 0 ; i<height; i++)
        {
            this->append(0,i);
        }
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
        while(z!=this->first)   /*пока не достигнуто начало(самая верхняя строка)*/
        {
            if(z->value-z->previousNode->value>1)       /*если текущий индекс нижней строки больше*/
                                                            /*индекса верхней строки на 2*/
            {
                z->previousNode->value++;               /*увеличиваем индекс верхней строки*/
                for(x = z->previousNode; x!= this->last; x = x->nextNode)
                {
                    x->value = z->previousNode->value;  /*все низлежащие выравниваем по индексу
                                                            верхней изменившейся строки*/
                }
            }
            z = z->previousNode;        /*переходим на узел выше*/
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
    QList<QList<short>> indPath;

};

#endif // CHAIN_H
