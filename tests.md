### 2048

**Meets requirement: (true/false)**

1. Sliding and merging in each of the four directions, including movement through gaps.             TRUE
2. Three equal tiles and four equal tiles: no tile merges twice in one move.                        TRUE
3. A successful slide with no merge: one new 2, one counted move, no score gain.                    TRUE
4. An unchanged move: no inserted tile and no changed counters.                                     TRUE
5. A full board with a possible merge, and a full board with no possible moves.                     TRUE
6. Several merges in one move, correct score updates, and reaching the 2048 target.                 TRUE
7. Save, change the game, and load: exact restoration of all cells and counters.                    TRUE
8. Missing, incomplete, and malformed saves, including an invalid tile: active state is preserved.  TRUE
9. Help, invalid commands, new-game confirmation, and exit behavior                                 TRUE


### Luhn Checksum

**Meets requirement: (true/false)**

1. 4532015112830366 Correct format; checksum passes                         TRUE
2. 4532015112830367 Correct format; checksum fails                          TRUE
3. 0000000000000018 Correct format; leading zeros preserved; passes         TRUE
4. 453201511283036 Reject: 15 digits                                        TRUE
5. 45320151128303666 Reject: 17 digits                                      TRUE
6. 453201511283036X  Reject: non-digit                                      TRUE
7. Input containing an internal space Reject: malformed input               TRUE
8. Several checks followed by exit Results correct; loop exits cleanly      TRUE
