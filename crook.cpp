#include "crook.h"
#include "cboard.h"
#include <iostream>

CRook::CRook(int player) : CPiece(player) {
    std::cout << "Creating a rook.\n";
}

CRook::~CRook() {
    std::cout << "Destroying a rook.\n";
}

void CRook::move() {
    std::cout << "Rook moves horizontally or vertically.\n";
}

void CRook::capture() {
    std::cout << "Rook captures an opponent.\n";
}

bool CRook::isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Rook moves vertically or horizontally, so either the rows or columns should be the same
    if(isPathClear(board, fromRow, fromCol, toRow, toCol))
        return fromRow == toRow || fromCol == toCol;
}

bool CRook::isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Rook captures in the same way it moves
    return isValidMove(board, fromRow, fromCol, toRow, toCol);
}

bool CRook::isPathClear(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Check if the diagonal path from (fromRow, fromCol) to (toRow, toCol) is clear of obstacles
    int rowDir = (toRow - fromRow > 0) ? 1 : (toRow - fromRow < 0) ? -1 : 0;
    int colDir = (toCol - fromCol > 0) ? 1 : (toCol - fromCol < 0) ? -1 : 0;

    // Iterate over the squares along the path
    for (int i = 1; i < std::max(std::abs(toRow - fromRow), std::abs(toCol - fromCol)); ++i) {
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
