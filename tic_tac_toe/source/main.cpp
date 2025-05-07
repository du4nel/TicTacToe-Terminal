// Tic Tac Toe Game by Duanel.
// v: a.10

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

void mainMenu();
void mainGame();
void drawBoard(std::vector<std::string>, std::vector<std::string>, std::vector<std::string>, char[9]);
bool fillVector(int, char (&)[9], char);
void detectWinner(char[9]);

int contX = 0, contO = 0;

void mainMenu()
{
    int selected = 0;

    bool upKeyWasDown = false;
    bool downKeyWasDown = false;
    bool enterKeyWasDown = false;

    system("cls");
    std::cout << std::endl;
    std::cout << "                                                    __   " << std::endl;
    std::cout << "   _____  _        _____            _____          |  |  " << std::endl;
    std::cout << "  |_   _|| |___   |_   _|___ ___   |_   _|___ ___  |  |  " << std::endl;
    std::cout << "    | |  | |  _|    | | | .'|  _|    | | | . | -_| |__|  " << std::endl;
    std::cout << "    |_|  |_|___|    |_| |__,|___|    |_| |___|___| |__|  " << std::endl;
    std::cout << std::endl;
    std::cout << "     ______________________________________________    " << std::endl;
    std::cout << "    |                                              |   " << std::endl;
    if (selected == 0)
    {
        std::cout << "    |                 -> |PLAY| (Local)            |   " << std::endl;
        std::cout << "    |                    |EXIT|                    |   " << std::endl;
    }
    else
    {
        std::cout << "    |                    |PLAY| (Local)            |   " << std::endl;
        std::cout << "    |                 -> |EXIT|                    |   " << std::endl;
    }
    std::cout << "    |                                              |   " << std::endl;
    std::cout << "    |______________________________________________|   " << std::endl;
    std::cout << std::endl
              << std::endl;
    std::cout << "  Multiplayer online coming soon!!                     " << std::endl;
    std::cout << "  Created by Duanel.                            v a1.0 " << std::endl;
    std::cout << std::endl
              << std::endl;

    while (true)
    {
        bool upKeyIsDown = (GetAsyncKeyState(VK_UP) & 0x8000) != 0;
        bool downKeyIsDown = (GetAsyncKeyState(VK_DOWN) & 0x8000) != 0;
        bool enterKeyIsDown = (GetAsyncKeyState(VK_RETURN) & 0x8000) != 0;

        bool needsRedraw = false;

        if (upKeyIsDown && !upKeyWasDown)
        {
            selected = 0;
            needsRedraw = true;
        }
        else if (downKeyIsDown && !downKeyWasDown)
        {
            selected = 1;
            needsRedraw = true;
        }
        else if (enterKeyIsDown && !enterKeyWasDown)
        {
            break;
        }

        upKeyWasDown = upKeyIsDown;
        downKeyWasDown = downKeyIsDown;
        enterKeyWasDown = enterKeyIsDown;

        if (needsRedraw)
        {
            system("cls");
            std::cout << std::endl;
            std::cout << "                                                    __   " << std::endl;
            std::cout << "   _____  _        _____            _____          |  |  " << std::endl;
            std::cout << "  |_   _|| |___   |_   _|___ ___   |_   _|___ ___  |  |  " << std::endl;
            std::cout << "    | |  | |  _|    | | | .'|  _|    | | | . | -_| |__|  " << std::endl;
            std::cout << "    |_|  |_|___|    |_| |__,|___|    |_| |___|___| |__|  " << std::endl;
            std::cout << std::endl;
            std::cout << "     ______________________________________________    " << std::endl;
            std::cout << "    |                                              |   " << std::endl;
            if (selected == 0)
            {
                std::cout << "    |                 -> |PLAY| (Local)            |   " << std::endl;
                std::cout << "    |                    |EXIT|                    |   " << std::endl;
            }
            else
            {
                std::cout << "    |                    |PLAY| (Local)            |   " << std::endl;
                std::cout << "    |                 -> |EXIT|                    |   " << std::endl;
            }
            std::cout << "    |                                              |   " << std::endl;
            std::cout << "    |______________________________________________|   " << std::endl;
            std::cout << std::endl
                      << std::endl;
            std::cout << "  Multiplayer online coming soon!!                     " << std::endl;
            std::cout << "  Created by Duanel.                            v a1.0 " << std::endl;
            std::cout << std::endl
                      << std::endl;
        }

        Sleep(10);
    }

    if (selected == 0)
    {
        system("cls");
        mainGame();
    }
    else
    {
        exit(0);
    }
}

bool fillVector(int box, char (&boardVector)[9], char playerIcon)
{
    box -= 1;

    if (box >= 0 && box < 9 && boardVector[box] == ' ')
    {
        boardVector[box] = playerIcon;
        return true;
    }
    else
    {
        std::cout << "Este campo ya esta ocupado." << std::endl;
    }
    return false;
}

