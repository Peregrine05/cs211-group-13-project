#ifndef HELPER_H
#define HELPER_H

using namespace std;

/*
    MOVE LEFT
*/
void move_left(int board[][5], int numrows = 5)
{
    for (int r = 0; r < numrows; r++)
    {
        int temp[5] = {0};
        int pos = 0;

        // Shift nonzero values left
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] != 0)
            {
                temp[pos] = board[r][c];
                pos++;
            }
        }

        // Merge matching values
        for (int c = 0; c < 4; c++)
        {
            if (temp[c] != 0 && temp[c] == temp[c + 1])
            {
                temp[c] *= 2;
                temp[c + 1] = 0;
                c++;
            }
        }

        // Shift left again
        int result[5] = {0};
        pos = 0;

        for (int c = 0; c < 5; c++)
        {
            if (temp[c] != 0)
            {
                result[pos] = temp[c];
                pos++;
            }
        }

        for (int c = 0; c < 5; c++)
        {
            board[r][c] = result[c];
        }
    }
}

/*
    MOVE RIGHT
*/
void move_right(int board[][5], int numrows = 5)
{
    for (int r = 0; r < numrows; r++)
    {
        int temp[5] = {0};
        int pos = 4;

        // Shift nonzero values right
        for (int c = 4; c >= 0; c--)
        {
            if (board[r][c] != 0)
            {
                temp[pos] = board[r][c];
                pos--;
            }
        }

        // Merge matching values
        for (int c = 4; c > 0; c--)
        {
            if (temp[c] != 0 && temp[c] == temp[c - 1])
            {
                temp[c] *= 2;
                temp[c - 1] = 0;
                c--;
            }
        }

        // Shift right again
        int result[5] = {0};
        pos = 4;

        for (int c = 4; c >= 0; c--)
        {
            if (temp[c] != 0)
            {
                result[pos] = temp[c];
                pos--;
            }
        }

        for (int c = 0; c < 5; c++)
        {
            board[r][c] = result[c];
        }
    }
}

/*
    MOVE UP
*/
void move_up(int board[][5], int numrows = 5)
{
    for (int c = 0; c < 5; c++)
    {
        int temp[5] = {0};
        int pos = 0;

        // Shift nonzero values up
        for (int r = 0; r < numrows; r++)
        {
            if (board[r][c] != 0)
            {
                temp[pos] = board[r][c];
                pos++;
            }
        }

        // Merge matching values
        for (int r = 0; r < 4; r++)
        {
            if (temp[r] != 0 && temp[r] == temp[r + 1])
            {
                temp[r] *= 2;
                temp[r + 1] = 0;
                r++;
            }
        }

        // Shift up again
        int result[5] = {0};
        pos = 0;

        for (int r = 0; r < 5; r++)
        {
            if (temp[r] != 0)
            {
                result[pos] = temp[r];
                pos++;
            }
        }

        for (int r = 0; r < numrows; r++)
        {
            board[r][c] = result[r];
        }
    }
}

/*
    MOVE DOWN
*/
void move_down(int board[][5], int numrows = 5)
{
    for (int c = 0; c < 5; c++)
    {
        int temp[5] = {0};
        int pos = 4;

        // Shift nonzero values down
        for (int r = 4; r >= 0; r--)
        {
            if (board[r][c] != 0)
            {
                temp[pos] = board[r][c];
                pos--;
            }
        }

        // Merge matching values
        for (int r = 4; r > 0; r--)
        {
            if (temp[r] != 0 && temp[r] == temp[r - 1])
            {
                temp[r] *= 2;
                temp[r - 1] = 0;
                r--;
            }
        }

        // Shift down again
        int result[5] = {0};
        pos = 4;

        for (int r = 4; r >= 0; r--)
        {
            if (temp[r] != 0)
            {
                result[pos] = temp[r];
                pos--;
            }
        }

        for (int r = 0; r < numrows; r++)
        {
            board[r][c] = result[r];
        }
    }
}

#endif