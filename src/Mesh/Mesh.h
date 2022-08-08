#ifndef __Mesh_H__
#define __Mesh_H__

#include "basicType.h"

namespace Smile
{
    class Mesh
    {
    private:
        
        scalarField p_;

        vectorField U_;
        
    public:

        Mesh();

        Mesh(label rowNum, label colNum);

        ~Mesh();

        void test();

        void U();
    };
} // namespace Smile

#endif