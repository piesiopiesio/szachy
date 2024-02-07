#include "cqueen.h"
#include "cboard.h"
#include <iostream>

CQueen::CQueen(int player) : CPiece(player) {
    std::cout << "Creating a queen.\n";
}

CQueen::~CQueen() {
    std::cout << "Destroying a queen.\n";
}

void CQueen::move() {
    std::cout << "Queen moves horizontally, vertically, or diagonally.\n";
}

void CQueen::capture() {
    std::cout << "Queen captures an opponent.\n";
}

bool CQueen::isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    if(isPathClear(board, fromRow, fromCol, toRow, toCol))
        return fromRow == toRow || fromCol == toCol || std::abs(toRow - fromRow) == std::abs(toCol - fromCol);
}

bool CQueen::isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    return isValidMove(board, fromRow, fromCol, toRow, toCol);
}

bool CQueen::isPathClear(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Check if the path from (fromRow, fromCol) to (toRow, toCol) is clear of obstacles

    // Determine the direction of movement
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
