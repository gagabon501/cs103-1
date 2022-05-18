/*****************************************************************************************************************
 *    CS-103 Integrated Studio I Assessment 1 - Question4: Hangman game. Game to test spelling skills of the user.
 *    @file Q4_hangmanGame.cpp
 *    @author Gilberto Gabon
 *    @version 1 / 29-May-2022
 *****************************************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function Prototypes
void drawHangMan();
void drawInvertedHangMan();
void drawWalkMan();
void showMenu();
void Clear();
string pickQuestion(int questionNumber);
string correctAnswer(int questionNumber);

int main()
{

    // variable definitions
    string answer = "";
    string rightAnswer = "";
    bool answeredCorrectly = false;
    int randomNum = 0;

    // generate random number to feed into pickQuestion() function and the correctAnswer() function
    srand((unsigned)time(NULL)); // seed the rand() function with time() to ensure you do not get the same random number generated
    randomNum = 1 + (rand() % 4);

    // Assign function to a variable
    rightAnswer = correctAnswer(randomNum); // get the correct answer to the question as per the random number

    Clear();    // clear screen
    showMenu(); // show the main menu

    for (int i = 0; i < 3; i++)
    {
        cout << "\nQUESTION: " << pickQuestion(randomNum); // pick the question based on the random number generated
        cin >> answer;

        if (answer == rightAnswer)
        {
            answeredCorrectly = true; // flagged the user has correctly answered the question
            break;
        }
        else
        {
            cout << "Sorry, try again";
        }
    }

    if (answeredCorrectly)
    {
        cout << "\nYour guess is correct\n";
        drawWalkMan();
    }
    else
    {
        cout << "\nYour guess is wrong\n";
        drawInvertedHangMan();
    }

    return 0;
}

void drawHangMan()
/****************************
 * Purpose: Draws the hangman
 ****************************/
{
    cout << "  +----+\n";
    cout << "  |    |\n";
    cout << "  |    o\n";
    cout << "  |   \\|/\n";
    cout << "  |    |\n";
    cout << "  |   / \\\n";

    for (int i = 0; i < 2; i++)
    {
        cout << "  |\n";
    }
    for (int j = 0; j < 5; j++)
    {
        cout << "-";
    }
    cout << "\n";
}

void drawInvertedHangMan()
/**************************************
 * Purpose: Draws the inverted hangman
 *************************************/

{
    cout << "  +----+\n";
    cout << "  |    |\n";
    cout << "  |   /|\\\n";
    cout << "  |    |\n";
    cout << "  |   /|\\\n";
    cout << "  |    o\n";

    for (int i = 0; i < 2; i++)
    {
        cout << "  |\n";
    }
    for (int j = 0; j < 5; j++)
    {
        cout << "-";
    }
    cout << "\n";
}

void drawWalkMan()
/********************************
 * Purpose: Draws the walking man
 ********************************/

{
    cout << " o\n";
    cout << "\\|/\n";
    cout << " |\n";
    cout << "/ \\\n";
    cout << "\n";
}

string pickQuestion(int questionNumber)
/***********************************************************************************************
 * Purpose: Picks the question based on the passed parameter that serves as the question number
 ***********************************************************************************************/

{
    string question = "";
    switch (questionNumber)
    {
    case 1:
        question = "Guess the missing letter in Yo_bee?: ";
        break;
    case 2:
        question = "How many 's' are there in the word Mi******ppi (a state in the Southeastern region of the United States): ";
        break;
    case 3:
        question = "It's cold in winter, but in spring the ______________ is beautiful.: ";
        break;
    case 4:
        question = "Why are you crying? What ______________ ? ";
        break;
    default:
        question = "";
    }
    return question;
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
        answer = "o";
        break;
    case 2:
        answer = "4";
        break;
    case 3:
        answer = "weather";
        break;
    case 4:
        answer = "happened";
        break;
    default:
        answer = "";
    }

    return answer;
}

void showMenu()
/*********************************************************************************************************
 * Purpose: Shows the welcome message and displays the hangman. This is the initial screen of the program.
 ********************************************************************************************************/

{
    string answer = "";
    cout << "==================================================================\n";
    cout << "Welcome to play hangman. This game is to check your spelling skill\n";
    cout << "==================================================================\n";
    drawHangMan();
}

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}