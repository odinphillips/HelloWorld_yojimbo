#pragma once

#include <yojimbo.h>

class GameServer;

// a simple test message
enum class GameMessageType {
    TEST,
    COUNT
};

class TestMessage : public yojimbo::Message {
public:
    int m_data;

    TestMessage() :
        m_data(0) {}

    template <typename Stream>
    bool Serialize(Stream& stream) {
        serialize_int(stream, m_data, 0, 512);
        return true;
    }

    YOJIMBO_VIRTUAL_SERIALIZE_FUNCTIONS();
};

// the message factory
YOJIMBO_MESSAGE_FACTORY_START(GameMessageFactory, (int)GameMessageType::COUNT);
YOJIMBO_DECLARE_MESSAGE_TYPE((int)GameMessageType::TEST, TestMessage);
YOJIMBO_MESSAGE_FACTORY_FINISH();

class GameAdapter : public yojimbo::Adapter {
public:
    explicit GameAdapter(GameServer* server = NULL) :
        m_server(server) {}

    yojimbo::MessageFactory* CreateMessageFactory(yojimbo::Allocator& allocator) override {
        return YOJIMBO_NEW(allocator, GameMessageFactory, allocator);
    }

    void OnServerClientConnected(int clientIndex) override;
    void OnServerClientDisconnected(int clientIndex) override;

private:
    GameServer* m_server;
};
