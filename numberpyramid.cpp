#include "numberpyramid.h"

NumberPyramid::NumberPyramid()
{
    this->content.clear();
    this->maxValueIndices.clear();
}

void NumberPyramid::readData(QString filename)
{
    quint8 currInd = 0;
    quint8 linesCounter = 0;
    short maxValue=0;
    QList<short> temp;
    QList<QList<short>> pyramid;
    QMap<short, short> indicesOfMaxValues; /*<номерСтроки, индексЭлемента>*/
    QFile sourceFile(filename);
    sourceFile.open(QFile::ReadOnly);
    for (auto item: QString(sourceFile.readAll()).split("\n")) /*этот цикл разделяет строки*/
    {
        currInd = 0;
        temp.clear();
        for(auto intSource: item.split(" ")) /*этот цикл разделяет элементы и ищет максимальный в каждой строке*/
        {
            if(currInd == 0)
            {
                maxValue = intSource.toShort();         /*первый элемент автоматически становится наибольшим*/
                indicesOfMaxValues.insert(linesCounter, currInd);       /*и добавляется в QMap*/
            }
            else if(intSource.toShort()==maxValue)
            {
//                на случай дублирования наибольшего элемента в строке, т. е. добавляется еще один индекс
//                с тем же номером строки
                indicesOfMaxValues.insertMulti(linesCounter, currInd);
            }
            else if (intSource.toShort()>maxValue)      /*если попадается больше чем добавленный*/
            {
                maxValue = intSource.toShort();
                indicesOfMaxValues.remove(linesCounter); /*удаляет все записи с текущим номером строки*/
                indicesOfMaxValues.insert(linesCounter, currInd); /*вставляет новую пару значений*/
            }
            temp.append(intSource.toShort());
            currInd++;
        }
        pyramid.append(temp);
        maxValue = 0;
        linesCounter++;
    }
    sourceFile.close();
    this->content = pyramid;
    this->maxValueIndices = indicesOfMaxValues;
}

void NumberPyramid::slice()
{
    NumberPyramid smallPyramid;
    for(int i = 0; i<4; i++)
        smallPyramid.content.append(this->content.at(i));
    smallPyramid.showPath(smallPyramid.findMaxPath());
}

short NumberPyramid::contentLineCount()
{
    return content.count();
}


NumberPyramid NumberPyramid::slice(const NumberPyramid &np, short line, short index, short height)
{
    NumberPyramid retNp;/*
    for(int i = 0; i<height; i++)
    {
        retNp.content.append(QList<short>);
        int c = 0;
        while(c<=i)
        {
            retNp.content.at(i).append(np.content.at(line+i).at(index+c));
            c++;
        }

    }*/
    return retNp;
}

int NumberPyramid::findMaxPath()
{
    this->fillInnerChain();
    innerChain.combCount(); //здесь создается список индексов прохождения.
    int maxSumInd = 0, forCounter = 0, result = 0, maxSum =0;
    for(auto list: innerChain.indPath)
    {
        for(int i = 0; i<this->contentLineCount(); i++)
        {
            result += this->content.at(i).at(list.at(i));
        }
        if(result>maxSum)
        {
            maxSum = result;
            maxSumInd = forCounter;
        }
        result = 0;
        forCounter++;
    }
    return maxSumInd;
}

//Добавляет во внутренний список пары значений (начальноеЗначение/максимальноеЗначение)
void NumberPyramid::fillInnerChain()
{
    short e = 0;
    while(e<this->contentLineCount())
    {
        innerChain.append(0,e);
        e++;
    }
}

void NumberPyramid::showPath(int maxSumInd)
{
    QString temp;
    auto z = innerChain.indPath.at(maxSumInd);
    for(auto s: z)
    {
        temp+=QString::number(s)+"->";
    }
    qDebug()<<temp;
}



//void NumberPyramid::showMaxSum()
//{
//    fillPossibleWays();
//}

//void NumberPyramid::fillPossibleWays()
//{

//    QMap<short, short> matchMap;
//    int branchCount = 1;
//    for(short i = 0; i<content.length(); i++)
//    {
//        short matchCounter = 0;
//        auto pair = this->maxValueIndices.equal_range(i);
//        while(pair.first != pair.second)
//        {
//            pair.first.key();
//            pair.first++;
//            matchCounter++;
//        }
//        branchCount*=matchCounter;
//        matchMap.insert(i,matchCounter);
//        qDebug()<<"i"<<i<<"matchCounter"<<matchCounter;
//    }
//    qDebug()<<"branchCount"<<branchCount;

//    QList<QList<short>> tree;
//}

//NumberPyramid::content NumberPyramid::slice(NumberPyramid)
//{

//}
