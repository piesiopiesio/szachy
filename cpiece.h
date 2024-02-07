#ifndef CPIECE_H
#define CPIECE_H

class CBoard; // Forward declaration

class CPiece {
public:
    CPiece(int player = 0); // Add a default parameter to the constructor
    virtual ~CPiece(); // Virtual destructor

    // Pure virtual functions for derived classes to implement
    virtual void move() = 0;
    virtual void capture() = 0;
    virtual bool isValidMove(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const = 0;
    virtual bool isValidCapture(const CBoard& board, int fromRow, int fromCol, int toRow, int toCol) const = 0;

    // Accessor for player
    int getPlayer() const;

private:
    int player; // Player identifier
};

#endif // CPIECE_H
