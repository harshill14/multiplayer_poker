#include "poker_client.h"
#include "network.h"
#include <iostream>

void PokerClient::connectToServer(const std::string& ip, int port) {
    sockfd = connectToServer(ip.c_str(), port);
}

void PokerClient::playGame() {
    while (true) {
        std::string action;
        std::cout << "Enter action (fold/check/raise): ";
        std::cin >> action;
        sendData(sockfd, action);

        std::string response = receiveData(sockfd);
        std::cout << "Server response: " << response << "\n";
        if (response == "game_over") {
            std::cout << "Game Over\n";
            break;
        }
    }
}
