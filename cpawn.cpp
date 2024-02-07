#include "cpawn.h"
#include "cboard.h" // Include the necessary header for CBoard
#include "cqueen.h"
#include <iostream>

CPawn::CPawn(int player) : CPiece(player) {
    std::cout << "Creating a pawn.\n";
}

CPawn::~CPawn() {
    std::cout << "Destroying a pawn.\n";
}

void CPawn::move() {
    std::cout << "Pawn moves forward.\n";
}

void CPawn::capture() {
    std::cout << "Pawn captures an opponent.\n";
}

bool CPawn::isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    using namespace std;
    // Pawns can move forward one square or two squares on their first move
    if (getPlayer() == 1) {
        // Player 1's pawn moves up the board
        if ((toRow - fromRow == 1 || (fromRow == 1 && toRow - fromRow == 2))&&fromCol==toCol) {
            // Check if the destination square is empty
            return board.isEmpty(toRow, toCol);
        }
    } else if (getPlayer() == 2) {
        // Player 2's pawn moves down the board

        if ((fromRow - toRow == 1 || (fromRow == 6 && fromRow - toRow == 2))&&fromCol==toCol) {
            // Check if the destination square is empty
            return board.isEmpty(toRow, toCol);
        }
    }

    return false; // Invalid move
}

bool CPawn::isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Pawns can capture diagonally
    if (std::abs(toRow - fromRow) == 1 && std::abs(toCol - fromCol) == 1) {
        // Check if there is an opponent's piece at the destination square
        return board.isOpponentPiece(fromRow, fromCol, toRow, toCol);
    }

    return false; // Invalid capture
}

void CPawn::promote(CBoard& board, int row, int col) {
    // Promote the pawn to a queen (you can customize this logic)
    board.removePiece(row, col);
    board.placePiece(new CQueen(getPlayer()), row, col);
    std::cout << "Pawn promoted to a queen.\n";
}
