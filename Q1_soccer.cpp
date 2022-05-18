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

    char positionChoice;

    string positions[] = {"Goalkeeper", "Midfielder", "Striker", "Winger", "Invalid"};

    enum Position
    {
        goalkeeper,
        midfielder,
        striker,
        winger,
        invalid
    };

    struct Soccer
    {
        int playerNum;
        float playerSpeed;
    };

    Soccer player;

    Position position;

    cout << "\nEnter information for player - " << playerNum << endl;
    cout << "================================" << endl;
    cout << "Enter player number: ";
    cin >> player.playerNum;
    cout << "Enter speed (mph): ";
    cin >> player.playerSpeed;
    cout << "Enter position (g=goalkeeper, m=midfielder, s=striker, w=winger): ";
    cin >> positionChoice;

    switch (positionChoice)
    {
    case 'g':
        position = goalkeeper;
        break;
    case 'm':
        position = midfielder;
        break;
    case 's':
        position = striker;
        break;
    case 'w':
        position = winger;
        break;
    default:
        position = invalid;
        cout << "Invalid position selection. Please press one of these choices: 'g','m','s','w'\n";
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