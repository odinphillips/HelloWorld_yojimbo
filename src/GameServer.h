#pragma once

#include "GameAdapter.h"
#include "GameConnectionConfig.h"

#include <yojimbo.h>

class GameServer {
public:
    GameServer(const yojimbo::Address& address);
    ~GameServer();

    void ClientConnected(int clientIndex);
    void ClientDisconnected(int clientIndex);
    
    void Run();
    void Update(float dt);
    
    void ProcessMessages();
    void ProcessMessage(int clientIndex, yojimbo::Message* message);
    void ProcessTestMessage(int clientIndex, TestMessage* message);

private:
    GameConnectionConfig m_connectionConfig;
    GameAdapter m_adapter;
    yojimbo::Server m_server;
    bool m_running;
    double m_time;
};


