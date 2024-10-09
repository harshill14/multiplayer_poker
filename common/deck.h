#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

class Deck {
    std::vector<Card> cards;
public:
    Deck();
    void reset();
    Card dealCard();
};

#endif
