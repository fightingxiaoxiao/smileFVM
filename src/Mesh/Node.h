#ifndef __Node_H__
#define __Node_H__

#include "basicType.h"

namespace Smile
{
    class Node
    {
    private:
        vector coordinate_;

    public:
        Node(vector _coordinate);
        ~Node();

        vector coordinate();
    };

} // namespace Smile

#endif