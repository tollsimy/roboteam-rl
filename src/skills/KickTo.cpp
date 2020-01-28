#include "skills/KickTo.h"

#include <control/BasicPosControl.h>
#include <control/ControlUtils.h>
#include <control/PositionUtils.h>
#include <control/numtrees/NumTreePosControl.h>
#include <world/Field.h>

namespace rtt::ai {

KickTo::KickTo(string name, bt::Blackboard::Ptr blackboard) : Skill(std::move(name), std::move(blackboard)) {}
void KickTo::onInitialize() {
    std::string type = properties->getString("type");
    if (type == "shootout") {
        shootPos = Vector2(field->get_field().get(FIELD_LENGTH) * 0.2, 0);  // 2.4 m for A field, 1.8 for B
    } else {
        shootPos = Vector2(0, 0);
    }
}
/// Get an update on the skill
bt::Node::Status KickTo::onUpdate() {
    if (field->pointIsInDefenceArea(ball->getPos(), false)) {
        command.set_w(0);
        publishRobotCommand();
        return Status::Running;
    }

    Vector2 aimPoint = shootPos;
    // TODO: tune kick velocity
    auto shotData = robot->getShotController()->getRobotCommand(*robot, aimPoint, false, control::BallSpeed::BALL_PLACEMENT, true, control::ShotPrecision::HIGH);
    command = shotData.makeROSCommand();
    publishRobotCommand();
    return Status::Running;
}

}  // namespace rtt::ai