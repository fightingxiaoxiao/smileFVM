#ifndef __basicType_H__
#define __basicType_H__

#include <eigen3/Eigen/Core>

namespace Smile
{
    using label = long;

    using scalar = double;

    using vector = Eigen::Matrix<scalar, 1, 3>;

    using scalarField = Eigen::Matrix<scalar, Eigen::Dynamic, 1>;

    using vectorField = Eigen::Array<scalar, Eigen::Dynamic, 3>;
}

#endif