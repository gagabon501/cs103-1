/**********************************************************************************************************************
 *    CS-103 Integrated Studio I Assessment 1 - Question2: Sums the contents of an integer array and returns the result
 *    @file Q2_sumArray.cpp
 *    @author Gilberto Gabon
 *    @version 1 / 29-May-2022
 **********************************************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes
int sumArray(int *arrList, int arrLen);

int main()
{
    int numList = 0;
    int totalArr = 0;
    cout << "Enter number of items to sum: ";
    cin >> numList;
    int arrNum[numList];

    for (int i = 0; i < numList; i++)
    {
        cout << "Enter value for item " << i + 1 << ": ";
        cin >> arrNum[i];
        while (arrNum[i] < 0)
        {
            cout << "Invalid entry. Enter only non-negative value.\n";
            cout << "Enter value for item " << i + 1 << ": ";
            cin >> arrNum[i];
        }
    }

    totalArr = sumArray(arrNum, numList);

    cout << "\nContents of array: " << endl;
    for (int i = 0; i < numList; i++)
    {
        cout << "arrNum[" << i << "] = " << arrNum[i] << "\n";
    }
    cout << "\nSum of array: " << totalArr << endl;
    return 0;
}

int sumArray(int *arrList, int arrLen)
/*************************************************************************************
 * Purpose: Sum the contents of the array passed as a parameter and returns the result
 *************************************************************************************/

{
    int arrSum = 0;
    for (int i = 0; i < arrLen; i++)
    {
        arrSum += arrList[i];
    }
    return arrSum;
}
