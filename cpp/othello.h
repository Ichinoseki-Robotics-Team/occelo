#ifndef OTHELLO_H
#define OTHELLO_H

#include <iostream>
#include <vector>

class Othello
{
public:
    enum Color {
        Empry = 0,
        Black = 1,
        White = 2,
    };

    typedef struct {
        int x;
        int y;
    } xy;

    Othello();
    bool canPutSomewhere();
    bool canPut(int x, int y);
    void flip(int x, int y);
    void changeTurn();
    bool isOutOfBoard(int x, int y);
    void printBoard();
    Color getTurn();

private:
    std::vector<std::vector<int>> board;
    Color turn;
    std::vector<xy> FLIP_DIRS = {
        xy{-1, -1},
        xy{0, -1},
        xy{1, -1},

        xy{-1, 0},
        xy{1, 0},

        xy{-1, 1},
        xy{0, 1},
        xy{1, 1},
    };
};


#endif // OTHELLO_H