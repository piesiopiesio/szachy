#ifndef CBISHOP_H
#define CBISHOP_H
#include "cpiece.h"

class CBishop : public CPiece {
public:
    CBishop(int player = 0);;
    virtual ~CBishop();

    // Implement CPiece's pure virtual functions
    void move() override;
    void capture() override;
    bool isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
    bool isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
private:
    bool isPathClear(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const;
};

#endif // CBISHOP_H
