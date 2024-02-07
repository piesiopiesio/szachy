#include "cboard.h"
#include "cpiece.h"
#include "cpawn.h"
#include "cbishop.h"
#include "crook.h"
#include "cknight.h"
#include "cqueen.h"
#include "cking.h"

#include <iostream>


CBoard::CBoard() {
    std::cout << "Creating a chess board.\n";
}

CBoard::~CBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            delete board[i][j];
        }
    }

    std::cout << "Destroying the chess board.\n";
}

// Implementation for removePiece and placePiece
void CBoard::removePiece(int row, int col) {
    delete board[row][col];
    board[row][col] = nullptr;
}

void CBoard::placePiece(CPiece* piece, int row, int col) {
    board[row][col] = piece;
}

void CBoard::displayBoard() const {
    using namespace std;
    for (int i = 7; i >= 0; --i) {
        cout<<i<<" ";
        for (int j = 0; j < 8; ++j) {
            CPiece* piece = board[i][j];
            if (piece == nullptr) {
                cout << "_|";
            } else {
                if (typeid(*piece) == typeid(CKing)) {
                    if (piece->getPlayer() == 1) {
                        cout << "K";
                    } else {
                        cout << "k";
                    }
                } else if (typeid(*piece) == typeid(CRook)) {
                    if (piece->getPlayer() == 1) {
                        cout << "R";
                    } else {
                        cout << "r";
                    }
                } else if (typeid(*piece) == typeid(CBishop)) {
                    if (piece->getPlayer() == 1) {
                        cout << "B";
                    } else {
                        cout << "b";
                    }
                } else if (typeid(*piece) == typeid(CKnight)) {
                    if (piece->getPlayer() == 1) {
                        cout << "N";
                    } else {
                        cout << "n";
                    }
                } else if (typeid(*piece) == typeid(CPawn)) {
                    if (piece->getPlayer() == 1) {
                        cout << "P";
                    } else {
                        cout << "p";
                    }
                } else if (typeid(*piece) == typeid(CQueen)) {
                    if (piece->getPlayer() == 1) {
                        cout << "Q";
                    } else {
                        cout << "q";
                    }
                }
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "X 0 1 2 3 4 5 6 7" << endl;
}


void CBoard::setupBoard() {
    // Player 1's pawns
    for (int i = 0; i < 8; ++i) {
        board[1][i] = new CPawn(1); // Pass player 1 to the constructor
    }

    // Player 1's rooks
    board[0][0] = new CRook(1);
    board[0][7] = new CRook(1);

    // Player 1's knights
    board[0][1] = new CKnight(1);
    board[0][6] = new CKnight(1);

    // Player 1's bishops
    board[0][2] = new CBishop(1);
    board[0][5] = new CBishop(1);

    // Player 1's queen
    board[0][3] = new CQueen(1);

    // Player 1's king
    board[0][4] = new CKing(1);

    // Player 2's pawns
    for (int i = 0; i < 8; ++i) {
        board[6][i] = new CPawn(2); // Pass player 2 to the constructor
    }

    // Player 2's rooks
    board[7][0] = new CRook(2);
    board[7][7] = new CRook(2);

    // Player 2's knights
    board[7][1] = new CKnight(2);
    board[7][6] = new CKnight(2);

    // Player 2's bishops
    board[7][2] = new CBishop(2);
    board[7][5] = new CBishop(2);

    // Player 2's queen
    board[7][3] = new CQueen(2);

    // Player 2's king
    board[7][4] = new CKing(2);

    // Initialize the rest of the board as nullptr
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = nullptr;
        }
    }
}

bool CBoard::isEmpty(int row, int col) const {
    if (row >= 0 && row < 8 && col >= 0 && col < 8) {
        return board[row][col] == nullptr;
    }
    return false;
}

bool CBoard::isOpponentPiece(int fromRow, int fromCol, int toRow, int toCol) const {
    if (fromRow >= 0 && fromRow < 8 && fromCol >= 0 && fromCol < 8 &&
        toRow >= 0 && toRow < 8 && toCol >= 0 && toCol < 8) {
        const CPiece* fromPiece = board[fromRow][fromCol];
        const CPiece* toPiece = board[toRow][toCol];

        // Check if there is a piece at 'from' and 'to' positions
        if (fromPiece != nullptr && toPiece != nullptr) {
            // Check if the pieces belong to different players
            return (fromPiece->getPlayer() != toPiece->getPlayer());
        }
    }
    return false;
}

bool CBoard::isValidMove(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol) const {
    // Check if the move is valid based on the piece logic
    if ((board[fromRow][fromCol] != nullptr)&&(board[toRow][toCol] == nullptr)) {
        return board[fromRow][fromCol]->isValidMove(*this, fromRow, fromCol, toRow, toCol);
    }
    return false;
}

bool CBoard::isValidCapture(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol) const {
    // Check if the move is valid based on the piece logic
    if ((board[fromRow][fromCol] != nullptr)&&(board[toRow][toCol]->getPlayer() != currentPlayer)) {
        return board[fromRow][fromCol]->isValidCapture(*this, fromRow, fromCol, toRow, toCol);
    }
    return false;
}

void CBoard::makeMove(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol) {
    // Make the move based on the piece logic
    if (board[fromRow][fromCol] != nullptr) {
        board[fromRow][fromCol]->move();
        // Move the piece in the board
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = nullptr;
    }
}

void CBoard::makeCapture(int currentPlayer, int fromRow, int fromCol, int toRow, int toCol) {
    // Make the move based on the piece logic
    if (board[toRow][toCol]->getPlayer() != currentPlayer) {
        board[fromRow][fromCol]->capture();
        // Move the piece in the board
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = nullptr;
    }
}

bool CBoard::isGameOver(int currentPlayer) const {
    // Check for checkmate or stalemate
    if (isInCheck(currentPlayer)) {
        // Check if the player is in checkmate
        std::cout << "Check! Player " << currentPlayer << "\n";
              if (isCheckmate(currentPlayer)) {
            std::cout << "Checkmate! Player " << currentPlayer << " loses.\n";
            return true;
        }
    } else {
        // Check for stalemate
        if (isStalemate(currentPlayer)) {
            std::cout << "Stalemate! It's a draw.\n";
            return true;
        }
    }
    return false;
}

bool CBoard::isInCheck(int currentPlayer) const {
    using namespace std;
    // Find the position of the current player's king
    int kingRow = -1;
    int kingCol = -1;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            CPiece* piece = board[i][j];
            if (piece != nullptr && piece->getPlayer() == currentPlayer && dynamic_cast<CKing*>(piece) != nullptr) {
                // Found the king
                kingRow = i;
                kingCol = j;
                break;
            }
        }
        if (kingRow != -1 && kingCol != -1) {
            break;
        }
    }

    // Check if the king is under attack
    if (kingRow != -1 && kingCol != -1) {
        // Iterate through all opponent pieces and check if they can capture the king
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                CPiece* piece = board[i][j];
                if (piece != nullptr && piece->getPlayer() != currentPlayer) {
                    if (piece->isValidCapture(*this, i, j, kingRow, kingCol)) {
                        // The king is under attack
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool CBoard::isCheckmate(int currentPlayer) const {
    // Check if the current player is in check
    if (isInCheck(currentPlayer)) {
        // Iterate through all pieces of the current player and check if any move can get out of check
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                CPiece* piece = board[i][j];
                if (piece != nullptr && piece->getPlayer() == currentPlayer) {
                    // Check if any legal move can get out of check
                    for (int toRow = 0; toRow < 8; ++toRow) {
                        for (int toCol = 0; toCol < 8; ++toCol) {
                            if (isValidMove(currentPlayer, i, j, toRow, toCol)) {
                                // Create a deep copy of the board
                                CBoard tempBoard(*this);
                                // Try making the move and see if it gets out of check
                                if(tempBoard.isValidCapture(currentPlayer, i, j, toRow, toCol))
                                    tempBoard.makeMove(currentPlayer, i, j, toRow, toCol);
                                if (!tempBoard.isInCheck(currentPlayer)) {
                                    // The move successfully gets out of check
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        // If no move can get out of check, it's checkmate
        return true;
    }

    // If the player is not in check, they are not in checkmate
    return false;
}


bool CBoard::isStalemate(int currentPlayer) const {
    // Check if the current player is not in check
    if (!isInCheck(currentPlayer)) {
        // Iterate through all pieces of the current player and check if any move is possible
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                CPiece* piece = board[i][j];
                if (piece != nullptr && piece->getPlayer() == currentPlayer) {
                    // Check if any legal move is possible
                    for (int toRow = 0; toRow < 8; ++toRow) {
                        for (int toCol = 0; toCol < 8; ++toCol) {
                            if (isValidMove(currentPlayer, i, j, toRow, toCol)) {
                                // A legal move is possible, so it's not stalemate
                                return false;
                            }
                        }
                    }
                }
            }
        }
        // If no legal move is possible and the player is not in check, it's stalemate
        return true;
    }

    // If the player is in check, it's not stalemate
    return false;
}

CPiece* CBoard::getPieceAt(int row, int col) const {
    if (row >= 0 && row < 8 && col >= 0 && col < 8) {
        return board[row][col];
    }
    return nullptr;
}
