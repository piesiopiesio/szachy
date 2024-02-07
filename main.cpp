#include "cboard.h"
#include "cclock.h"
#include <iostream>

int main() {
    CBoard chessBoard;
    chessBoard.setupBoard();
    // Display the current state of the board
    chessBoard.displayBoard();

    int currentPlayer = 1; // 0 for player 1, 1 for player 2
    int opponent = 2;
    int tmp = -1;
    bool gameOver = false;

    while (!gameOver) {
         // Prompt for player move
        int fromRow, fromCol, toRow, toCol;
        std::cout << "Player " << currentPlayer << "'s turn:\n";
        std::cout << "Enter the source and destination coordinates (fromRow, fromCol, toRow, toCol): ";
        std::cin >> fromRow >> fromCol >> toRow >> toCol;

        // Validate the move
        std::cout << "Validating move\n";
        if (chessBoard.isValidMove(currentPlayer, fromRow, fromCol, toRow, toCol)) {
            // Make the move
            std::cout << "Making move\n";
            chessBoard.makeMove(currentPlayer, fromRow, fromCol, toRow, toCol);
            // Display the updated board after the move
            chessBoard.displayBoard();

            // Check for checkmate, stalemate, or other game-over conditions
            if (chessBoard.isGameOver(opponent)) {
                std::cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
        }
        else{
            if(chessBoard.isValidCapture(currentPlayer, fromRow, fromCol, toRow, toCol)) {
                // Make the capture
                std::cout << "Capturing\n";
                chessBoard.makeCapture(currentPlayer, fromRow, fromCol, toRow, toCol);

                // Display the updated board after the move
                chessBoard.displayBoard();

                // Check for checkmate, stalemate, or other game-over conditions
                if (chessBoard.isGameOver(opponent)) {
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                }
            }
            else{
                std::cout << "Invalid move. Try again.\n";
                tmp = currentPlayer;
                currentPlayer = opponent;
                opponent = tmp;
            }
        }

        // Switch to the next player
        tmp = currentPlayer;
        currentPlayer = opponent;
        opponent = tmp;
    }

    return 0;
}
