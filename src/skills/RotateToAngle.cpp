//
// Created by rolf on 21/11/18.
//

#include <skills/RotateToAngle.h>

namespace rtt::ai {
RotateToAngle::RotateToAngle(std::string name, bt::Blackboard::Ptr blackboard) : Skill(std::move(name), std::move(blackboard)) {}

void RotateToAngle::onInitialize() {
    if (properties->hasDouble("Angle")) {
        targetAngle = properties->getDouble("Angle");
    }

    if (properties->getBool("rotateToBall")) {
        targetAngle = ((Vector2)ball->get()->getPos() - robot->get()->getPos()).angle();
    }
}

RotateToAngle::Status RotateToAngle::onUpdate() {
    command.set_w(static_cast<float>(targetAngle));
    deltaAngle = fabs(control::ControlUtils::constrainAngle(targetAngle - robot->get()->getAngle()));
    currentProgress = checkProgression();

    switch (currentProgress) {
        case ROTATING: {
            publishRobotCommand();
            return Status::Running;
        }
        case DONE:
            return Status::Success;
        case FAIL:
            return Status::Failure;
    }

    return Status::Failure;
}

void RotateToAngle::onTerminate(Status s) {
    command.set_w(targetAngle);
    currentProgress = ROTATING;
    publishRobotCommand();
}

RotateToAngle::Progression RotateToAngle::checkProgression() {
    double errorMargin = M_PI * 0.03;
    if (deltaAngle > errorMargin)
        return ROTATING;
    else
        return DONE;
}

}  // namespace rtt::ai