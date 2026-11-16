#include <iostream>
#include <ctime>
#include "2048_helper.h"

using namespace std;

int main()
{
    srand(time(0));

    const int size = 5;

    int board[size][size];

    reset_game(board);

    bool won_game = false;
    bool lost_game = false;

    cout << "===== 2048 (5x5) =====" << endl;

    while (true)
    {
        print_board(board);

        cout << "Score: " << get_score() << endl;
        cout << "Moves: " << get_num_moves() << endl;
        cout << "Largest tile: " << get_largest_tile() << endl;

        // Win check
        if (!won_game && check_win(board))
        {
            cout << "\nCongratulations! You reached 2048!" << endl;
            won_game = true;
        }

        // Game over check
        if (!lost_game && game_over(board))
        {
            cout << "\nGAME OVER!" << endl;
            cout << "Final Score: " << get_score() << endl;
            lost_game = true;
        }

        char choice;

        cout << "\nEnter move:" << endl;
        if (!lost_game) {
            cout << "u = Up" << endl;
            cout << "d = Down" << endl;
            cout << "l = Left" << endl;
            cout << "r = Right" << endl;
        }
        cout << "n = New Game" << endl;
        cout << "s = Save" << endl;
        cout << "o = Load" << endl;
        cout << "h = Help" << endl;
        cout << "e = Exit" << endl;
        cout << "Choice: ";

        cin >> choice;

        if (choice == 'e') {
            cout << "Thanks for playing!" << endl;
            break;
        } else if (choice == 'h') {
            cout << "2048 consists of a 5x5 board of tiles, each containing a number that is a"
            << " power of two. The goal of the game is to slide tiles up, down, left, or right"
            << " to combine matching tiles, with the end goal of creating a tile with value"
            << " 2048. Game progress may be saved by choosing 's' when prompted. Game"
            << " progress will be saved to a file called \"savegame.txt\" in the program's"
            << " working directory. This action will overwrite any progress previously"
            << " saved in that file. Game progress may be loaded from that file by"
            << " choosing 'o' when prompted." << endl;
            continue;
        } else if (choice == 'n') {
            if (confirm_reset_game()) {
                reset_game(board);
                won_game = false;
                lost_game = false;
            }
            continue;
        } else if (choice == 's') {
            if (save_game(board)) {
                cout << "Game state saved to \"savegame.txt\"." << endl;
            } else {
                cout << "Failed to save game to \"savegame.txt\". Missing file permissions?";
            }
            continue;
        } else if (choice == 'o') {
            if (load_game(board)) {
                cout << "Game state loaded from \"savegame.txt\"." << endl;
            } else {
                cout << "Failed to load game state from \"savegame.txt\". Make sure the file"
                << " exists in the working directory, and that it represents a valid game save."
                << endl;
            }
            continue;
        }

        if (lost_game) {
            continue;
        }

        // Handle movement
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
            increment_num_moves();
            insert_random(board, size);
        }
    }

    return 0;
}
