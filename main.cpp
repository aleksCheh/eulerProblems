#include "commonheaders.h"
quint64 eulerOne();
quint64 eulerOne_2();
quint64 eulerTwo();
quint64 eulerThree();
quint64 eulerFour();
quint64 eulerFive();
quint64 eulerSix();
quint64 eulerSeven();
quint64 eulerEight();
void eulerNine();
quint64 eulerTen();
quint64 eulerEleven();
quint64 eulerTwelve();
QString eulerThirteen();
quint64 eulerFourteen();
quint64 eulerFifteen();
quint64 eulerSixteen();
quint64 eulerSeventeen();
quint64 eulerEighteen();
void runAnswers10();
void runAnswers20();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    runAnswers20();
    //qDebug()<<16%20;
    return 0;
}
void runAnswers20()
{
    QTime t;
    t.start();
    /*qDebug()<<"eulerEleven"<<eulerEleven();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerTwelve"<<eulerTwelve();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerThirteen"<<eulerThirteen();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerFourteen"<<eulerFourteen();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerFifteen"<<eulerFifteen();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerSixteen"<<eulerSixteen();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerSeventeen"<<eulerSeventeen();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();*/
    qDebug()<<"eulerEighteen"<<eulerEighteen();
    qDebug("Time elapsed: %d ms", t.elapsed());

}
void runAnswers10()
{

    QTime t;

    t.start();
    qDebug()<<"eulerOne"<<eulerOne();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerOne_2"<<eulerOne_2();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerTwo"<<eulerTwo();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerThree"<<eulerThree();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerFour"<<eulerFour();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerFive"<<eulerFive();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerSix"<<eulerSix();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerSeven"<<eulerSeven();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerEight"<<eulerEight();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    eulerNine();
    qDebug("Time elapsed: %d ms", t.elapsed());
    t.restart();
    qDebug()<<"eulerTen"<<eulerTen();
    qDebug("Time elapsed: %d ms", t.elapsed());
}
quint64 eulerOne()
{
    quint64 accum = 0;
    int i = 0;
    while(i<1000000)
    {
        accum +=i;
        i +=3;
    }
    i = 0;
    while(i<1000000)
    {
        if(i%3!=0)
        {
            accum +=i;
        }
        i +=5;
    }
    return accum;
}
quint64 eulerOne_2()
{
    quint64 i=0, accum =0;
    int offset[] = {3,2,1,3,1,2,3};
    int offsetIndex = 0;
    forever
    {
        if(offsetIndex == 7)
        {offsetIndex = 0;}
        i+=offset[offsetIndex++];
        if(i<1000)
        {accum +=i;}
        else
        {
            break;
        }

    }
    return accum;
}
quint64 eulerTwo()
{
    quint64 limit = 4000000;
    quint64 pna[] = {0,1};
    quint64 fibSum=0, result=0;
    while(fibSum<limit)
    {
        fibSum = pna[0]+pna[1];
        if(fibSum%2 ==0)
        {
            result+=fibSum;
        }
        pna[0] = pna[1];
        pna[1] = fibSum;
    }
 return result;
}
quint64 eulerThree()
{
    QVector<quint64> simpleNumbers;
    simpleNumbers.append(3);
    quint64 targetNumber = 600851475143;
    //quint64 targetNumber = 2000;
    quint64 checkSimpleNumber = 5;
    quint64 sqrtTargetNumber = sqrt(targetNumber);
    //qDebug()<<"sqrt(targetNumber)"<<sqrt(targetNumber);
    bool simple = true;
    forever
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
            //qDebug()<<"checkSimpleNumber"<<checkSimpleNumber;
        }
        if(checkSimpleNumber>sqrtTargetNumber)
        {
            break;
        }
        checkSimpleNumber+=2;
        simple = true;

    }
    for(int i = simpleNumbers.length()-1;i>0;i--)
    {
        if(targetNumber%simpleNumbers.at(i) ==0)
        {
            return simpleNumbers.at(i);
        }
    }
    return 1;

}
quint64 eulerFour()
{
    uint startNumber = 999999;
    short divider=999;
    bool palindrom = true;

    forever
    {
        QByteArray temp;
        temp.append(QString::number(startNumber));
        short midString = temp.length()/2;
        for(int i = 0; i<=midString; i++ )
        {
            if(temp.at(i)!=temp.at(temp.length()-1-i))
            {
                palindrom = false;
            }
        }
        if(palindrom)
        {
            for(int i = 999; i>100; i--)
            {
                if(startNumber%i==0&&startNumber/i>=100&&startNumber/i<1000)
                {
                    qDebug()<<i<<"x"<<startNumber/i <<"="<<startNumber;
                    return startNumber;
                }
            }
        }
        palindrom=true;
        if(startNumber<100001)
        {
            break;
        }
        startNumber --;
    }
return 0;

}
quint64 eulerFive()
{
    quint64 res = 40;
    bool bingo = false;
    forever
    {
        for(int i = 2; i<21; i++)
        {
            if(res%i!=0)
            {
                bingo=false;
                break;
            }
            bingo = true;
        }
        if(bingo)
        {
            return res;
        }
        res+=20;
    }

    return 0;
}
quint64 eulerSix()
{
    quint64 sumSquare = 0, squareSum = 0;
    for(int i = 1; i<=100;i++)
    {
        sumSquare+=qPow(i,2);
        squareSum+=i;
    }
    return qPow(squareSum,2)-sumSquare;

}
quint64 eulerSeven()
{
    QVector<quint64> simpleNumbers;
    simpleNumbers.append(2);
    simpleNumbers.append(3);
    simpleNumbers.append(5);
    simpleNumbers.append(7);
    simpleNumbers.append(11);
    simpleNumbers.append(13);
    uint counter = 6;
    bool simple = true;
    quint64 resNumber = 17;
    forever
    {
        for(auto i: simpleNumbers)
        {
            if(resNumber%i==0)
            {
                simple = false;
            }
        }
        if (simple)
        {
            simpleNumbers.append(resNumber);
            counter++;
        }

        simple = true;
        resNumber +=2;
        if (counter == 10001)
        {break;}
    }
   // qDebug()<<simpleNumbers.count();
return simpleNumbers.last();
}
quint64 eulerEight()
{
    int startOffset =0;
    quint64 maxMult = 0, currMult = 0;
    QByteArray initialArray("73167176531330624919225119674426574742355349194934"
                            "96983520312774506326239578318016984801869478851843"
                            "85861560789112949495459501737958331952853208805511"
                            "12540698747158523863050715693290963295227443043557"
                            "66896648950445244523161731856403098711121722383113"
                            "62229893423380308135336276614282806444486645238749"
                            "30358907296290491560440772390713810515859307960866"
                            "70172427121883998797908792274921901699720888093776"
                            "65727333001053367881220235421809751254540594752243"
                            "52584907711670556013604839586446706324415722155397"
                            "53697817977846174064955149290862569321978468622482"
                            "83972241375657056057490261407972968652414535100474"
                            "82166370484403199890008895243450658541227588666881"
                            "16427171479924442928230863465674813919123162824586"
                            "17866458359124566529476545682848912883142607690042"
                            "24219022671055626321111109370544217506941658960408"
                            "07198403850962455444362981230987879927244284909188"
                            "84580156166097919133875499200524063689912560717606"
                            "05886116467109405077541002256983155200055935729725"
                            "71636269561882670428252483600823257530420752963450");
    QByteArray temp;
    while(startOffset+12<initialArray.length())
    {
        temp = initialArray.mid(startOffset,13);
        if(temp.contains('0'))
        {
            //qDebug()<<temp;
            //startOffset++;

        }
        else
        {
            //qDebug()<<temp;
            for(int i = 0; i<13; i++)
            {
                if (i ==0)
                {
                    QString s(temp.at(i));
                    currMult =s.toInt();
                }
                else
                {
                    QString s(temp.at(i));
                    currMult *=s.toInt();
                }
            }

        }
        startOffset++;
        if(currMult>maxMult)
        {
            maxMult = currMult;
        }

    }
    qDebug()<<maxMult;
    return maxMult;

}

