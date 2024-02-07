#ifndef CBOARD_H
#define CBOARD_H


#include "CPiece.h"

class CBoard {
public:
    CBoard();
    virtual ~CBoard();

    void setupBoard();
    void displayBoard() const;
    // Add more functions for board manipulation as needed
    CPiece* getPieceAt(int row, int col) const;

    // Add these functions to remove and place pieces
    void removePiece(int row, int col);
    void placePiece(CPiece* piece, int row, int col);

    bool isEmpty(int row, int col) const;
    bool isOpponentPiece(int fromRow, int fromCol, int toRow, int toCol) const;

    bool isValidMove(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol) const;
    bool isValidCapture(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol) const;
    void makeMove(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol);
    void makeCapture(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol);
    bool isGameOver(int currentPlayer) const;

    bool isInCheck(int currentPlayer) const;
    bool isCheckmate(int currentPlayer) const;
    bool isStalemate(int currentPlayer) const;

private:
    CPiece* board[8][8]; // 2D array representing the chess board
    bool isKingInCheck(int currentPlayer) const;
    bool isMoveLegal(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol) const;
};

#endif // CBOARD_H
