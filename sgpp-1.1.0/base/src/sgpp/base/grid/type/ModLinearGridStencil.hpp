// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#ifndef MODLINEARGRIDSTENCIL_HPP
#define MODLINEARGRIDSTENCIL_HPP

#include <sgpp/base/grid/type/GridStencil.hpp>
#include <sgpp/base/grid/common/BoundingBox.hpp>

#include <sgpp/globaldef.hpp>


namespace SGPP {
namespace base {

/**
 * grid with linear base functions
 */
class ModLinearGridStencil : public GridStencil {
 protected:
  explicit ModLinearGridStencil(std::istream& istr);

 public:
  /**
   * Constructor Linear Grid without boundaries
   *
   * @param dim the dimension of the grid
   */
  explicit ModLinearGridStencil(size_t dim);

  /**
   * Constructor Linear Grid
   *
   * @param BB the BoundingBox of the grid
   */
  explicit ModLinearGridStencil(BoundingBox& BB);

  /**
   * Destructor
   */
  ~ModLinearGridStencil() override;

  SGPP::base::GridType getType() override;

  const SBasis& getBasis() override;

  GridGenerator* createGridGenerator() override;

  static Grid* unserialize(std::istream& istr);
};

}  // namespace base
}  // namespace SGPP

#endif /* MODLINEARGRIDSTENCIL_HPP */
