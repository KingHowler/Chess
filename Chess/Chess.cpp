#include <iostream>
#include <stdlib.h>
using namespace std;

class Point
{
public:
    int x, y;
    string address;

    void changeAddress(char X, int Y)
    {
        x = int(X) - 97;
        y = Y + 1;
        address = X + to_string(Y + 1);
    }
};

class ChessPiece
{
public:
    Point add;
    int color;
    char piece;

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
            info += add.address;
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
    string buff;

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

            Board[0][i].add.changeAddress(char(i + 97), 0);
            Board[1][i].add.changeAddress(char(i + 97), 1);
            Board[6][i].add.changeAddress(char(i + 97), 6);
            Board[7][i].add.changeAddress(char(i + 97), 7);
        }
    }

    string LegalMoves[27];

    void checkMoves(Point Start)
    {
        int y;
        for (int i = 0; i < 27; ++i)
        {
            LegalMoves[i] = "";
        }
        switch (Board[Start.y][Start.x].piece)
        {
        case 'x':
            cout << "No Piece";
            break;
        case 'p':
            if (Board[Start.y][Start.x].color == 1)
            {
                if (Start.y == 1)
                {
                    if (Board[Start.y + 2][Start.x].color == 3 && Board[Start.y + 1][Start.x].color == 3)
                    {
                        buff += char(Start.x + 97);
                        buff += to_string(Start.y + 3);
                    }
                }
                if (Board[Start.y + 1][Start.x].color == 3)
                {
                    buff += char(Start.x + 97);
                    buff += to_string(Start.y + 2);
                }
                if (Board[Start.y + 1][Start.x + 1].color == 2 && Start.x != 7)
                {
                    buff += char(Start.x + 98);
                    buff += to_string(Start.y + 2);
                }
                if (Board[Start.y + 1][Start.x - 1].color == 2 && Start.x != 0)
                {
                    buff += char(Start.x + 96);
                    buff += to_string(Start.y + 2);
                }
            }
            if (Board[Start.y][Start.x].color == 2)
            {
                if (Start.y == 6)
                {
                    if (Board[Start.y - 2][Start.x].color == 3 && Board[Start.y - 1][Start.x].color == 3)
                    {
                        buff += char(Start.x + 97);
                        buff += to_string(Start.y - 1);
                    }
                }
                if (Board[Start.y - 1][Start.x].color == 3)
                {
                    buff += char(Start.x + 97);
                    buff += to_string(Start.y);
                }
                if (Board[Start.y - 1][Start.x + 1].color == 1 && Start.x != 7)
                {
                    buff += char(Start.x + 98);
                    buff += to_string(Start.y);
                }
                if (Board[Start.y - 1][Start.x - 1].color == 1 && Start.x != 0)
                {
                    buff += char(Start.x + 96);
                    buff += to_string(Start.y);
                }
            }
            break;
        case 'K':
            for (int y = Start.y - 1; y < Start.y + 2; y++)
            {
                for (int x = Start.x - 1; x < Start.x + 2; x++)
                {
                    if ((y >= 0) && (y <= 7) && (x >= 0) && (x <= 7) && (Board[y][x].color != Board[Start.y][Start.x].color))
                    {
                        buff += char(x + 97);
                        buff += to_string(y + 1);
                    }
                }
            }
            break;
        case 'N':
            for (int y = Start.y - 2; y < Start.y + 3; y++)
            {
                for (int x = Start.x - 2; x < Start.x + 3; x++)
                {
                    if ((abs(x - Start.x) == 2 && abs(y - Start.y) == 1) || (abs(x - Start.x) == 1 && abs(y - Start.y) == 2))
                    {
                        if ((y >= 0) && (y <= 7) && (x >= 0) && (x <= 7) && (Board[y][x].color != Board[Start.y][Start.x].color))
                        {
                            buff += char(x + 97);
                            buff += to_string(y + 1);
                        }
                    }
                }
            }
            break;
        case 'R':
            for (int i = Start.x + 1; i < 8; i++)
            {
                if (Board[Start.y][i].color != Board[Start.y][Start.x].color)
                {
                    buff += char(i + 97);
                    buff += to_string(Start.y + 1);
                    if (Board[Start.y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            for (int i = Start.x - 1; i > -1; i--)
            {
                if (Board[Start.y][i].color != Board[Start.y][Start.x].color)
                {
                    buff += char(i + 97);
                    buff += to_string(Start.y + 1);
                    if (Board[Start.y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            for (int i = Start.y + 1; i < 8; i++)
            {
                if (Board[i][Start.x].color != Board[Start.y][Start.x].color)
                {
                    buff += char(Start.x + 97);
                    buff += to_string(i + 1);
                    if (Board[i][Start.x].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            for (int i = Start.y - 1; i > -1; i--)
            {
                if (Board[i][Start.x].color != Board[Start.y][Start.x].color)
                {
                    buff += char(Start.x + 97);
                    buff += to_string(i + 1);
                    if (Board[i][Start.x].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            break;
        case 'B':
            y = Start.y;
            for (int i = Start.x + 1; i < 8; i++)
            {
                y++;
                if (Board[y][i].color != Board[Start.y][Start.x].color && y < 8)
                {
                    buff += char(i + 97);
                    buff += to_string(y + 1);
                    if (Board[y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            y = Start.y;
            for (int i = Start.x + 1; i < 8; i++)
            {
                y--;
                if (Board[y][i].color != Board[Start.y][Start.x].color && y > -1)
                {
                    buff += char(i + 97);
                    buff += to_string(y + 1);
                    if (Board[y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            y = Start.y;
            for (int i = Start.x - 1; i > -1; i--)
            {
                y++;
                if (Board[y][i].color != Board[Start.y][Start.x].color && y < 8)
                {
                    buff += char(i + 97);
                    buff += to_string(y + 1);
                    if (Board[y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            y = Start.y;
            for (int i = Start.x - 1; i > -1; i--)
            {
                y--;
                if (Board[y][i].color != Board[Start.y][Start.x].color && y > -1)
                {
                    buff += char(i + 97);
                    buff += to_string(y + 1);
                    if (Board[y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            break;
        case 'Q':
            for (int i = Start.x + 1; i < 8; i++)
            {
                if (Board[Start.y][i].color != Board[Start.y][Start.x].color)
                {
                    buff += char(i + 97);
                    buff += to_string(Start.y + 1);
                    if (Board[Start.y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            for (int i = Start.x - 1; i > -1; i--)
            {
                if (Board[Start.y][i].color != Board[Start.y][Start.x].color)
                {
                    buff += char(i + 97);
                    buff += to_string(Start.y + 1);
                    if (Board[Start.y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            for (int i = Start.y + 1; i < 8; i++)
            {
                if (Board[i][Start.x].color != Board[Start.y][Start.x].color)
                {
                    buff += char(Start.x + 97);
                    buff += to_string(i + 1);
                    if (Board[i][Start.x].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            for (int i = Start.y - 1; i > -1; i--)
            {
                if (Board[i][Start.x].color != Board[Start.y][Start.x].color)
                {
                    buff += char(Start.x + 97);
                    buff += to_string(i + 1);
                    if (Board[i][Start.x].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            y = Start.y;
            for (int i = Start.x + 1; i < 8; i++)
            {
                y++;
                if (Board[y][i].color != Board[Start.y][Start.x].color && y < 8)
                {
                    buff += char(i + 97);
                    buff += to_string(y + 1);
                    if (Board[y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            y = Start.y;
            for (int i = Start.x + 1; i < 8; i++)
            {
                y--;
                if (Board[y][i].color != Board[Start.y][Start.x].color && y > -1)
                {
                    buff += char(i + 97);
                    buff += to_string(y + 1);
                    if (Board[y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            y = Start.y;
            for (int i = Start.x - 1; i > -1; i--)
            {
                y++;
                if (Board[y][i].color != Board[Start.y][Start.x].color && y < 8)
                {
                    buff += char(i + 97);
                    buff += to_string(y + 1);
                    if (Board[y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            y = Start.y;
            for (int i = Start.x - 1; i > -1; i--)
            {
                y--;
                if (Board[y][i].color != Board[Start.y][Start.x].color && y > -1)
                {
                    buff += char(i + 97);
                    buff += to_string(y + 1);
                    if (Board[y][i].color != 3)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            break;
        }
        for (int i = 0; i < buff.length(); i += 2)
        {
            LegalMoves[i / 2] = buff.substr(i, 2);
        }
        buff = "";
    }
    void displayLegalMoves()
    {
        for (int i = 0; i < 27; i++)
        {
            cout << LegalMoves[i] << '\n'; // Output each element followed by newline
        }
    }
};