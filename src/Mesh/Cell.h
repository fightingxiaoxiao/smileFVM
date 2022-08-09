#ifndef __Cell_H__
#define __Cell_H__

#include "basicType.h"
#include "Face.h"

namespace Smile
{
    class Cell
    {
    private:
        label id_;

        // 单元体积
        scalar V_;

        // 压力
        scalar p_;

        // 速度
        vector U_;

        vector center_;

        List<label> faces_;

    public:
        Cell();

        Cell(List<Face> facesRef,
             List<label> facesID);

        ~Cell();

        scalar &p();

        vector &U();

        vector center();

        vector grad();

        void addFace(List<Face> facesRef,
                     label faceI);
    };

} // namespace Smile

#endif