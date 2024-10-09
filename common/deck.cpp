#include "deck.h"
#include <algorithm>
#include <ctime>
#include <random>

Deck::Deck() {
    reset();
}

void Deck::reset() {
    cards.clear();
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 1; rank <= 13; ++rank) {
            cards.push_back(Card(suit, rank));
        }
    }
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(std::time(0)));
}

Card Deck::dealCard() {
    Card dealt = cards.back();
    cards.pop_back();
    return dealt;
}
