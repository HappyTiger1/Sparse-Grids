// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#ifndef OPERATIONTESTPOLY_HPP
#define OPERATIONTESTPOLY_HPP

#include <sgpp/base/operation/hash/OperationEval.hpp>
#include <sgpp/base/grid/GridStorage.hpp>
#include <sgpp/base/operation/hash/common/basis/PolyBasis.hpp>
#include <sgpp/datadriven/operation/hash/simple/OperationTest.hpp>
#include <sgpp/base/datatypes/DataVector.hpp>
#include <sgpp/base/datatypes/DataMatrix.hpp>

#include <sgpp/globaldef.hpp>

namespace SGPP {
namespace datadriven {

/**
 * This class implements OperationTest for a grids with poly basis ansatzfunctions with
 *
 */
class OperationTestPoly : public OperationTest {
 public:
  /**
   * Constructor
   *
   * @param storage the grid's base::GridStorage object
   * @param degree the polynom's max. degree
   */
  explicit OperationTestPoly(base::GridStorage* storage, size_t degree)
      : storage(storage), base(degree) {}

  /**
   * Destructor
   */
  virtual ~OperationTestPoly() {}

  virtual float_t test(base::DataVector& alpha, base::DataMatrix& data, base::DataVector& classes);
  virtual float_t testMSE(base::DataVector& alpha, base::DataMatrix& data,
                          base::DataVector& refValues);
  virtual float_t testWithCharacteristicNumber(SGPP::base::DataVector& alpha,
                                               SGPP::base::DataMatrix& data,
                                               SGPP::base::DataVector& classes,
                                               SGPP::base::DataVector& charaNumbers);
  virtual void calculateROCcurve(SGPP::base::DataVector& alpha, SGPP::base::DataMatrix& data,
                                 SGPP::base::DataVector& classes,
                                 SGPP::base::DataVector& thresholds,
                                 SGPP::base::DataMatrix& ROC_curve);

 protected:
  /// Pointer to base::GridStorage object
  base::GridStorage* storage;
  /// Poly Basis object
  base::SPolyBase base;
};
}  // namespace datadriven
}  // namespace SGPP
#endif /* OPERATIONTESTPOLY_HPP */
