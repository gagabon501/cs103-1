#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void displayMatrix(int matrix[][3], int length, string title)
{
    string numString = "";
    cout << title << "\n";
    cout << " +--------------+\n";
    for (int i = 0; i < length; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] < 10)
            {
                numString = "0" + to_string(matrix[i][j]);
            }
            else
            {
                numString = to_string(matrix[i][j]);
            }

            cout << " | " << numString;
        }
        cout << " |\n";
        cout << " +--------------+\n";
    }
}

void addTwoMatrices(int matrixA[][3], int matrixB[][3], int length)
{
    int matrixC[3][3];
    for (int i = 0; i < length; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            matrixC[i][j] = (matrixA[i][j] + matrixB[i][j]) * 3;
        }
    }

    cout << "\n";
    displayMatrix(matrixC, 3, "     Matrix C");
}

int main()
{
    int matrixA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[3][3] = {{5, 6, 9}, {6, 4, 7}, {8, 2, 1}};

    displayMatrix(matrixA, 3, "     Matrix A");

    cout << "\n";

    displayMatrix(matrixB, 3, "     Matrix B");

    addTwoMatrices(matrixA, matrixB, 3);

    return 0;
}