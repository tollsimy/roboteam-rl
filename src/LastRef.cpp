#include "roboteam_msgs/RefereeCommand.h"
#include "roboteam_msgs/RefereeData.h"
#include "roboteam_msgs/RefereeStage.h"

#include "roboteam_utils/LastRef.h"
#include "ros/ros.h"

namespace rtt {

roboteam_msgs::RefereeData LastRef::lastRef;
int LastRef::previousRefCommand = -1;

roboteam_msgs::RefereeData LastRef::get() {
    return LastRef::lastRef;
}

RefState LastRef::getState() {
    return static_cast<RefState>(LastRef::lastRef.command.command);
}

void LastRef::set(roboteam_msgs::RefereeData refCommand) {
    if (refCommand.command.command != lastRef.command.command) {
        previousRefCommand = lastRef.command.command;
    }

    LastRef::lastRef = refCommand;
}

const std::vector<RefStateTransitionFunction> LastRef::transitions = {
    //TODO, for example:
    [](RefState current, const roboteam_msgs::World& world) {
        return current == RefState::INDIRECT_FREE_THEM && (int) world.us[0].pos.x % 2
                ? boost::optional<RefState>(RefState::NORMAL_PLAY)
                : boost::optional<RefState>();
    }
};

int LastRef::getPreviousRefCommand() {
    return previousRefCommand;
}

}
