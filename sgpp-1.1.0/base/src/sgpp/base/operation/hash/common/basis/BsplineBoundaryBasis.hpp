// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#ifndef BSPLINE_BOUNDARY_BASE_HPP
#define BSPLINE_BOUNDARY_BASE_HPP

#include <sgpp/base/operation/hash/common/basis/Basis.hpp>
#include <sgpp/base/operation/hash/common/basis/BsplineBasis.hpp>

#include <sgpp/globaldef.hpp>

#include <cmath>

namespace SGPP {
namespace base {

/**
 * B-spline basis on Boundary grids.
 */
template <class LT, class IT>
class BsplineBoundaryBasis: public Basis<LT, IT> {
 public:
  /**
   * Default constructor.
   */
  BsplineBoundaryBasis() : bsplineBasis(BsplineBasis<LT, IT>()) {
  }

  /**
   * Constructor.
   *
   * @param degree    B-spline degree, must be odd
   *                  (if it's even, degree - 1 is used)
   */
  explicit BsplineBoundaryBasis(size_t degree) :
    bsplineBasis(BsplineBasis<LT, IT>(degree)) {
  }

  /**
   * Destructor.
   */
  ~BsplineBoundaryBasis() override {
  }

  /**
   * @param l     level of basis function
   * @param i     index of basis function
   * @param x     evaluation point
   * @return      value of boundary B-spline basis function
   */
  inline float_t eval(LT l, IT i, float_t x) override {
    const float_t hInv = static_cast<float_t>(static_cast<IT>(1) << l);

    return bsplineBasis.uniformBSpline(
             x * hInv - static_cast<float_t>(i) +
             static_cast<float_t>(bsplineBasis.getDegree() + 1) / 2.0,
             bsplineBasis.getDegree());
  }

  /**
   * @param l     level of basis function
   * @param i     index of basis function
   * @param x     evaluation point
   * @return      value of derivative of boundary B-spline basis function
   */
  inline float_t evalDx(LT l, IT i, float_t x) {
    const float_t hInv = static_cast<float_t>(static_cast<IT>(1) << l);

    return hInv * bsplineBasis.uniformBSplineDx(
             x * hInv - static_cast<float_t>(i) +
             static_cast<float_t>(bsplineBasis.getDegree() + 1) / 2.0,
             bsplineBasis.getDegree());
  }

  /**
   * @param l     level of basis function
   * @param i     index of basis function
   * @param x     evaluation point
   * @return      value of 2nd derivative of boundary B-spline basis function
   */
  inline float_t evalDxDx(LT l, IT i, float_t x) {
    const float_t hInv = static_cast<float_t>(static_cast<IT>(1) << l);

    return hInv * hInv * bsplineBasis.uniformBSplineDxDx(
             x * hInv - static_cast<float_t>(i) +
             static_cast<float_t>(bsplineBasis.getDegree() + 1) / 2.0,
             bsplineBasis.getDegree());
  }

  /**
   * @return      B-spline degree
   */
  inline size_t getDegree() const {
    return bsplineBasis.getDegree();
  }

 protected:
  /// B-spline basis for B-spline evaluation
  BsplineBasis<LT, IT> bsplineBasis;
};

// default type-def (unsigned int for level and index)
typedef BsplineBoundaryBasis<unsigned int, unsigned int> SBsplineBoundaryBase;

}  // namespace base
}  // namespace SGPP

#endif /* BSPLINE_BOUNDARY_BASE_HPP */
