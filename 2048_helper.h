#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++)
{
    int temp[5] = {0};
    int pos = 0;

    // Move all nonzero tiles to the left
    for (int c = 0; c < 5; c++)
    {
        if (board[r][c] != 0)
        {
            temp[pos] = board[r][c];
            pos++;
        }
    }

    // Merge matching tiles only once
    for (int c = 0; c < 4; c++)
    {
        if (temp[c] != 0 && temp[c] == temp[c + 1])
        {
            temp[c] *= 2;

            // Shift remaining tiles left
            for (int k = c + 1; k < 4; k++)
            {
                temp[k] = temp[k + 1];
            }

            temp[4] = 0;

            // Skip the tile created by this merge
            c++;
        }
    }

    // Copy the completed row back to the board
    for (int c = 0; c < 5; c++)
    {
        board[r][c] = temp[c];
    }
}
}

void move_right(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_up(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_down(int board[][5], int numrows = 5)
{
	//CODE HERE
}


void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
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
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}

