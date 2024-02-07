#include "cbishop.h"
#include "cboard.h"
#include <iostream>

CBishop::CBishop(int player) : CPiece(player) {
    std::cout << "Creating a bishop.\n";
}

CBishop::~CBishop() {
    std::cout << "Destroying a bishop.\n";
}

void CBishop::move() {
    std::cout << "Bishop moves diagonally.\n";
}

void CBishop::capture() {
    std::cout << "Bishop captures an opponent diagonally.\n";
}

bool CBishop::isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Bishop moves diagonally, so the absolute difference between rows and columns should be equal
    return std::abs(toRow - fromRow) == std::abs(toCol - fromCol) && isPathClear(board, fromRow, fromCol, toRow, toCol);
}

bool CBishop::isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Bishop captures diagonally, so the absolute difference between rows and columns should be equal
    return std::abs(toRow - fromRow) == std::abs(toCol - fromCol) && isPathClear(board, fromRow, fromCol, toRow, toCol);
}

bool CBishop::isPathClear(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Check if the diagonal path from (fromRow, fromCol) to (toRow, toCol) is clear of obstacles
    int rowDir = (toRow - fromRow > 0) ? 1 : -1;
    int colDir = (toCol - fromCol > 0) ? 1 : -1;

    for (int i = 1; i < std::abs(toRow - fromRow); ++i) {
        int intermediateRow = fromRow + i * rowDir;
        int intermediateCol = fromCol + i * colDir;

        if (!board.isEmpty(intermediateRow, intermediateCol)) {
            // There is an obstacle in the path
            return false;
        }
    }

    // The path is clear
    return true;
}
