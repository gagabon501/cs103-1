#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void showPlayerInfo(int playerNum)
{

    char positionChoice;

    string positions[] = {"Goalkeeper", "Midfielder", "Striker", "Winger"};

    enum Position
    {
        goalkeeper,
        midfielder,
        striker,
        winger,
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
        cout << "Invalid selection\n";
    }

    if (position >= 0 && position <= 3)
    {
        cout << "=========================" << endl;
        cout << "Information for Player - " << playerNum << endl;
        cout << "Number      : " << player.playerNum << endl;
        cout << "Speed (mph) : " << player.playerSpeed << endl;
        cout << "Position    : " << positions[position] << endl;
    }
}

int main()
{
    showPlayerInfo(1);
    showPlayerInfo(2);
}