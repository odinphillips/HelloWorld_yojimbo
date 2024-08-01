#include "GameServer.h"

int main(int argc, char* argv[]) {
    
    InitializeYojimbo();

    // Scope { } required for proper memory deallocation at shutdown
    {
        yojimbo::Address address("127.0.0.1", 40000);
        GameServer gameServer(address);
        gameServer.Run();
    }

    ShutdownYojimbo();

    return 0;
}
