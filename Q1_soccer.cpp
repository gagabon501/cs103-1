/**********************************************************************************************************************
 *    CS-103 Integrated Studio I Assessment 1 - Question1: Display soccer player information using structure data type
 *    @file Q1_soccer.cpp
 *    @author Gilberto Gabon
 *    @version 1 / 29-May-2022
 *********************************************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Soccer
{
    int playerNum;
    float playerSpeed;
};

enum Position
{
    goalkeeper,
    midfielder,
    striker,
    winger,
    invalid
};

// Function Prototypes
void showPlayerInfo(int playerNum);

int main()
{
    showPlayerInfo(1);
    showPlayerInfo(2);
}

void showPlayerInfo(int playerNum)
/*****************************************************************************
 * Purpose: Shows the player's information. This utilises structure data type.
 *****************************************************************************/

{

    char positionChoice = ' ';
    bool doLoop = true;

    string positions[] = {"Goalkeeper", "Midfielder", "Striker", "Winger", "Invalid"};

    Soccer player;

    Position position;

    cout << "\nEnter information for player - " << playerNum << endl;
    cout << "================================" << endl;
    cout << "Enter player number: ";
    cin >> player.playerNum;
    cout << "Enter speed (mph): ";
    cin >> player.playerSpeed;
    while (doLoop)
    {
        cout << "Enter position (g=goalkeeper, m=midfielder, s=striker, w=winger): ";
        cin >> positionChoice;

        switch (positionChoice)
        {
        case 'g':
            position = goalkeeper;
            doLoop = false;
            break;
        case 'm':
            position = midfielder;
            doLoop = false;
            break;
        case 's':
            position = striker;
            doLoop = false;
            break;
        case 'w':
            position = winger;
            doLoop = false;
            break;
        default:
            position = invalid;
            cout << "Invalid position selection. Please press one of these choices: 'g','m','s','w'\n";
        }
    }

    // Player information will only be displayed if the user selects one of the acceptable positions (g, m, s, w)
    if (position >= goalkeeper && position <= winger)
    {
        cout << "\n================================" << endl;
        cout << "Information for Player - " << playerNum << endl;
        cout << "Number      : " << player.playerNum << endl;
        cout << "Speed (mph) : " << player.playerSpeed << endl;
        cout << "Position    : " << positions[position] << endl;
        cout << "================================" << endl;
    }
}