#ifndef NETWORK_H
#define NETWORK_H

#include <string>

int connectToServer(const char *ip, int port);
void sendData(int sock, const std::string &data);
std::string receiveData(int sock);

#endif
