#include <stdio.h>
#include "othello.h"

int main() {
    // 1 : black
    // 2 : white
    int board[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    int turn = black;
    int x, y;
    int passed = false;

    while (true)
    {
        printf("\x1b[1;1H\x1b[2J");
        print_board(board);
        if (!can_put_somewhere(turn, board)) {
            turn = (turn == black ? white : black);
            printf("passed !!\n");
            if (passed) {
                break;
            }
            passed = true;
            continue;
        } else {
            passed = false;
        }

        while (true)
        {
            printf("turn : ");
            if (turn == black) {
                printf("●\n");
            } else {
                printf("○\n");
            }
            printf("x : ");
            scanf("%d", &x);
            printf("y : ");
            scanf("%d", &y);

            x--;
            y--;

            if (is_out_of_board(x, y)) {
                printf("out of board !!\n");
            } else if (!can_put(turn, board, x, y)) {
                printf("cannot put here ...\n");
            } else {
                break;
            }
        }

        flip(turn, board, x, y);
        turn = (turn == black ? white : black);
    }
    printf("finish !!\n");

    return 0;
}