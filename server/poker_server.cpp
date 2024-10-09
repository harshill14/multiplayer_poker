#include "poker_server.h"
#include "network.h"
#include <iostream>
#include <vector>
#include <unistd.h>

void PokerServer::startServer(int port) {
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sock, 3);

    std::cout << "Server started on port " << port << "\n";
}

void PokerServer::runGame() {
    while (true) {
        int client_sock = accept(server_sock, nullptr, nullptr);
        std::cout << "Player connected\n";
        players.push_back(client_sock);
        std::thread(&PokerServer::handlePlayer, this, client_sock).detach();
    }
}

void PokerServer::handlePlayer(int client_sock) {
    std::string data;
    while ((data = receiveData(client_sock)) != "") {
        std::cout << "Received action from player: " << data << "\n";
        sendData(client_sock, "acknowledged");
        if (data == "fold") {
            sendData(client_sock, "game_over");
            close(client_sock);
            break;
        }
    }
}
