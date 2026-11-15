# cs211-group-13-project

Session: MW

Group: 13

Repo URL: [https://github.com/Peregrine05/cs211-group-13-project](https://github.com/Peregrine05/cs211-group-13-project)

---

### 2048

2048 is a game where the player must choose directions to move tiles, with the goal of creating a tile of value 2048. This implementation of the game uses a 5x5 grid, and players can save their progress to a "savegame.txt" file in the current working directory to be loaded at a later time. This implementation of 2048 only supports one save file in the working directory. Attempting to save when a save already exists will result in previous save data being overwritten.

To play the game, follow the on-screen prompts.

- `u`: Merge tiles up
- `d`: Merge tiles down
- `l`: Merge tiles left
- `r`: Merge tiles right
- `n`: Start a new game
- `s`: Save your current game to "savegame.txt" in the current working directory
- `o`: Load the saved game from "savegame.txt" in the current working directory
- `h`: Get in-game help
- `e`: Exit without saving

### Luhn Algorithm

The Luhn checksum algorithm is an algorithm that determines whether a 16-digit number, such as those used on credit cards, can represent a valid credit card number.

To use the program, follow the on-screen prompts.

- `1`: Input a number to check if it can represent a valid credit card number
- `2`: Exit the program

---

## Building

To build and run the programs, ensure you have a C++ compiler installed.

On Linux, run the following commands to run 2048:

```shell
g++ game2048/main.cpp game2048/2048_helper.cpp -o game2048_app
./game2048_app
```

To run the Luhn checksum program, run the following commands:

```shell
g++ luhn/luhn.cpp -o luhn_app
./luhn_app
```

On Windows, if you are using Visual Studio Code with the correct C++ extensions installed, then you can just click the play button to compile and run the program. If you do not have a way to compile C++ code on your computer, then you may upload the files to [OnlineGDB](https://www.onlinegdb.com), and run them there.

## Collaborators:

- Peregrine05
- tyler-eric-west
- PibosGit

## Task Plan

**Peregrine05**:
- Checkpoint 1: Create GitHub repository, invite members, set up folders, upload starter files, create README and project plan, open first PR.
- Checkpoint 4: Implement 2048 save/load system, file validation, state preservation after failed loads, and save/load testing.
- Reviews: Member tyler-eric-west's PRs
- Merges: Member PibosGit's approved PRs

**tyler-eric-west**:
- Checkpoint 2: Implement move_left, merge logic, merge-once rule, and required movement tests.
- Checkpoint 5: Implement the Luhn program, input validation, checksum calculation, repeatable interaction, and required Luhn tests.
- Reviews: Member PibosGit's PRs
- Merges: Member Peregrine05's approved PRs

**PibosGit**
- Checkpoint 3: Implement move_right, move_up, move_down, scoring, tile insertion, menu
controls, win/game-over logic.
- Checkpoint 6: Complete README, report.pdf, tests.md, contributions.md, final packaging, and
clean-build verification.
- Reviews: Member Peregrine05's PRs
- Merges: Member tyler-eric-west's approved PRs
