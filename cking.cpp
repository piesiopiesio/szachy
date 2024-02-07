#include "cking.h"
#include <iostream>

CKing::CKing(int player) : CPiece(player) {
    std::cout << "Creating a king.\n";
}

CKing::~CKing() {
    std::cout << "Destroying a king.\n";
}

void CKing::move() {
    std::cout << "King moves one square in any direction.\n";
}

void CKing::capture() {
    std::cout << "King captures an opponent.\n";
}

bool CKing::isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // Check if the move is one square in any direction
    return std::abs(toRow - fromRow) <= 1 && std::abs(toCol - fromCol) <= 1;
}

bool CKing::isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const {
    // For the king, capturing is the same as moving
    return isValidMove(board, fromRow, fromCol, toRow, toCol);
}