void drawBoard(std::vector<std::string> board, std::vector<std::string> player1, std::vector<std::string> player2, char boardVector[9])
{

    std::cout << std::endl
              << std::endl
              << board[0] << std::endl;

    for (int row = 0; row < 3; ++row)
    {

        for (int line = 0; line < 4; ++line)
        {
            std::cout << "     |";
            for (int col = 0; col < 3; ++col)
            {
                int idx = row * 3 + col;
                if (boardVector[idx] == 'X')
                    std::cout << player1[line];
                else if (boardVector[idx] == 'O')
                    std::cout << player2[line];
                else
                    std::cout << "              ";
                std::cout << "|";
            }
            std::cout << std::endl;
        }

        std::cout << board[1] << std::endl;
        if (row < 2)
            std::cout << board[2] << std::endl;
    }
    std::cout << board[0] << std::endl
              << std::endl
              << std::endl;
}

char checkWinner(char board[9])
{
    int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (auto &combo : winCombos)
    {
        if (board[combo[0]] != ' ' &&
            board[combo[0]] == board[combo[1]] &&
            board[combo[1]] == board[combo[2]])
        {
            return board[combo[0]];
        }
    }

    bool tie = true;
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] == ' ')
            tie = false;
    }
    if (tie)
        return 'T';
    return ' ';
}

void mainGame()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Player Spaces

    std::vector<std::string> playerSpaces = {
        "              "};

    // Players
    std::vector<std::string>
        player1 = {"     __ __    ", "    |  |  |   ", "    |-   -|   ", "    |__|__|   "};

    std::vector<std::string> player2 = {
        "     _____    ",
        "    |     |   ",
        "    |  |  |   ",
        "    |_____|   "};

    // Board
    std::vector<std::string> board = {
        "      ____________________________________________",
        "     |              |              |              |",
        "     |______________|______________|______________|"};

    char boardVector[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    drawBoard(board, player1, player2, boardVector);

    char winner = ' ';

    do
    {
        bool redrawBoard = false;
        int box;
        char p1 = 'X';
        char p2 = 'O';

        system("cls");
        drawBoard(board, player1, player2, boardVector);

        do
        {
            std::cout << "Player 1: ";
            std::cin >> box;
            if (box < 1 || box > 9)
            {
                std::cout << "Invalid position." << std::endl;
            }
        } while (box < 1 || box > 9 || !fillVector(box, boardVector, p1));

        system("cls");
        drawBoard(board, player1, player2, boardVector);
        winner = checkWinner(boardVector);
        if (winner != ' ')
            break;

        do
        {
            std::cout << "Player 2: ";
            std::cin >> box;
            if (box < 1 || box > 9)
            {
                std::cout << "Invalid position." << std::endl;
            }
        } while (box < 1 || box > 9 || !fillVector(box, boardVector, p2));

        system("cls");
        drawBoard(board, player1, player2, boardVector);
        winner = checkWinner(boardVector);

    } while (winner == ' ');

    if (winner == 'X')
    {
        contX += 1;
        system("cls");
        std::cout << std::endl
                  << std::endl
                  << "                                                       __ " << std::endl;
        std::cout << "   _____ _                    ___      _ _ _ _        |  |" << std::endl;
        std::cout << "  |  _  | |___ _ _ ___ ___   |_  |    | | | |_|___ ___|  |" << std::endl;
        std::cout << "  |   __| | .'| | | -_|  _|   _| |_   | | | | |   |_ -|__|" << std::endl;
        std::cout << "  |__|  |_|__,|_  |___|_|    |_____|  |_____|_|_|_|___|__|" << std::endl;
        std::cout << "              |___|                                       " << std::endl
                  << std::endl;
        std::cout << "                             " << contX << ":" << contO << "                             ";
        PlaySound(TEXT("./resources/sounds/winner.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(9000);
    }
    else if (winner == 'O')
    {
        contO += 1;
        system("cls");
        std::cout << std::endl
                  << std::endl
                  << "                                                     __ " << std::endl;
        std::cout << "   _____ _                    ___    _ _ _ _        |  |" << std::endl;
        std::cout << "  |  _  | |___ _ _ ___ ___   |_  |  | | | |_|___ ___|  |" << std::endl;
        std::cout << "  |   __| | .'| | | -_|  _|  |  _|  | | | | |   |_ -|__|" << std::endl;
        std::cout << "  |__|  |_|__,|_  |___|_|    |___|  |_____|_|_|_|___|__|" << std::endl;
        std::cout << "              |___|                                     " << std::endl
                  << std::endl;
        std::cout << "                             " << contX << ":" << contO << "                             ";
        PlaySound(TEXT("./resources/sounds/winner.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(9000);
    }
    else
    {
        system("cls");
        std::cout << std::endl
                  << std::endl
                  << "   _____ _     " << std::endl;
        std::cout << "  |_   _|_|___ " << std::endl;
        std::cout << "    | | | | -_|" << std::endl;
        std::cout << "    |_| |_|___|" << std::endl
                  << std::endl;
        std::cout << "                             " << contX << ":" << contO << "                             ";
        PlaySound(TEXT("./resources/sounds/tie.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Sleep(3000);
    }

    std::cout << std::endl
              << std::endl
              << std::endl
              << "  ";

    system("pause");

    Sleep(100);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    PlaySound(NULL, 0, 0);
    mainMenu();
}

int main()
{
    mainMenu();
    return 0;
}