#include <iostream>

#include "othello.h"

Othello othello{};

int main() {
    int x, y;
    bool passed = false;
    while (true)
    {
        othello.printBoard();
        if (!othello.canPutSomewhere()) {
            if (passed) {
                break;
            } else {
                othello.changeTurn();
                passed = true;
                continue;
            }
        }

        while (true)
        {
            std::cout << "turn : " << (othello.getTurn() == Othello::Black ? "●" : "○") << std::endl;

            std::cout << "x : ";
            scanf("%d", &x);
            std::cout << "y : ";
            scanf("%d", &y);

            x--;
            y--;

            if (othello.isOutOfBoard(x, y)) {
                std::cout << "out of board !!" << std::endl;
            } else if (!othello.canPut(x, y)) {
                std::cout << "cannot put here ..." << std::endl;
            } else {
                break;
            }
        }

        othello.flip(x, y);
        othello.changeTurn();
    }
    std::cout << "finish !!" << std::endl;

    return 0;
}