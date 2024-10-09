# Multiplayer Poker Game in C++

An online multiplayer poker game developed in C++, using a client-server architecture with socket-based networking. This game allows multiple players to connect to a central server, enabling real-time gameplay and interaction.

## Features

- **Game Server:** Manages game state, player connections, and turn-based gameplay.
- **Client:** Connects to the server, handles player inputs, and updates based on server responses.
- **Networking Layer:** Built with sockets to handle communication between the server and clients.

## Directory Structure

```plaintext
multiplayer_poker/
├── client/
│   ├── client.cpp
│   ├── network.cpp
│   ├── poker_client.h
│   └── poker_client.cpp
├── server/
│   ├── server.cpp
│   ├── poker_server.h
│   └── poker_server.cpp
└── common/
    ├── deck.h
    ├── deck.cpp
    ├── card.h
    ├── card.cpp
    └── network.h
