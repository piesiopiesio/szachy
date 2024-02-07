#ifndef CKNIGHT_H
#define CKNIGHT_H
#include "cpiece.h"

class CKnight : public CPiece {
public:
    CKnight(int player = 0);;
    virtual ~CKnight();

    // Implement CPiece's pure virtual functions
    void move() override;
    void capture() override;
    bool isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
    bool isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
};
#endif // CKNIGHT_H
