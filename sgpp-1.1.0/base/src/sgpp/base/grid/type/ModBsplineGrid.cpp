// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#include <sgpp/base/grid/Grid.hpp>
#include <sgpp/base/grid/type/ModBsplineGrid.hpp>
#include <sgpp/base/grid/GridStorage.hpp>
#include <sgpp/base/grid/generation/StandardGridGenerator.hpp>

#include <sgpp/base/exception/factory_exception.hpp>


#include <sgpp/globaldef.hpp>


namespace SGPP {
namespace base {

ModBsplineGrid::ModBsplineGrid(std::istream& istr) :
  Grid(istr),
  degree(1 << 16),
  basis_(NULL) {
  istr >> degree;
}


ModBsplineGrid::ModBsplineGrid(size_t dim, size_t degree) :
  Grid(dim),
  degree(degree),
  basis_(NULL) {
}

ModBsplineGrid::~ModBsplineGrid() {
  if (basis_ != NULL) {
    delete basis_;
  }
}

SGPP::base::GridType ModBsplineGrid::getType() {
  return SGPP::base::GridType::ModBspline;
}

const SBasis& ModBsplineGrid::getBasis() {
  if (basis_ == NULL) {
    basis_ = new SBsplineModifiedBase(degree);
  }

  return *basis_;
}

size_t ModBsplineGrid::getDegree() {
  return this->degree;
}

Grid* ModBsplineGrid::unserialize(std::istream& istr) {
  return new ModBsplineGrid(istr);
}

void ModBsplineGrid::serialize(std::ostream& ostr) {
  this->Grid::serialize(ostr);
  ostr << degree << std::endl;
}

/**
 * Creates new GridGenerator
 * This must be changed if we add other storage types
 */
GridGenerator* ModBsplineGrid::createGridGenerator() {
  return new StandardGridGenerator(this->storage);
}

}  // namespace base
}  // namespace SGPP
