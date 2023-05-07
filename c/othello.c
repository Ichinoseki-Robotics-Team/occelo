#include <stdio.h>
#include "othello.h"

int FLIP_DIRS[8][2] = {
    {-1, -1},
    {0, -1},
    {1, -1},

    {-1, 0},
    {1, 0},
    
    {-1, 1},
    {0, 1},
    {1, 1},
};

int is_out_of_board(int x, int y) {
    if ((x < 0 || 7 < x) || (y < 0 || 7 < y)){
        return true;
    }
    return false;
}

int can_put_somewhere(int player, int board[8][8]) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (can_put(player, board, x, y)) {
                return true;
            }
        }
    }
    return false;
}

int can_put(int player, int board[8][8], int x, int y) {
    int cx = x, cy = y;
    int here;
    int can_flip = false;

    if (is_out_of_board(x, y)) {
        return false;
    }
    if (board[y][x] != 0) {
        return false;
    }

    for (int di = 0; di < 8; di++) {
        cx = x, cy = y;
        can_flip = false;

        for (int i = 0; i < 8; i++) {
            cx += FLIP_DIRS[di][0];
            cy += FLIP_DIRS[di][1];
            // printf("%d, %d", cx, cy);
            if (is_out_of_board(cx, cy)) {
                break;
            }
            here = board[cy][cx];
            if (here == 0) {
                break;
            } else if (here != player) {
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

void flip(int player, int board[8][8], int x, int y) {
    int cx = x, cy = y;
    int dir[2];
    int here;
    int can_flip = false;

    for (int di = 0; di < 8; di++) {
        cx = x, cy = y;
        can_flip = false;

        for (int i = 0; i < 8; i++) {
            cx += FLIP_DIRS[di][0];
            cy += FLIP_DIRS[di][1];
            if (is_out_of_board(cx, cy)) {
                break;
            }
            here = board[cy][cx];
            if (here == 0) {
                break;
            } else if (here != player) {
                can_flip = true;
            } else {
                if (can_flip) {
                    int fx = x, fy = y;
                    for (int fi = 0; fi < 8; fi++) {
                        board[fy][fx] = player;
                        fx += FLIP_DIRS[di][0];
                        fy += FLIP_DIRS[di][1];
                        if (board[fy][fx] == player) {
                            break;
                        } else {
                            board[fy][fx] == player;
                        }
                    }
                }
                break;
            }
        }
    }    
}

void print_board(int board[8][8]) {
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int y = 0; y < 8; y++) {
        printf("|");
        for (int x = 0; x < 8; x++) {
            if (board[y][x] == 0) {
                printf("   |");
            } else if (board[y][x] == 1) {
                printf(" ● |");
            } else {
                printf(" ○ |");
            }
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    } 
}