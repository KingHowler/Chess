#include <iostream>
#include <stdlib.h>
using namespace std;

class Point
{
public:
    int x, y;
};

class ChessPiece
{
public:
    Point add;
    int color;
    char piece;

    void point(int x, int y)
    {
        add.x = x;
        add.y = y;
    }

    void printPiece()
    {
        switch (color)
        {
        case 1:
            cout << "Black ";
            break;
        case 2:
            cout << "White ";
            break;
        case 3:
            cout << "      ";
            break;
        }
        switch (piece)
        {
        case 'p':
            cout << "Pawn   ";
            break;
        case 'N':
            cout << "Knight ";
            break;
        case 'B':
            cout << "Bishop ";
            break;
        case 'R':
            cout << "Rook   ";
            break;
        case 'Q':
            cout << "Queen  ";
            break;
        case 'K':
            cout << "King   ";
            break;
        case 'x':
            cout << "       ";
            break;
        }
    }
    void printPieceInfo()
    {
        string info;
        if (piece != 'x')
        {
            if (piece != 'p')
            {
                info += piece;
            }
            else
            {
                info += " ";
            }
            info += char(add.x + 97);
            info += to_string(add.y);
        }
        else
        {
            info += "   ";
        }
        cout << info;
    }
};

ChessPiece Pawn, Knight, Bishop, Rook, Queen, King, NoPiece;

class Chess
{
public:
    ChessPiece Board[8][8];

    void CreateBoard()
    {
        Pawn.piece = 'p';
        Knight.piece = 'N';
        Bishop.piece = 'B';
        Rook.piece = 'R';
        Queen.piece = 'Q';
        King.piece = 'K';
        NoPiece.piece = 'x';
        NoPiece.color = 3;

        Board[0][0] = Rook;
        Board[0][7] = Rook;
        Board[7][0] = Rook;
        Board[7][7] = Rook;

        Board[0][1] = Knight;
        Board[0][6] = Knight;
        Board[7][1] = Knight;
        Board[7][6] = Knight;

        Board[0][2] = Bishop;
        Board[0][5] = Bishop;
        Board[7][2] = Bishop;
        Board[7][5] = Bishop;

        Board[0][3] = Queen;
        Board[7][3] = Queen;
        Board[0][4] = King;
        Board[7][4] = King;

        for (int i = 0; i < 8; i++)
        {
            Board[1][i] = Pawn;
            Board[6][i] = Pawn;
            Board[2][i] = NoPiece;
            Board[3][i] = NoPiece;
            Board[4][i] = NoPiece;
            Board[5][i] = NoPiece;

            Board[0][i].color = 1;
            Board[1][i].color = 1;
            Board[6][i].color = 2;
            Board[7][i].color = 2;

            Board[0][i].point(i, 0);
            Board[1][i].point(i, 1);
            Board[6][i].point(i, 6);
            Board[7][i].point(i, 7);
        }
    }
    void checkMoves(Point Start)
    {
        switch (Board[Start.y][Start.x].piece)
        {
        case 'x':

            break;

        default:
            break;
        }
    }
};