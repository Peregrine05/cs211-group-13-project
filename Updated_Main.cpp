#include <iostream>
#include <ctime>
#include "2048_helper.h"

using namespace std;

int main()
{
    srand(time(0));

    int size = 5;

    int board[5][5] =
    {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    // Start with two tiles
    insert_random(board, size);
    insert_random(board, size);

    cout << "===== 2048 (5x5) =====" << endl;

    while (true)
    {
        print_board(board);

        cout << "Score: " << get_score() << endl;

        // Win check
        if (check_win(board))
        {
            cout << "\nCongratulations! You reached 2048!" << endl;
            break;
        }

        // Game over check
        if (game_over(board))
        {
            cout << "\nGAME OVER!" << endl;
            cout << "Final Score: " << get_score() << endl;
            break;
        }

        char choice;

        cout << "\nEnter move:" << endl;
        cout << "u = Up" << endl;
        cout << "d = Down" << endl;
        cout << "l = Left" << endl;
        cout << "r = Right" << endl;
        cout << "e = Exit" << endl;
        cout << "Choice: ";

        cin >> choice;

        if (choice == 'e')
        {
            cout << "Thanks for playing!" << endl;
            break;
        }

        int oldBoard[5][5];
        copy_board(board, oldBoard);

        switch(choice)
        {
            case 'u':
                move_up(board, size);
                break;

            case 'd':
                move_down(board, size);
                break;

            case 'l':
                move_left(board, size);
                break;

            case 'r':
                move_right(board, size);
                break;

            default:
                cout << "Invalid choice!" << endl;
                continue;
        }

        // Only add a tile if board changed
        if (board_changed(oldBoard, board))
        {
            insert_random(board, size);
        }
    }

    return 0;
}