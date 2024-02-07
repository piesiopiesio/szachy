#ifndef CKING_H
#define CKING_H
#include "cpiece.h"

class CKing : public CPiece {
public:
    CKing(int player = 0);;
    virtual ~CKing();

    // Implement CPiece's pure virtual functions
    void move() override;
    void capture() override;
    bool isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
    bool isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
};

#endif // CKING_H
