#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int sumArray(int *arrList, int arrLen)
{

    int arrSum = 0;
    cout << "\narray length: " << arrLen;
    for (int i = 0; i < arrLen; i++)
    {
        arrSum += arrList[i];
        // cout << arrList[i] << endl;
    }
    return arrSum;
}

int main()
{
    int numList = 0;
    int totalArr = 0;
    cout << "Enter number of items to sum: ";
    cin >> numList;
    int arrNum[numList];

    for (int i = 0; i < numList; i++)
    {
        cout << "Enter item " << i << ": ";
        cin >> arrNum[i];
        // cout << arrNum[i];
    }

    totalArr = sumArray(arrNum, numList);

    cout << "\nSum of arrays: " << totalArr << endl;
    return 0;
}