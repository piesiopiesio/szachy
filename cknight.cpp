#include "cknight.h"
#include <iostream>

CKnight::CKnight(int player) : CPiece(player) {
    std::cout << "Creating a knight.\n";
}

CKnight::~CKnight() {
    std::cout << "Destroying a knight.\n";
}

void CKnight::move() {
    std::cout << "Knight moves in an 'L' shape.\n";
}

void CKnight::capture() {
    std::cout << "Knight captures an opponent.\n";
}

bool CKnight::isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    int rowDiff = std::abs(toRow - fromRow);
    int colDiff = std::abs(toCol - fromCol);

    // Knight moves in an L-shape: 2 squares in one direction and 1 square perpendicular to that
    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}

bool CKnight::isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Knight captures using the same L-shaped movement
    return isValidMove(board, fromRow, fromCol, toRow, toCol);
}
