#include <iostream>
#include <random>
#include <iomanip>
#include <fstream>
#include "2048_helper.h"

using namespace std;

// Global score
static int score = 0;

// Global move count
static int num_moves = 0;

// Largest tile value
static int largest_tile = 2;

/*
====================================================
MOVE LEFT
====================================================
*/
void move_left(int board[][5], int numrows)
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
                if (temp[c] > largest_tile) {
                    largest_tile = temp[c];
                }
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
void move_right(int board[][5], int numrows)
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
                if (temp[c] > largest_tile) {
                    largest_tile = temp[c];
                }
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
void move_up(int board[][5], int numrows)
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
                if (temp[c] > largest_tile) {
                    largest_tile = temp[c];
                }
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
void move_down(int board[][5], int numrows)
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
                if (temp[c] > largest_tile) {
                    largest_tile = temp[c];
                }
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
void print_board(int board[][5], int numrows)
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
}

/*
====================================================
INSERT RANDOM TILE
====================================================
*/
void insert_random(int board[][5], int numrows)
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
                board[r][c] = 2;
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
void copy_board(int source[][5], int destination[][5], int numrows)
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
bool board_changed(int before[][5], int after[][5], int numrows)
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
GET NUMBER OF MOVES
====================================================
*/
int get_num_moves()
{
    return num_moves;
}

/*
====================================================
INCREMENT NUMBER OF MOVES
====================================================
*/
void increment_num_moves()
{
    num_moves++;
}

/*
====================================================
GET LARGEST TILE VALUE
====================================================
*/
int get_largest_tile()
{
    return largest_tile;
}

/*
====================================================
FIND LARGEST TILE VALUE
====================================================
*/
int find_largest_tile(int board[][5], int numrows)
{
    int largest = 2;
    for (int i = 0; i < numrows; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] > largest) {
                largest = board[i][j];
            }
        }
    }
    largest_tile = largest;
    return largest;
}

/*
====================================================
WIN CHECK
====================================================
*/
bool check_win(int board[][5], int numrows)
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
bool board_full(int board[][5], int numrows)
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
bool game_over(int board[][5], int numrows)
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

/*
====================================================
RESET THE GAME SCORES
====================================================
*/
void reset_scores() {
    score = 0;
    num_moves = 0;
    largest_tile = 2;
}

/*
====================================================
RESET THE GAME STATE
====================================================
*/
void reset_game(int board[][5], int numrows) {
    reset_scores();
    for (int i = 0; i < numrows; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = 0;
        }
    }
    insert_random(board, numrows);
    insert_random(board, numrows);
}

/*
====================================================
CONFIRM WHETHER TO RESET GAME
====================================================
*/
bool confirm_reset_game() {
    char choice;

    while (true) {
        cout << "Are you sure you want to reset the game (Y/n): ";
        cin >> choice;
        switch (choice) {
            case 'Y':
            case 'y':
                return true;
            case 'N':
            case 'n':
                return false;
        }
    }
}

/*
====================================================
SAVE THE GAME TO A FILE
====================================================
*/
bool save_game(int board[][5], int numrows) {
    ofstream ofs("savegame.txt");
    if (!ofs.is_open()) {
        return false;
    }
    ofs << "CS211_2048_V1" << endl;
    ofs << score << " " << num_moves << endl;
    for (int i = 0; i < numrows; i++) {
        for (int j = 0; j < 5; j++) {
            ofs << board[i][j] << " ";
        }
        ofs << endl;
    }
    ofs.close();
    return true;
}

/*
====================================================
LOAD THE GAME FROM A FILE
====================================================
*/
bool load_game(int board[][5], int numrows) {
    ifstream ifs("savegame.txt");
    if (!ifs.is_open()) {
        return false;
    }

    const char STANDARD_VERSION[] = "CS211_2048_V1";
    char version[14];
    ifs.getline(version, 14);
    for (int i = 0; i < 14; i++) {
        if (version[i] != STANDARD_VERSION[i]) {
            cout << "File version does not match: Expected " << STANDARD_VERSION
            << ", got " << version << endl;
            ifs.close();
            return false;
        }
    }

    int temp_score;
    ifs >> temp_score;
    if (temp_score < 0) {
        cout << "Invalid saved score value: Expected a positive value, got " << temp_score << endl;
        ifs.close();
        return false;
    }
    score = temp_score;

    int temp_num_moves;
    ifs >> temp_num_moves;
    if (temp_num_moves < 0) {
        cout << "Invalid saved number of moves: Expected a positive value, got " << temp_num_moves
        << endl;
        ifs.close();
        return false;
    }
    num_moves = temp_num_moves;

    int temp_board[numrows][5];
    for (int i = 0; i < numrows; i++) {
        for (int j = 0; j < 5; j++) {
            ifs >> temp_board[i][j];
            if (temp_board[i][j] < 0 || !is_valid_tile(temp_board[i][j])) {
                cout << "Invalid tile value at row: " << i << " and column " << j << ": Expected"
                << " zero or a positive power of 2 greater than 1, got " << temp_board[i][j]
                << endl;
                ifs.close();
                return false;
            }
        }
    }
    copy_board(temp_board, board);
    find_largest_tile(board);

    ifs.close();
    return true;
}

/*
====================================================
CHECK IF NUMBER IS A VALID TILE
====================================================
*/
bool is_valid_tile(int num) {
    if (num < 0 || num == 1) {
        return false;
    }
    return (num == 0) || ((num & (num - 1)) == 0);
}
