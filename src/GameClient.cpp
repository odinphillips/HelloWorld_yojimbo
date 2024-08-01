#include "GameClient.h"

#include "key_press.h"

#include <iostream>

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

static const uint8_t DEFAULT_PRIVATE_KEY[yojimbo::KeyBytes] = { 0 };

GameClient::GameClient(const yojimbo::Address& serverAddress) :
    m_serverAddress(serverAddress),
    m_client(yojimbo::GetDefaultAllocator(), yojimbo::Address("0.0.0.0"), m_connectionConfig, m_adapter, 0.0),
    m_running(false),
    m_time(0.0)
{
    uint64_t clientId;
    yojimbo_random_bytes((uint8_t*)&clientId, 8);
    m_client.InsecureConnect(DEFAULT_PRIVATE_KEY, clientId, m_serverAddress);
}

GameClient::~GameClient() {
    // NOTE: not sure if we need to check any of the following first?
    // yojimbo::Client::IsConnected()
    // yojimbo::Client::IsConnecting()
    // yojimbo::Client::IsLoopback()
    // yojimbo::Client::ConnectionFailed()
    // or yojimbo::Client::GetClientState()
    m_client.Disconnect();
}

void GameClient::Run() {
    float fixedDt = 1.0f / 60.0f;
    m_running = true;
    m_time = yojimbo_time();
    while (m_running) {
        double currentTime = yojimbo_time();
        if (m_time <= currentTime) {
            Update(fixedDt);
            m_time += fixedDt;
        } else {
            yojimbo_sleep(m_time - currentTime);
        }
    }
}

void GameClient::Update(float dt) {
    TestMessage* message = nullptr;
    // update client
    m_client.AdvanceTime(m_client.GetTime() + dt);
    m_client.ReceivePackets();

    // TODO: handle case when client auto disconnects due to server dying.

    if (m_client.IsConnected()) {
        ProcessMessages();

        // ... do connected stuff ...

        // send a message when space is pressed
        setRawMode(true);
        if (kbhit()) {
            char ch = getch();
            if (ch == 'q') {
                m_running = false;
            }
            else if (ch == ' ') {
                // NOTE: do we need to release this message in the future?
                message = (TestMessage*)m_client.CreateMessage((int)GameMessageType::TEST);
                message->m_data = 42;
                m_client.SendMessage((int)GameChannel::RELIABLE, message);
            }
        }
        setRawMode(false);
    }

    m_client.SendPackets();
}

void GameClient::ProcessMessages() {
    for (int i = 0; i < m_connectionConfig.numChannels; i++) {
        yojimbo::Message* message = m_client.ReceiveMessage(i);
        while (message != NULL) {
            ProcessMessage(message);
            m_client.ReleaseMessage(message);
            message = m_client.ReceiveMessage(i);
        }
    }
}

void GameClient::ProcessMessage(yojimbo::Message* message) {
    switch (message->GetType()) {
    case (int)GameMessageType::TEST:
        ProcessTestMessage((TestMessage*)message);
        break;
    default:
        break;
    }
}

void GameClient::ProcessTestMessage(TestMessage* message) {
    std::cout << "Test message received from server with data " << message->m_data << std::endl;
}
