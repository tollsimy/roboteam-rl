#include <memory>
#include <iostream>
#include "Blackboard.hpp"
#include "Node.hpp"

namespace bt {

void Node::initialize() {
}

void Node::terminate(Status s) {
    init = false;
    // If we're terminating while we're still running,
    // consider the node failed. If it already failed
    // or succeeded, leave it like that.
    if (s == Status::Running) {
        status = Status::Failure;
    }
}

Node::Status Node::tick() {
    amountOfTicks++;
    lastTickTime = ros::Time::now();

    if (! init) {
        NodeInitialize();
    }

    setStatus(NodeUpdate());

    if (status != Status::Running) {
        NodeTerminate(status);
    }

    return status;
}

bool Node::IsSuccess() const { return status == Status::Success; }

bool Node::IsFailure() const { return status == Status::Failure; }

bool Node::IsRunning() const { return status == Status::Running; }

bool Node::IsTerminated() const { return IsSuccess() || IsFailure(); }

Node::Status Node::getStatus() const { return status; }

void Node::setStatus(Status s) { status = s; }

std::string Node::node_name() {
    return "Node name undefined node.cpp";
}

void Node::addChild(bt::Node::Ptr) { }

// testing purpose
std::vector<Node::Ptr> Node::getChildren() {
//    std::cerr << "Get children in Node.cpp, should never be called" << std::endl;
    return std::vector<Node::Ptr>{};
}

void Node::setProperties(bt::Blackboard::Ptr blackboard) {
    properties = blackboard;

}
Node::Node() {
    globalBB = std::make_shared<Blackboard>();
}

Node::Status Node::NodeUpdate() {
    status = update();
    return status;
}

void Node::NodeInitialize() {
    initialize();
    init = true;


}

void Node::NodeTerminate(Status s) {
    terminate(s);
    init = false;

}

unsigned long long Node::getAmountOfTicks() const {
    return amountOfTicks;
}

ros::Time Node::getLastTickTime() {
    return lastTickTime;
}
void Node::giveProperty(std::string a, std::string b) {
    std::cerr << "giveProperty in Node.cpp, should never be called" << std::endl;

}

std::string statusToString(bt::Node::Status status) {
    if (status == bt::Node::Status::Success) {
        return "Success";
    }
    else if (status == bt::Node::Status::Failure) {
        return "Failure";
    }
    else if (status == bt::Node::Status::Waiting) {
        return "Waiting";
    }
    else if (status == bt::Node::Status::Running) {
        return "Running";
    }
    else {
        std::cout << "Enum failure in Node::Status overload of to_string\n";
        return "ERROR ERROR!!!";
    }
}

}
