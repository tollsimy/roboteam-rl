//
// Created by Martin Miksik on 24/05/2023.
//

#ifndef RTT_INTERFACESUBSCRIBER_H
#define RTT_INTERFACESUBSCRIBER_H
#include "proto/NewInterface.pb.h"

namespace rtt::ai::io {
class InterfaceGateway;
class InterfaceSubscriber {
    friend InterfaceGateway;  /// Only the InterfaceGateway can create an InterfacePublisher

   public:
    /**
     * @brief Callback function invoked when a message is received from a client.
     * Processes the received message and performs corresponding actions.
     *
     * @param message The received message from the client.
     */
    void onMessage(const proto::MsgFromInterface&& message);

   private:
    InterfaceSubscriber() = default;
};
}  // namespace rtt::ai::io
#endif  // RTT_INTERFACESUBSCRIBER_H
