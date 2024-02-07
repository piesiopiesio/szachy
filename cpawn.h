#ifndef CPAWN_H
#define CPAWN_H

#include "CPiece.h"

class CPawn : public CPiece {
public:
    CPawn(int player = 0);;
    virtual ~CPawn();

    // Implement CPiece's pure virtual functions
    void move() override;
    void capture() override;
    bool isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
    bool isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
    void promote(CBoard& board, int row, int col); // Promotion function
};

#endif // CPAWN_H
