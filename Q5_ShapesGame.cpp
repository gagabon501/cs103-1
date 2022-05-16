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
void showWelcomeMsg();
void showOptions();
void pickQuestion(int questionNumber);
string correctAnswer(int questionNumber);

int main()
{

    // variable definitions
    string choice = "";
    string rightAnswer = "";
    bool answeredCorrectly = false;
    int randomNum = 0;

    // generate random number to feed into pickQuestion() function and the correctAnswer() function
    srand((unsigned)time(NULL)); // seed the rand() function with time() to ensure you do not get the same random number generated
    randomNum = 1 + (rand() % 3);

    rightAnswer = correctAnswer(randomNum); // get the correct answer to the question as per the random number

    showWelcomeMsg();
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
        cout << "\nYour guess is correct\n";
    }
    else
    {
        cout << "\nYour guess is wrong\n";
    }

    return 0;
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
void showWelcomeMsg()
/********************************************************************************
 * Purpose: Shows the welcome message. This is the initial screen of the program.
 ********************************************************************************/

{
    cout << "===========================\n";
    cout << "Welcome to Identify Shapes.\n";
    cout << "===========================\n";
}

void showOptions()
/******************************************************************************************
 * Purpose: Shows the options/questions. This is part of the initial screen of the program.
 ******************************************************************************************/

{
    cout << "a. Rectangle\n";
    cout << "b. Triangle\n";
    cout << "c. Square\n";
    cout << "d. None of the above\n";
    cout << "====================\n";
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
