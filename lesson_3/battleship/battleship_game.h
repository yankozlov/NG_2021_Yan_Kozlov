#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H

#include <bot.h>
#include <maps.h>
#include <ships.h>

void showIntro()
{
    cout << endl << endl;
    cout << "\t" << "       ___        _    _    _           _     _  _ __ " << endl
         << "\t" << "      | _ ) __ _ | |_ | |_ | | ___  ___| |_  (_)| '_ \\" << endl
         << "\t" << "      | _ \\/ _` ||  _||  _|| |/ -_)(_-/|   \\ | || .__/" << endl
         << "\t" << "      |___/\\__/_| \\__| \\__||_|\\___|/__/|_||_||_||_|" << endl;
    cout << endl << endl << endl;
    cout << "Press ENTER to start...";
    getchar();
}

void showOutro(int currPlayer, bool playWithComputer) {
    system("clear");
    if (currPlayer == 0) {
        cout << "       ___  _        _  _                _               _             _ " << endl <<
                "      | _ \\| | __ _ | || | ___  _ _     / |     _ __ __ (_) _ _   ___ | |" << endl <<
                "      |  _/| |/ _` | \\_. |/ -_)| '_|    | |     \\ V  V /| || ' \\ (_-/ |_|" << endl <<
                "      |_|  |_|\\__/_| |__/ \\___||_|      |_|      \\_/\\_/ |_||_||_|/__/ (_)" << endl;
    }
    else if (playWithComputer == false) {
        cout << "       ___  _        _  _                ___              _             _ " << endl <<
                "      | _ \\| | __ _ | || | ___  _ _     |_  )    _ __ __ (_) _ _   ___ | |" << endl <<
                "      |  _/| |/ _` | \\_. |/ -_)| '_|     / /     \\ V  V /| || ' \\ (_-/ |_|" << endl <<
                "      |_|  |_|\\__/_| |__/ \\___||_|      /___|     \\_/\\_/ |_||_||_|/__/ (_)" << endl;
    }
    else {
        cout << "      ___              _ __        _                         _             _" << endl <<
                "     / __| ___  _ __  | '_ \\ _  _ | |_  ___  _ _    _ __ __ (_) _ _   ___ | |" << endl <<
                "    | (__ / _ \\| '  \\ | .__/| || ||  _|/ -_)| '_|   \\ V  V /| || ' \\ (_-/ |_|" << endl <<
                "     \\___|\\___/|_|_|_||_|    \\_._| \\__|\\___||_|      \\_/\\_/ |_||_||_|/__/ (_)" << endl;
    }
    cout << endl;
}

void formatCoords(char coords[], int size)
{
    for (int i = 0; i < size; i++)
        if (coords[i] >= 'A' && coords[i] <= 'Z') coords[i] += 32;

    if (coords[0] == 'r' && coords[1] == 'a' && coords[2] == 'n' && coords[3] == 'd') return;
    if (coords[0] == 'c' && coords[1] == 'l' && coords[2] == 'r' && coords[3] == 0) return;

    if (coords[0] >= 'a' && coords[0] <= 'j' && coords[1] >= '0' && coords[1] <= '9') swap(coords[0], coords[1]);
    if (coords[2] >= 'a' && coords[2] <= 'j' && coords[3] >= '0' && coords[3] <= '9') swap(coords[2], coords[3]);

    if (size == 2) return;

    if (coords[2] == 0) coords[2] = coords[0];
    if (coords[3] == 0) coords[3] = coords[1];

    if (coords[0] > coords[2]) swap(coords[0], coords[2]);
    if (coords[1] > coords[3]) swap(coords[1], coords[3]);
}

void makeAMove(char moveCoord[2], int currPlayer, bool playWithComputer, Maps *maps, Bot *bot)
{
    do {
        moveCoord[0] = 0;
        moveCoord[1] = 0;

        if (currPlayer == 0)
            cout << "P1│ Enter the coordinates (for example: a1): ";
        else if (!playWithComputer)
            cout << "P2│ Enter the coordinates (for example: a1): ";

        if (currPlayer == 1 && playWithComputer) {
            bot->makeAMove(moveCoord, maps->playersMaps, currPlayer);
        }
        else {
            cin >> moveCoord;
            getchar();          //! fixes getchar() after showing current move
        }

        formatCoords(moveCoord, 2);
    } while (!(moveCoord[0] >= '0' && moveCoord[0] <= '9' && moveCoord[1] >= 'a' && moveCoord[1] <= 'j'));
}

void showPreviousMove(int currPlayer, bool playWithComputer, char moveCoord[2], Maps maps)
{
    if (currPlayer == 1 && playWithComputer)
        cout << " C| Computer move: " << moveCoord[1] << moveCoord[0] << " - ";
    else if (currPlayer == 0)
        cout << "P1| First player's move: " << moveCoord[1] << moveCoord[0] << " - ";
    else
        cout << "P2| Second player's move: " << moveCoord[1] << moveCoord[0] << " - ";

    if (maps.playersMaps[(currPlayer+1)%2][moveCoord[0]-'0'][moveCoord[1]-'a'] == 3) cout << "direct hit!" << endl;
    else if (maps.playersMaps[(currPlayer+1)%2][moveCoord[0]-'0'][moveCoord[1]-'a'] == 2) cout << "miss!" << endl;
}

bool gameOver (int gameMaps[2][10][10], int opponent)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (gameMaps[opponent][i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

#endif // BATTLESHIP_GAME_H
