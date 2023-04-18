//
// Created by emiel on 21-02-22.
//

#ifndef RTT_WEBSOCKETMANAGER_H
#define RTT_WEBSOCKETMANAGER_H

#include <world/World.hpp>

#include "ixwebsocket/IXWebSocketServer.h"
#include "stp/Play.hpp"

namespace rtt::ai::io {

// Singleton design according to this post on Stackoverflow
// https://stackoverflow.com/questions/1008019/c-singleton-design-pattern

class WebSocketManager {
   public:
    static WebSocketManager& instance();
    void broadcastWorld();
    void broadcastPlay(stp::Play* play);

   private:
    WebSocketManager();
    static std::string WebSocketMessageTypeToString(ix::WebSocketMessageType type);
    ix::WebSocketServer webSocketServer;

   public:
    WebSocketManager(WebSocketManager const&) = delete;
    void operator=(WebSocketManager const&) = delete;
};

}







#endif  // RTT_WEBSOCKETMANAGER_H