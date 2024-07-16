#include "Chess.cpp"

Chess game;

void cls()
{
    system("cls");
}

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
    Point pawan;
    game.CreateBoard();
    pawan.x = 4;
    pawan.y = 5;
    game.Board[5][4].color = 2;
    game.Board[5][4].piece = 'p';
    game.Board[5][4].add = pawan;
    game.Board[5][4].add.address = "e6";
    pawan.x = 3;
    pawan.y = 4;
    game.Board[4][3].color = 1;
    game.Board[4][3].piece = 'Q';
    game.Board[4][3].add = pawan;
    game.Board[4][3].add.address = "d5";
    DisplayNotation();
    game.checkMoves(pawan);
    game.displayLegalMoves();
    pawan.x = 4;
    pawan.y = 5;
    game.checkMoves(pawan);
    game.displayLegalMoves();
    pawan.x = 4;
    pawan.y = 6;
    game.checkMoves(pawan);
    game.displayLegalMoves();
    pawan.x = 1;
    pawan.y = 6;
    game.checkMoves(pawan);
    game.displayLegalMoves();
    while (buff != 0)
    {
        cin >> buff;
    }
    return 0;
}