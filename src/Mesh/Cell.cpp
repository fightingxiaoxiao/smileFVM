#include "Cell.h"
#include <fmt/core.h>
#include <fmt/ostream.h>

namespace Smile
{
    Cell::Cell()
        : p_(0.),
          U_(vector(0., 0., 0.)),
          center_(vector(0., 0., 0.))
    {
    }

    Cell::Cell(List<Face> facesRef,
               List<label> facesID)
        : p_(0.),
          U_(vector(0., 0., 0.)),
          center_(vector(0., 0., 0.))
    {

        // 计算体心
        for (label faceI : facesID)
        {
            this->center_ += facesRef[faceI].center();
        }
        this->center_ /= facesID.size();
    }

    Cell::~Cell()
    {
    }

    scalar &Cell::p()
    {
        return this->p_;
    }

    vector &Cell::U()
    {
        return this->U_;
    }

    vector Cell::center()
    {
        return this->center_;
    }

    vector Cell::grad()
    {
    }

    void Cell::addFace(List<Face> facesRef,
                       label faceI)
    //在单元中添加新的面，并更新体心
    {
        
        this->center_ = this->center_ * this->faces_.size() + facesRef[faceI].center();
        this->center_ /= this->faces_.size() + 1;
        this->faces_.push_back(faceI);
        //fmt::print("face id = {}\n", faceI);
        //fmt::print("center = {}\n", this->center_);
        //fmt::print("face num = {}\n", this->faces_.size());
    }

} // namespace Smile
