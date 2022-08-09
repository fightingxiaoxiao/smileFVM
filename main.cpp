#include <fmt/core.h>
#include <fmt/ostream.h>
#include <omp.h>
#include <QString>

#include "Mesh.h"

int main(int argc, char **argv)
{
    QString b = "hello";

    Smile::Mesh mesh(10, 10);

    // fmt::print("Face numbers: {}\n", mesh.faces_.size());

    Eigen::IOFormat CleanFmt(4, 0, ", ", "\n", "[", "]");
    /*
        for (Smile::Node &n : mesh.nodes_)
        {
            fmt::print("n = {}\n", n.coordinate());
        }

        for (auto &f : mesh.faces_)
        {
            fmt::print("face center = {}\n", f.center());
        }
    */
    Smile::label count = 0;
    for (auto &c : mesh.cells_)
    {
        fmt::print("center = {}\n", c.center());
        fmt::print("cell count = {}\n", ++count);
    }

    /*
        for (Smile::Node &n : mesh.nodes_)
        {

            fmt::print("n = {}\n", n.coordinate().format(CleanFmt));
        }
    */
    // fmt::print("cp = {}\n", &cp);
    // mesh.U();
    // fmt::print("Hello, world!\n");
    // fmt::print("a = {0}, b = {1}\n",a, b.toUtf8());

    return EXIT_SUCCESS;
}
