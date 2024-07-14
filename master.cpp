#include "Chess.cpp"

Chess game;

void DisplayBoard()
{
    for (int i = 0; i < 129; i++)
    {
        cout << "-";
    }
    cout << '\n';
    for (int row = 0; row < 8; row++)
    {
        cout << "|  ";
        for (int column = 0; column < 8; column++)
        {
            game.Board[row][column].printPiece();
            cout << "|  ";
        }
        cout << '\n';
        for (int i = 0; i < 129; i++)
        {
            cout << "-";
        }
        cout << '\n';
    }
}

void DisplayNotation()
{
    for (int i = 0; i < 65; i++)
    {
        cout << "-";
    }

    cout << '\n';
    for (int row = 0; row < 8; row++)
    {
        cout << "|";
        for (int i = 0; i < 8; i++)
        {
            cout << "       |";
        }
        cout << '\n';
        cout << "|  ";
        for (int column = 0; column < 8; column++)
        {
            game.Board[row][column].printPieceInfo();
            cout << "  |  ";
        }
        cout << '\n';
        cout << "|";
        for (int i = 0; i < 8; i++)
        {
            cout << "       |";
        }
        cout << '\n';
        for (int i = 0; i < 65; i++)
        {
            cout << "-";
        }
        cout << '\n';
    }
}

void selectMove()
{
    Point startAddress;
    char buffc;
    int buffi;
    cout << "Type Column Number of Chess Peice ";
    cin >> buffc;
    startAddress.x = int(buffc) - 97;
    cout << '\n'
         << "Type Row Number ";
    cin >> buffi;
    startAddress.y = buffi - 1;
    game.checkMoves(startAddress);
}

int main()
{
    int buff = 1;
    // system("cls");
    game.CreateBoard();
    DisplayNotation();
    while (buff != 0)
    {
        cin >> buff;
    }
    return 0;
}