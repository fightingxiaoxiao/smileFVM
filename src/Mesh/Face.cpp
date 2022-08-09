#include "Face.h"
#include <fmt/core.h>
#include <fmt/ostream.h>

namespace Smile
{
    Face::Face()
        : center_(vector(0., 0., 0.))
    {
    }

    Face::Face(List<Node> nodesRef,
               List<label> nodesID,
               label _c0,
               label _c1)
        : center_(vector(0., 0., 0.))
    {
        for (label nodeI : nodesID)
        {
            this->nodes.push_back(nodeI);
            this->center_ += nodesRef[nodeI].coordinate();
        }

        this->center_ /= nodesID.size();

        //fmt::print("face center = {}\n", this->center_);

        if (_c0 == -1)
        {
            this->c0 = _c1;
            this->c1 = _c0;
        }
        else
        {
            this->c0 = _c0;
            this->c1 = _c1;
        }
    }

    Face::~Face()
    {
    }

    vector Face::center()
    {
        return this->center_;
    }

    vector Face::S()
    {
        return this->S_;
    }
} // namespace Smile
