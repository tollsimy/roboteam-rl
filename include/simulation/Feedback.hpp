#pragma once

#include <string>
#include <vector>
#include <map>

namespace rtt::robothub::simulation {
typedef struct SimulationError {
    std::string code;
    std::string message;
} SimulationError;

typedef struct RobotControlFeedback {
    bool isTeamYellow;
    std::map<int, bool> robotIdHasBall;
    std::vector<SimulationError> simulationErrors;
} RobotControlFeedback;

typedef struct ConfigurationFeedback {
    std::vector<SimulationError> simulationErrors;
} ConfigurationFeedback;
}  // namespace rtt::robothub::simulation