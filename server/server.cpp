#include "poker_server.h"
#include "network.h"

int main() {
    PokerServer server;
    server.startServer(8080);
    server.runGame();
    return 0;
}
