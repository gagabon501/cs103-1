/*********************************************************************************************************************************************************************
 *    CS-103 Integrated Studio I Assessment 1 - Question3: Program to sum two (2) matrices and save the result in a 3rd matrix and multiply by 3 the resultant matrix
 *    @file Q3_sumMatrices.cpp
 *    @author Gilberto Gabon
 *    @version 1 / 29-May-2022
 ***********************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function Prototypes
void displayMatrix(int matrix[][3], int length, string title);
void addTwoMatrices(int matrixA[][3], int matrixB[][3], int length);

int main()
{
    int matrixA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixB[3][3] = {{5, 6, 9}, {6, 4, 7}, {8, 2, 1}};

    cout << "This program will add two matrices (A & B) then store the result into Matrix C. Matrix C is then multiplied by 3.\n";
    cout << "=================================================================================================================\n\n";

    displayMatrix(matrixA, 3, "     Matrix A");

    cout << "\n";

    displayMatrix(matrixB, 3, "     Matrix B");

    addTwoMatrices(matrixA, matrixB, 3);

    return 0;
}

void displayMatrix(int matrix[][3], int length, string title)
/******************************************
 * Purpose: Display contents of the matrix
 ******************************************/
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
/****************************************************************************************************************************
 * Purpose: Add two matrices passed as parameters and save it in another matrix (C). Multiply then contents of Matrix C by 3.
 ****************************************************************************************************************************/
{
    int matrixC[3][3]; // Matrix to hold sum of the two matrices A&B

    // Sum the two matrices A&B
    for (int i = 0; i < length; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            matrixC[i][j] = (matrixA[i][j] + matrixB[i][j]);
        }
    }

    cout << "\n";
    displayMatrix(matrixC, 3, "     Matrix C"); // Display resultant matrix

    // Multiply Matrix-C by 3
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrixC[i][j] *= 3;
        }
    }

    cout << "\n";
    displayMatrix(matrixC, 3, "   Matrix C x 3"); // Display the resultant matrix after multiplying by 3
}