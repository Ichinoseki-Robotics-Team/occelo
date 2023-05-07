#ifndef OTHELLO_H
#define OTHELLO_H

#define true 1
#define false 0

#define empty 0
#define black 1
#define white 2

int can_put_somewhere(int player, int board[8][8]);
int can_put(int player, int board[8][8], int x, int y);
void flip(int player, int board[8][8], int x, int y);

int is_out_of_board(int x, int y);

void print_board(int board[8][8]);

#endif // OTHELLO_H
