#include "network.h"
#include "poker_client.h"
#include <iostream>

int main() {
    PokerClient client;
    client.connectToServer("localhost", 8080);
    client.playGame();
    return 0;
}
