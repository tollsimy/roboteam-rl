#pragma once

#include <memory>
#include <vector>
#include <cstdio>
#include <cstdarg>

#include "Blackboard.hpp"
#include "../../src/utilities/RobotDealer.h"

namespace bt {

class Node {
    public:
        // When this is updated, updated the tostring method below too!
        enum class Status {
                Invalid,
                Success,
                Failure,
                Running
        };

        std::string status_print(Status s) {
            switch (s) {
            case Status::Invalid:
                return " Status : Invalid";
            case Status::Success:
                return " Status : Success";
            case Status::Failure:
                return " Status : Failure";
            case Status::Running:
                return " Status : Running";
            }
        }

        virtual ~Node();

        Node();

        using Ptr = std::shared_ptr<Node>;

        virtual Status Update() = 0;

        Status NodeUpdate();

        void NodeInitialize();

        void NodeTerminate(Status s);

        virtual void Initialize();

        virtual void Terminate(Status s);

        virtual void AddChild(bt::Node::Ptr);

        virtual Status Tick();

        bool IsSuccess() const;

        bool IsFailure() const;

        bool IsRunning() const;

        bool IsTerminated() const;

        Status getStatus() const;

        void setStatus(Status s);

        using RobotDealer = rtt::ai::RobotDealer;

        bt::Blackboard::Ptr properties = std::make_shared<bt::Blackboard>();

        bt::Blackboard::Ptr globalBB;

        virtual std::string node_name();

        static std::string status_desc;

        void setProperties(bt::Blackboard::Ptr blackboard);

    protected:
        Status status = Status::Invalid;

        static void append_status(std::string fmt, ...);
};

using Nodes = std::vector<Node::Ptr>;

std::string statusToString(bt::Node::Status status);

} // bt
