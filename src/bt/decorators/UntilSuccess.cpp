/*
 * The UntilSuccess decorator repeats until the child returns success and then returns success.
 */

#include "decorators/UntilSuccess.h"

namespace bt {

Node::Status UntilSuccess::update() {
    auto status = child->tick(world, field);

    if (status == Status::Success) {
        return Status::Success;
    } else if (status == Status::Waiting) {
        return Status::Failure;
    } else {
        return Status::Running;
    }
}

}  // namespace bt
