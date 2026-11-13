#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// Global score
static int score = 0;

/*
====================================================
MOVE LEFT
====================================================
*/
void move_left(int board[][5], int numrows = 5)
{
    for (int r = 0; r < numrows; r++)
    {
        int temp[5] = {0};
        int pos = 0;

        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] != 0)
                temp[pos++] = board[r][c];
        }

        for (int c = 0; c < 4; c++)
        {
            if (temp[c] != 0 && temp[c] == temp[c + 1])
            {
                temp[c] *= 2;
                score += temp[c];
                temp[c + 1] = 0;
                c++;
            }
        }

        int result[5] = {0};
        pos = 0;

        for (int c = 0; c < 5; c++)
        {
            if (temp[c] != 0)
                result[pos++] = temp[c];
        }

        for (int c = 0; c < 5; c++)
            board[r][c] = result[c];
    }
}

/*
====================================================
MOVE RIGHT
====================================================
*/
void move_right(int board[][5], int numrows = 5)
{
    for (int r = 0; r < numrows; r++)
    {
        int temp[5] = {0};
        int pos = 4;

        for (int c = 4; c >= 0; c--)
        {
            if (board[r][c] != 0)
                temp[pos--] = board[r][c];
        }

        for (int c = 4; c > 0; c--)
        {
            if (temp[c] != 0 && temp[c] == temp[c - 1])
            {
                temp[c] *= 2;
                score += temp[c];
                temp[c - 1] = 0;
                c--;
            }
        }

        int result[5] = {0};
        pos = 4;

        for (int c = 4; c >= 0; c--)
        {
            if (temp[c] != 0)
                result[pos--] = temp[c];
        }

        for (int c = 0; c < 5; c++)
            board[r][c] = result[c];
    }
}

/*
====================================================
MOVE UP
====================================================
*/
void move_up(int board[][5], int numrows = 5)
{
    for (int c = 0; c < 5; c++)
    {
        int temp[5] = {0};
        int pos = 0;

        for (int r = 0; r < numrows; r++)
        {
            if (board[r][c] != 0)
                temp[pos++] = board[r][c];
        }

        for (int r = 0; r < 4; r++)
        {
            if (temp[r] != 0 && temp[r] == temp[r + 1])
            {
                temp[r] *= 2;
                score += temp[r];
                temp[r + 1] = 0;
                r++;
            }
        }

        int result[5] = {0};
        pos = 0;

        for (int r = 0; r < 5; r++)
        {
            if (temp[r] != 0)
                result[pos++] = temp[r];
        }

        for (int r = 0; r < numrows; r++)
            board[r][c] = result[r];
    }
}

/*
====================================================
MOVE DOWN
====================================================
*/
void move_down(int board[][5], int numrows = 5)
{
    for (int c = 0; c < 5; c++)
    {
        int temp[5] = {0};
        int pos = 4;

        for (int r = 4; r >= 0; r--)
        {
            if (board[r][c] != 0)
                temp[pos--] = board[r][c];
        }

        for (int r = 4; r > 0; r--)
        {
            if (temp[r] != 0 && temp[r] == temp[r - 1])
            {
                temp[r] *= 2;
                score += temp[r];
                temp[r - 1] = 0;
                r--;
            }
        }

        int result[5] = {0};
        pos = 4;

        for (int r = 4; r >= 0; r--)
        {
            if (temp[r] != 0)
                result[pos--] = temp[r];
        }

        for (int r = 0; r < numrows; r++)
            board[r][c] = result[r];
    }
}

/*
====================================================
PRINT BOARD
====================================================
*/
void print_board(int board[][5], int numrows = 5)
{
    cout << endl;
    cout << "\t-----------------------------------------" << endl;

    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] > 0)
            {
                cout << "\t|"
                     << right
                     << setw(6)
                     << setfill(' ')
                     << board[r][c];
            }
            else
            {
                cout << "\t|"
                     << right
                     << setw(6)
                     << setfill(' ')
                     << " ";
            }
        }

        cout << "\t|" << endl;
        cout << "\t-----------------------------------------" << endl;
    }

    cout << "\nScore: " << score << endl;
}

/*
====================================================
INSERT RANDOM TILE
====================================================
*/
void insert_random(int board[][5], int numrows = 5)
{
    int empty_count = 0;

    for (int r = 0; r < numrows; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] == 0)
                empty_count++;
        }
    }

    if (empty_count > 0)
    {
        while (true)
        {
            int r = rand() % numrows;
            int c = rand() % numrows;

            if (board[r][c] == 0)
            {
                board[r][c] = 2 * (1 + (rand() % 2));
                break;
            }
        }
    }
}

/*
====================================================
COPY BOARD
====================================================
*/
void copy_board(int source[][5], int destination[][5])
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            destination[r][c] = source[r][c];
        }
    }
}

/*
====================================================
BOARD CHANGED
====================================================
*/
bool board_changed(int before[][5], int after[][5])
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (before[r][c] != after[r][c])
                return true;
        }
    }

    return false;
}

/*
====================================================
GET SCORE
====================================================
*/
int get_score()
{
    return score;
}

/*
====================================================
WIN CHECK
====================================================
*/
bool check_win(int board[][5])
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] == 2048)
                return true;
        }
    }

    return false;
}

/*
====================================================
BOARD FULL
====================================================
*/
bool board_full(int board[][5])
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] == 0)
                return false;
        }
    }

    return true;
}

/*
====================================================
GAME OVER
====================================================
*/
bool game_over(int board[][5])
{
    if (!board_full(board))
        return false;

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (board[r][c] == board[r][c + 1])
                return false;
        }
    }

    for (int c = 0; c < 5; c++)
    {
        for (int r = 0; r < 4; r++)
        {
            if (board[r][c] == board[r + 1][c])
                return false;
        }
    }

    return true;
}

#endif