void eulerNine()
{
    QVector<uint> squares;
    for (int i = 1; i<1001;i++)
    {
        squares.append(qPow(i,2));
    }
    int counter = 3;

    while(counter<1000)
    {
        for(int i = 0;i<=counter-1;i++)
        {
            for(int j = 0; j<=counter-2;j++)
            {
                if(squares.at(i)+squares.at(j)==squares.at(counter)&&(i+1)+(j+1)+(counter+1)==1000)
                {
                    qDebug()<<"eulerNine"<<(i+1)*(j+1)*(counter+1);
                    return;

                    //qDebug()<<"a"<<i<<squares.at(i)<<"b"<<j<<squares.at(j)<<"c"<<counter<<squares.at(counter);
                }
            }
        }
        counter++;
    }
}

quint64 eulerTen()
{
    quint64 accum = 0;
    QList<int> simpleNumbers;
    int targetSqrt = qSqrt(2000000);
    QList<int> rawSimpleNumbers;
    rawSimpleNumbers.append(3);
    QLinkedList<int> allNumbers;
    for(int i = 3; i<2000000; i+=2)
    {
        allNumbers.append(i);
    }
    auto iterator = rawSimpleNumbers.begin();
    bool simple = true;
    for(int i = 3; i<targetSqrt; i+=2)
    {
      while(iterator!=rawSimpleNumbers.end())
      {
          if(i%(*iterator)==0)
          {
              simple = false;
              break;
          }
          iterator++;
      }
      if(simple)
      {
          rawSimpleNumbers.append(i);
      }
      simple = true;
      iterator = rawSimpleNumbers.begin();
    }

    QMutableLinkedListIterator<int> mIterator(allNumbers);
    for(auto i: rawSimpleNumbers)
    {
        while(mIterator.hasNext())
        {
            int val = mIterator.next();
            if(val%i==0&&val!=i)
            {
                mIterator.remove();
            }
        }
        mIterator.toFront();
    }

    accum = 2;
    for (auto i: allNumbers)
    {
        accum+=i;
    }
    return accum;
}
quint64 eulerEleven()
{
    int rowLength = 20, colLength = 20;
    int max = 0;
    QVector<int> res;
    res.resize(6);
    QString initialArray(   "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
                            "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
                            "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
                            "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
                            "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
                            "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
                            "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
                            "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
                            "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
                            "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
                            "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
                            "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
                            "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
                            "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
                            "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
                            "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
                            "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
                            "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
                            "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
                            "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48"
                            );
    QStringList parsedNumber = initialArray.split(' ');
    QVector<int> initVector;

    foreach(QString s, parsedNumber)
    {
        initVector.append(s.toInt());
    }
    //qDebug()<<parsedNumber.count();
    //qDebug()<<initVector.count();
    for(int i = 0; i<initVector.length(); i++)
    {
        if(i!=0)
        {
            if(i<16||i%rowLength<16)
            {
                res[0] = initVector.at(i)*initVector.at(i+1)*initVector.at(i+2)*initVector.at(i+3);
                //qDebug()<<"horiz"<<initVector.at(i)<<initVector.at(i+1)<<initVector.at(i+2)<<initVector.at(i+3);
            }
            if(i<340)
            {
                res[1] = initVector.at(i)*initVector.at(i+20)*initVector.at(i+40)*initVector.at(i+60);
                //qDebug()<<"vert"<<initVector.at(i)<<initVector.at(i+20)<<initVector.at(i+40)<<initVector.at(i+60);
            }
            if(i/colLength>2&&i%rowLength>2)
            {
                res[2] = initVector.at(i)*initVector.at(i-19)*initVector.at(i-38)*initVector.at(i-57);
                //qDebug()<<"rUDiag"<<initVector.at(i)<<initVector.at(i-19)<<initVector.at(i-38)<<initVector.at(i-57);
            }
            if(i/colLength>2&&i%rowLength>2)
            {
                res[3] = initVector.at(i)*initVector.at(i-21)*initVector.at(i-42)*initVector.at(i-63);
                //qDebug()<<"lUDiag"<<initVector.at(i)<<initVector.at(i-21)<<initVector.at(i-42)<<initVector.at(i-63);
            }
            if(i/colLength<17&&i%rowLength<17)
            {
                res[4] = initVector.at(i)*initVector.at(i+21)*initVector.at(i+42)*initVector.at(i+63);
                //qDebug()<<"rDDiag"<<initVector.at(i)<<initVector.at(i+21)<<initVector.at(i+42)<<initVector.at(i+63);
            }
            if(i/colLength<17&&i%rowLength>2)
            {
                res[5] = initVector.at(i)*initVector.at(i+19)*initVector.at(i+38)*initVector.at(i+57);
                //qDebug()<<"lDDiag"<<initVector.at(i)<<initVector.at(i+19)<<initVector.at(i+38)<<initVector.at(i+57);
            }
            for(auto i: res)
            {
                if(i>max)
                {
                    max = i;
                }
            }
        }
    }
    return max;
}
quint64 eulerTwelve()
{
    QFile f;
    f.setFileName("eulerTwelve.txt");
    f.open(QFile::WriteOnly | QFile::Truncate);
    QTextStream ts;
    ts.setDevice(&f);
    QList<int> simple;
    simple = simpleNumbers(10000);

    quint64 res = 1;
    QHash<int, int> simpleDivisors;
    quint64 triangleNumber = 2;
    quint64 iterator;
    quint64 accum=0, tempAccum;

    while(triangleNumber<100000)
    {
        res = 1;
        accum = 0;
        iterator = triangleNumber;
        while(iterator>0)
        {
            accum+=iterator;
            iterator--;
        }
        triangleNumber++;
        tempAccum = accum;
        for(auto i: simple)
        {
            if(accum == 1)
            {
                break;
            }
            while(accum%i==0)
            {
                if(simpleDivisors.contains(i))
                {
                    int temp = simpleDivisors.value(i);
                    temp++;
                    simpleDivisors.insert(i,temp);
                }
                else
                {
                    simpleDivisors.insert(i,1);
                }
                accum /= i;
            }
        }
        foreach(int val, simpleDivisors)
        {
            res*= (val+1) ;
        }

        res+=2;
        if(res>500)
        {
            return tempAccum;
        }
        simpleDivisors.clear();
    }

    f.close();   
    return res;
}
QString eulerThirteen()
{
    QFile f("task13.txt");
    f.open(QFile::ReadOnly);
   // QList<QByteArray> initialNumbers = f.readAll().split('\n');
    QStringList initialNumbers = QString(f.readAll()).split("\n");
    f.close();

    int addRes = 0, stringCounter = 0, numberLength = 49;
    QString resultString, tempResult;
    QString temp;
    while(numberLength>=0)
    {
        while(stringCounter<100)
        {
           temp = initialNumbers.at(stringCounter).at(numberLength);
           addRes +=temp.toInt();
           stringCounter++;
        }

        tempResult.append(QString::number(addRes%10));
        resultString.prepend(tempResult);
        tempResult.clear();
        addRes/=10;
        numberLength--;
        stringCounter = 0;
    }
    tempResult.append(QString::number(addRes));
    resultString.prepend(tempResult);

    return resultString.left(10);;
}
quint64 eulerFourteen()
{
    QHash<uint, uint> total;
    uint number = 13;
    uint kollatzCount, kollatzNumber;


    while(number<1000000)
    {
        kollatzNumber = number;

        while(kollatzNumber!=1)
        {
            if(kollatzNumber%2!=0)
            {
                kollatzNumber = 3*kollatzNumber + 1;
                kollatzCount++;
            }
            else
            {
                kollatzNumber /=2;
                kollatzCount++;
            }
        }

        total.insert(number,kollatzCount+1);
        kollatzCount = 0;
        number++;
    }

    uint maxValue=0;
    uint maxKey = 0;
    auto i = total.constBegin();

    while(i!=total.constEnd())
    {
        if(i.value()>maxValue)
        {
            maxValue = i.value();
            maxKey = i.key();
        }
        ++i;
    }

    return maxKey;
}
quint64 eulerFifteen()
{
    QList<QVector<quint64> > allVectors;
    QVector<quint64> temp, nextTemp;
    temp.append(1);
    temp.append(2);
    allVectors.append(temp);
    for (int counter = 0; counter<19;counter++)
    {
        nextTemp.append(1);
        for(int i = 1; i<temp.count(); i++)
        {
            nextTemp.append(temp.at(i)+nextTemp.at(i-1));
        }
        nextTemp.append(nextTemp.last()*2);
        temp = nextTemp;
        nextTemp.clear();
        //qDebug()<<counter+2<<"---"<<temp.last();
    }
    return temp.last();
}

