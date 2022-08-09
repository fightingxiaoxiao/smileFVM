#ifndef __Mesh_H__
#define __Mesh_H__

#include "basicType.h"

#include "Cell.h"
#include "Face.h"
#include "Node.h"

namespace Smile
{
    class Mesh
    {
    private:
        scalarField p_;

        vectorField U_;

        scalarField pFace_;

        vectorField UFace_;

        vectorField cellCenter_;

        vectorField faceCenter_;

        vectorField faceArea_;

    public:
        List<Cell> cells_;

        List<Face> faces_;

        List<Node> nodes_;

        Mesh();

        Mesh(label rowNum, label colNum);

        ~Mesh();

        void test();

        void U();
    };
} // namespace Smile

#endif