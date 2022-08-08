#include <fmt/core.h>
#include <omp.h>
#include <QString>

#include "Mesh.h"

int main(int argc, char **argv)
{
    float a = 1.23;
    QString b = "hello";

    Smile::Mesh mesh;
    mesh.test();
    //fmt::print("Hello, world!\n");
    //fmt::print("a = {0}, b = {1}\n",a, b.toUtf8());

    return EXIT_SUCCESS;
}
