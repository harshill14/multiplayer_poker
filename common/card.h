#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    int suit;
    int rank;
public:
    Card(int s, int r);
    std::string toString() const;
};

#endif
