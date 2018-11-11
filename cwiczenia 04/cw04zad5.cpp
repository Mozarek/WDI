#include <iostream>

using namespace std;

int main()
{
    int tempSum;

    /////////////////////////////////
    int maxCol = 0;
    int minCol = 0;

    int maxSumCol = 0;
    for(int i =0;i<MAX;i++)
        maxSumCol+=tab[i][0];
    int minSumCol = maxSumCol;


    for(int i =1; i<MAX ;i++)
    {
        tempSum = 0;
        for(int j = 0; j<MAX ;j++)
            tempSum+=tab[j][i];

        if(tempSum > maxSumCol)
        {
            maxSumCol = tempSum;
            maxCol = i;
        }
        else if(tempSum < minSumcol)
        {
            minSumCol = tempSum;
            minCol =i;
        }
    }

    //flagujemy czy znalezlismy dodatnie/ujemne sumy
    bool negative = false;
    bool positive = false;

    if(minSumCol <0)
        negative = true;

    if(maxSumCol >0)
        positive = true;

    ////////////////////////////////////////////////
    //

    int maxNegRow;
    int minPosRow;

    int maxNegSumRow;
    int minPosSumRow;

    bool firstPosMin = true;
    bool firstNegMax = true;

    for(int i = 0; i<MAX ;i++)
    {
        tempSum = 0;
        for(int j = 0; j<MAX ;j++)
            tempSum+=tab[i][j];

        if(tempSum>0 && positive && (firstPosMin || tempSum<minPosSumRow))
        {
            minPosSumRow = tempSum;
            minPosRow = i;
        }
        else if(tempSum <0 && negative && (firstNegMax || tempSum > maxNegSumRow))
        {
            maxNegSumRow = tempSum;
            maxNegRow = i;
        }
    }

    double quotientPos = -1;
    double quotientNeg = -1;

    if(positive && !firstPosMin)
        quotientPos = (maxSumCol*1.0)/minPosSumRow;

    if(negative && !firstNegMax)
        quotientNeg = (minSumCol*1.0)/maxNegSumRow;

    if(quotientPos > quotientNeg)
    {
        cout << "x: " << minPosRow << endl;
        cout << "y: " << maxCol << endl;
    }
    else
    {
        cout << "x: " << maxNegRow << endl;
        cout << "y: " << minCol << endl;
    }

    return 0;
}