quint64 eulerSixteen()
{
    short power = 1;
    quint64  init = qPow(2, power);
    QString temporaryNumber = QString::number(init);
    QString temporaryString = "";
    uchar theOne = 0;
    int powCounter = power;

    while(powCounter<1000)
    {
        for(int i = temporaryNumber.length()-1; i>=0; i--)
        {
            int tempInt = 2*temporaryNumber.mid(i,1).toInt();

            if(i != 0)
            {
                temporaryString.prepend(QString::number(tempInt%10+theOne));
                theOne = tempInt/10;
            }
            else
            {
                temporaryString.prepend(QString::number(tempInt+theOne));
                theOne = 0;
            }
        }

        temporaryNumber = temporaryString;
        temporaryString.clear();
        powCounter++;
    }

    quint64 finalSum = 0;

    for(int i = 0; i<temporaryNumber.length(); i++)
    {
        finalSum+=temporaryNumber.mid(i, 1).toInt();
    }

    return finalSum;
}
quint64 eulerSeventeen()
{
    attachFileOuput("seventeen.txt");

    QStringList onesS, tensS;
    tensS.append("");
    tensS.append("");
    tensS.append("twenty");
    tensS.append("thirty");
    tensS.append("forty");
    tensS.append("fifty");
    tensS.append("sixty");
    tensS.append("seventy");
    tensS.append("eighty");
    tensS.append("ninety");

    onesS.append("");
    onesS.append("one");
    onesS.append("two");
    onesS.append("three");
    onesS.append("four");
    onesS.append("five");
    onesS.append("six");
    onesS.append("seven");
    onesS.append("eight");
    onesS.append("nine");
    onesS.append("ten");
    onesS.append("eleven");
    onesS.append("twelve");
    onesS.append("thirteen");
    onesS.append("fourteen");
    onesS.append("fifteen");
    onesS.append("sixteen");
    onesS.append("seventeen");
    onesS.append("eighteen");
    onesS.append("nineteen");

    int tempInt = 0;
    QString resultString = "";

    for(int i = 1; i<1000;i++)
    {
        tempInt = i;
        ts<<QString::number(tempInt)<<"\r\n";
        int h =0, d = 0, o = 0;
        h = tempInt/100;
        d = (tempInt-100*h)/10;
        o = (tempInt-100*h)-d*10;
        if(h)
        {
            if(d||o)
            {
                ts<<onesS.at(h)+" hundred and ";
                resultString+=onesS.at(h)+" hundred and ";
            }
            else
            {
                ts<<onesS.at(h)+" hundred"<<"\r\n";
                resultString+=onesS.at(h)+" hundred";               
                continue;
            }
        }
        if(d)
        {
            if(d>1)
            {                
                ts<<tensS.at((tempInt-100*h)/10)<<" ";
                resultString+=tensS.at((tempInt-100*h)/10);
            }
            else
            {               
                ts<<onesS.at((tempInt-100*h))<<"\r\n";
                resultString+=onesS.at((tempInt-100*h));
                continue;
            }
        }

        ts<<onesS.at(o)<<"\r\n";
        resultString+=onesS.at(o);        
    }

    detachFileOutput();
    resultString.replace(" ","");
    return resultString.length()+11; //+one thousand
}

