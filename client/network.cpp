#include "network.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

int connectToServer(const char *ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Error creating socket\n";
        return -1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection to server failed\n";
        return -1;
    }

    std::cout << "Connected to server\n";
    return sock;
}

void sendData(int sock, const std::string &data) {
    send(sock, data.c_str(), data.size(), 0);
}

std::string receiveData(int sock) {
    char buffer[1024] = {0};
    int bytesRead = recv(sock, buffer, sizeof(buffer), 0);
    return std::string(buffer, bytesRead);
}
