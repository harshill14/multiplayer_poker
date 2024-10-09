#include "card.h"

Card::Card(int s, int r) : suit(s), rank(r) {}

std::string Card::toString() const {
    return "Suit: " + std::to_string(suit) + ", Rank: " + std::to_string(rank);
}