quint64 eulerEighteen()
{
    int result = 0;
    quint8 currInd = 0;
    quint8 linesCounter = 0;
    //short maxValue=0;

    auto procRes = processNumberList("task18.txt");
    auto pyramid = procRes.second;
    auto indicesOfMaxValues = procRes.first;

    while(linesCounter<pyramid.count()-1)
    {
        result+=pyramid.at(linesCounter).at(currInd);
        qDebug()<<pyramid.at(linesCounter).at(currInd);
        if(pyramid.at(linesCounter+1).at(currInd)<=pyramid.at(linesCounter+1).at(currInd+1))
        {
            currInd++;
        }
        linesCounter++;
    }



    result+=pyramid.at(linesCounter).at(currInd);
    int maxSum = 0;
    linesCounter =0;
    auto i = indicesOfMaxValues.cbegin();
    while(i!= indicesOfMaxValues.cend())
    {
        qDebug()<<i.key()<<"<=>"<<i.value();
        ++i;
    }

    qDebug()<<"maxSum: "<<maxSum;
    EBTree * ebtree = new EBTree();
    ebtree->setRoot(pyramid.at(0).at(0));
    ebtree->root->appendRight(ebtree->root, pyramid.at(1).at(0));
    ebtree->root->appendRight(ebtree->root, pyramid.at(1).at(1));



    return result;
}
