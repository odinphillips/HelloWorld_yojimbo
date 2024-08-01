#pragma once

#include "GameAdapter.h"
#include "GameConnectionConfig.h"

#include <yojimbo.h>

class GameClient {
public:
    GameClient(const yojimbo::Address& serverAddress);
    ~GameClient();

    void Run();
    void Update(float dt);
    void ProcessMessages();
    void ProcessMessage(yojimbo::Message* message);
    void ProcessTestMessage(TestMessage* message);

private:
    yojimbo::Address m_serverAddress;
    GameConnectionConfig m_connectionConfig;
    GameAdapter m_adapter;
    yojimbo::Client m_client;
    bool m_running;
    double m_time;
};
