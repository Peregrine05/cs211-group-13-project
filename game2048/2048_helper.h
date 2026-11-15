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

        // Move nonzero tiles to the left
        for (int c = 0; c < 5; c++)
        {
            if (board[r][c] != 0)
            {
                temp[pos] = board[r][c];
                pos++;
            }
        }

        // Merge matching tiles once
        for (int c = 0; c < 4; c++)
        {
            if (temp[c] != 0 && temp[c] == temp[c + 1])
            {
                temp[c] *= 2;
                temp[c + 1] = 0;
                c++;
            }
        }

        // Move remaining tiles left after merging
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

        // Copy finished row back to board
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = result[c];
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

