#include "cpiece.h"
#include <iostream>

CPiece::CPiece(int player) : player(player) {
    // Constructor to set the player number
}

CPiece::~CPiece() {
    std::cout << "Destroying a piece.\n";
}

int CPiece::getPlayer() const {
    return player;
}

