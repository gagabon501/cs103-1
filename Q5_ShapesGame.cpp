/********************************************************************************************************************************************************************************
 *    CS-103 Integrated Studio I Assessment 1 - Question5: Identify the Shapes game. User is displayed with a shape and selects the name of the shape from the choices presented.
 *    @file Q5_ShapesGame.cpp
 *    @author Gilberto Gabon
 *    @version 1 / 29-May-2022
 ********************************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function Prototypes
void drawSquare();
void drawTriangle();
void drawRectangle(int height, int width);
void showOptions();
void pickQuestion(int questionNumber);

void playGame(int *ptrTotalScore);
void showFinalScore(int totalScore);
int calculateScore(int totalScore);
int showMenu(int totalScore);
string correctAnswer(int questionNumber);

int main()
{

    // variable definitions
    int menuChoice = 0;
    int totalScore = 0;
    int *ptrTotalScore = &totalScore;

    while (menuChoice != 3)
    {
        menuChoice = showMenu(totalScore);
        switch (menuChoice)
        {
        case 1:
            playGame(ptrTotalScore);
            break;
        case 2:
            showFinalScore(totalScore);
            break;
        default:
            cout << "Not a valid choice. Enter only 1,2, or 3";
        }
    }

    return 0;
}
void showFinalScore(int totalScore)
{
    cout << "\nFinal score: " << totalScore << "\n\n";
}

void playGame(int *ptrTotalScore)
{
    string choice = "";
    string rightAnswer = "";
    bool answeredCorrectly = false;
    int randomNum = 0;

    // generate random number to feed into pickQuestion() function and the correctAnswer() function
    srand((unsigned)time(NULL)); // seed the rand() function with time() to ensure you do not get the same random number generated
    randomNum = 1 + (rand() % 3);

    rightAnswer = correctAnswer(randomNum); // get the correct answer to the question as per the random number

    cout << "What is this shape?\n\n";
    pickQuestion(randomNum);
    cout << "\n";

    showOptions();

    for (int i = 0; i < 3; i++)
    {
        cout << "Choice >> ";
        cin >> choice;

        if (choice == rightAnswer)
        {
            answeredCorrectly = true; // flagged the user has correctly answered the question
            break;
        }
        else
        {
            cout << "Sorry, try again\n";
        }
    }

    if (answeredCorrectly)
    {
        cout << "\nYour guess is correct\n\n";
        *ptrTotalScore = calculateScore(*ptrTotalScore);
    }
    else
    {
        cout << "\nYour guess is wrong. You reached the limit of tries. Play again \n\n";
    }
}

int calculateScore(int totalScore)
{

    return totalScore += 10;
}

void drawSquare()
/**********************************
 * Purpose: Draws the square shape
 *********************************/
{

    cout << "+";

    for (int i = 0; i < 10; i++)
    {
        cout << "-";
    }
    cout << "+";

    for (int i = 0; i < 4; i++)
    {
        cout << "\n|";
        for (int j = 0; j < 10; j++)
        {
            cout << " ";
        }
        cout << "|";
    }
    cout << "\n+";

    for (int i = 0; i < 10; i++)
    {
        cout << "-";
    }
    cout << "+\n";
}

void drawTriangle()
/**********************************
 * Purpose: Draws the triangle shape
 *********************************/
{
    cout << "     *\n";
    cout << "    * *\n";
    cout << "   *   *\n";
    cout << "  *     *\n";
    cout << " *********\n";
}

void drawRectangle(int height, int width)
/**********************************
 * Purpose: Draws the rectangle shape
 *********************************/
{

    cout << "+";

    for (int i = 0; i < width; i++)
    {
        cout << "-";
    }
    cout << "+";

    for (int i = 0; i < height; i++)
    {
        cout << "\n|";
        for (int j = 0; j < width; j++)
        {
            cout << " ";
        }
        cout << "|";
    }
    cout << "\n+";

    for (int i = 0; i < width; i++)
    {
        cout << "-";
    }
    cout << "+\n";
}

void showOptions()
/********************************************
 * Purpose: Shows the choices for the answer.
 ********************************************/

{

    cout << "a. Rectangle\n";
    cout << "b. Triangle\n";
    cout << "c. Square\n";
    cout << "d. None of the above\n";
    cout << "=====================\n";
}

int showMenu(int totalScore)
/*********************************************************************
 * Purpose: Shows the menu. This is the initial screen of the program.
 *********************************************************************/

{
    int menuChoice = 0;
    cout << "\n===========================\n";
    cout << "Welcome to Identify Shapes.\n";
    cout << "===========================\n";
    cout << "1. Play\n";
    cout << "2. Final Score (" << totalScore << ")\n";
    cout << "3. Exit\n";
    cout << "===========================\n";
    cout << "Choice: ";
    cin >> menuChoice;
    return menuChoice;
}

void pickQuestion(int questionNumber)
/***********************************************************************************************
 * Purpose: Picks the question based on the passed parameter that serves as the question number
 ***********************************************************************************************/

{
    switch (questionNumber)
    {
    case 1:
        drawRectangle(2, 10);
        break;
    case 2:
        drawTriangle();
        break;
    case 3:
        drawSquare();
        break;
    }
}

string correctAnswer(int questionNumber)
/**********************************************************************
 * Purpose: Returns the correct answer for a particular question number
 **********************************************************************/

{

    string answer = "";

    switch (questionNumber)
    {
    case 1:
        answer = "a";
        break;
    case 2:
        answer = "b";
        break;
    case 3:
        answer = "c";
        break;
    }

    return answer;
}
