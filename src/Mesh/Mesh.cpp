#include "Mesh.h"
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <Python.h>

namespace Smile
{
    Mesh::Mesh()
    {
    }

    Mesh::Mesh(label rowNum, label colNum)
    {
        Py_Initialize();
        PyRun_SimpleString("import meshio\n"
                           "print('lalala')\n");
        Py_Finalize();
        this->p_ = scalarField::Zero(rowNum * colNum);
        this->U_ = vectorField::Zero(rowNum * colNum, 3);
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
        Eigen::IOFormat HeavyFmt(Eigen::FullPrecision, 0, ", ", ",\n", "[", "]", "[", "]");
        fmt::print("{}\n", this->U_.format(HeavyFmt));
    }
} // namespace Smile
