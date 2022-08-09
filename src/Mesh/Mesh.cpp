#include "Mesh.h"
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <Python.h>

namespace Smile
{
    Mesh::Mesh()
    {
    }

    // test
    Mesh::Mesh(label rowNum, label colNum)
    {

        // Py_Initialize();
        // PyRun_SimpleString("import meshio\n"
        //                    "print('lalala')\n");
        // Py_Finalize();
        
        for (label i = 0; i < (rowNum + 1) * (colNum + 1); i++)
        {
            scalar y = (i / (rowNum + 1)) * 0.1;
            scalar x = (i % (rowNum + 1)) * 0.1;

            this->nodes_.push_back(Node(vector(x, y, 0.)));
        }

        for (label i = 0; i < (rowNum + 1) * colNum; i++)
        {
            label xI = i % colNum;
            label yI = i / colNum;

            if (xI % (colNum + 1) != colNum)
            {

                this->faces_.push_back(
                    Face(
                        this->nodes_,
                        List<label>({yI * (colNum + 1) + xI, yI * (colNum + 1) + xI + 1}),
                        (yI == rowNum) ? (-1) : (yI * colNum + xI),
                        (yI == 0) ? (-1) : ((yI - 1) * (colNum) + xI)));
            }
        }

        for (label i = 0; i < rowNum * (colNum + 1); i++)
        {
            label xI = i % (colNum + 1);
            label yI = i / (colNum + 1);

            {
                this->faces_.push_back(
                    Face(
                        this->nodes_,
                        List<label>({yI * (colNum + 1) + xI, (yI + 1) * (colNum + 1) + xI}),
                        (xI == colNum) ? (-1) : (yI * colNum + xI),
                        (xI == 0) ? (-1) : (yI * colNum + xI - 1)));
            }
        }

        this->cells_ = List<Cell>(rowNum * colNum);

        label faceI = 0;
        for (Face &f : this->faces_)
        {
            //fmt::print("\nf.c0 = {}\n", f.c0);
            //fmt::print("f.c1 = {}\n", f.c1);

            this->cells_[f.c0].addFace(this->faces_, faceI);

            if (f.c1 > -1)
            {
                this->cells_[f.c1].addFace(this->faces_, faceI);
            }

            faceI++;
        }
    }

    Mesh::~Mesh()
    {
    }

    void Mesh::test()
    {
        fmt::print("Hello, world!\n");
    }

    void Mesh::U()
    {
    }
} // namespace Smile
