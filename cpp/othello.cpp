#include "./othello.h"

Othello::Othello() {
    this->board = std::vector<std::vector<int>>{
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    this->turn = this->Black;
}

bool Othello::canPut(int x, int y) {
    xy dir;
    int cx = x, cy = y;
    bool can_flip = false;
    int here = 0;

    if (isOutOfBoard(x, y)) {
        return false;
    }

    if (board[y][x] != 0) {
        return false;
    }

    for (int di = 0; di < 8; di++) {
        dir = this->FLIP_DIRS[di];
        can_flip = false;
        cx = x, cy = y;

        for (int i = 0; i < 8; i++) {
            cx += dir.x;
            cy += dir.y;
            if (isOutOfBoard(cx, cy)) {
                break;
            }
            here = board[cy][cx];
            if (here == Empry) {
                break;
            } else if (here != turn) {
                can_flip = true;
            } else {
                if (can_flip) {
                    return true;
                }
                break;
            }
        }
    }
    return false;
}

bool Othello::canPutSomewhere() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (canPut(x, y)) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::isOutOfBoard(int x, int y) {
    if ((x < 0 || 7 < x) || (y < 0 || 7 < y)) {
        return true;
    } else {
        return false;
    }
}

void Othello::flip(int x, int y) {
    xy dir;
    int cx = x, cy = y;
    bool can_flip = false;
    int here = 0;

    for (int di = 0; di < 8; di++) {
        cx = x, cy = y;
        dir = this->FLIP_DIRS[di];
        can_flip = false;

        for (int i = 0; i < 8; i++) {
            cx += dir.x;
            cy += dir.y;
            if (isOutOfBoard(cx, cy)) {
                break;
            }
            here = board[cy][cx];
            if (here == Empry) {
                break;
            } else if (here != turn) {
                can_flip = true;
            } else {
                if (can_flip) {
                    int fx = x, fy = y;
                    board[fy][fx] = turn;
                    for (int fi = 0; fi < 8; fi++) {
                        fx += dir.x;
                        fy += dir.y;
                        if (board[fy][fx] == turn) {
                            break;
                        } else {
                            board[fy][fx] = turn;
                        }
                    }
                }
                break;
            }
        }
    }
}

void Othello::changeTurn() {
    turn = turn == Black ? White : Black;
}

void Othello::printBoard() {
    std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
    for (int y = 0; y < 8; y++) {
        std::cout << "|";
        for (int x = 0; x < 8; x++) {
            if (board[y][x] == 0) {
                std::cout << "   |";
            } else if (board[y][x] == 1) {
                std::cout << " ● |";
            } else {
                std::cout << " ○ |";
            }
        }
        std::cout << "\n+---+---+---+---+---+---+---+---+" << std::endl;
    } 
}


Othello::Color Othello::getTurn() {
    return turn;
}