//
// Created by rolf on 30-1-19.
//

#ifndef ROBOTEAM_AI_GOAROUNDPOS_H
#define ROBOTEAM_AI_GOAROUNDPOS_H

#include "Skill.h"

namespace rtt {
namespace ai {

class GoAroundPos : public Skill {

        const double MAX_STOP_TIME = 2.0;           // Seconds
        const double MAX_DIST_DEVIATION = 0.2;      // Meters
        const double SPEED = 6.0;                   // Rad/second
        const double BALL_DIST = 0.11;              // Meters
        const double POS_MARGIN = 0.05;             // Meters
        const double ANGLE_MARGIN = 0.03*M_PI;      //Rad
        const double MIN_SPEED = 0.25;              // Meters/second

    private:

        enum Progression { FAIL, ROTATING, STOPPING, DONE };
        Progression currentProgress;
        bool ballIsTarget;
        Vector2 targetPos, deltaPos, commandPos;
        double startAngle, endAngle, angleDif;
        double distanceFromPoint;
        int rotateDir;
        double currentTick, maxTick;
        void sendRotateCommand();
        bool checkPosition();
        Progression checkProgression();
    public:
        explicit GoAroundPos(string name, bt::Blackboard::Ptr blackboard);
        void onInitialize() override;
        Status onUpdate() override;
        void onTerminate(Status s) override;
        std::string node_name() override { return "GoAroundPos"; };

};

}//ai
}//rtt
#endif //ROBOTEAM_AI_GOAROUNDPOS_H
