
//
// Created by baris on 05/11/18.
//

#include <utility>
#include "DemoTactic.h"
#include "../../utilities/World.h"

namespace bt {

DemoTactic::DemoTactic(std::string name, Blackboard::Ptr blackboard) {

    globalBB = std::move(blackboard);
    setName(std::move(name));
}

void DemoTactic::setName(std::string newName) {
    name = std::move(newName);
}

void DemoTactic::Initialize() {

    while (!claimedRobots) {
        std::set<int> ids;
        ids = RobotDealer::getAvailableRobots();
        if (!ids.empty()) {
            auto id = *ids.begin();  // only one robot...
            std::pair<int, std::string> idName = {id, "testRole"};
            claimedRobots = RobotDealer::claimRobotForTactic(idName, "testTactic");
            robotIDs.insert(id);
        }
    }
}

Node::Status DemoTactic::Update() {
    Node::append_status("[DemoTactic untill success: executing child of type %s]", child->node_name().c_str());
    auto status = child->Tick();

    if (status == Status::Success) {
        return Status::Success;
    }
    else if (status == Status::Invalid) {
        return Status::Failure;
    }
    else /* if (status == Status::Failure || status == Status::Running) */ {
        // If the status was anything but success/invalid, keep running
        return Status::Running;
    }
}

} // bt










