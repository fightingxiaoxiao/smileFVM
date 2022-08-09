#include "Node.h"

namespace Smile
{
    Node::Node(vector _coordinate)
    {
        this->coordinate_ = _coordinate;
    }

    Node::~Node()
    {
    }

    vector Node::coordinate()
    {
        return this->coordinate_;
    }
} // namespace Smile
