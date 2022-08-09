#ifndef __Face_H__
#define __Face_H__

#include "Node.h"

namespace Smile
{
    class Face
    {
    private:
        label id_;

        List<label> nodes;

        vector S_;

        vector center_;

    public:
        label c0;

        label c1;

        scalar p;

        vector U;

        Face();

        Face(List<Node> nodesRef,
             List<label> nodesID,
             label _c0,
             label _c1);

        ~Face();

        vector S();

        vector center();
    };

} // namespace Smile

#endif