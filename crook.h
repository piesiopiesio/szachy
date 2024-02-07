#ifndef CROOK_H
#define CROOK_H
#include "cpiece.h"

class CRook : public CPiece {
public:
    CRook(int player = 0);;
    virtual ~CRook();

    // Implement CPiece's pure virtual functions
    void move() override;
    void capture() override;
    bool isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
    bool isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const override;
private:
    bool isPathClear(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const;
};

#endif // CROOK_H
