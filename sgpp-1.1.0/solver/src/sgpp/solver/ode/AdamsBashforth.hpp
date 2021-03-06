// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#ifndef ADAMSBASHFORTH_HPP
#define ADAMSBASHFORTH_HPP

#include <sgpp/base/application/ScreenOutput.hpp>
#include <sgpp/solver/ODESolver.hpp>
#include <sgpp/globaldef.hpp>

#include <string>

namespace SGPP {
namespace solver {

/**
 * This class implements the explicit Adams-Bashforth method
 * for solving ordinary partial equations
 *
 */
class AdamsBashforth : public ODESolver {
 private:
  /// Pointer to SGPP::base::ScreenOutput object
  SGPP::base::ScreenOutput* myScreen;

 public:
  /**
   * Std-Constructer
   *
   * @param imax number of maximum executed iterations
   * @param timestepSize the size of one timestep
   * @param screen possible pointer to a SGPP::base::ScreenOutput object
   */
  AdamsBashforth(size_t imax, float_t timestepSize, SGPP::base::ScreenOutput* screen = NULL);

  /**
   * Std-Destructor
   */
  virtual ~AdamsBashforth();

  virtual void solve(SLESolver& LinearSystemSolver,
                     SGPP::solver::OperationParabolicPDESolverSystem& System,
                     bool bIdentifyLastStep = false, bool verbose = false);
};

}  // namespace solver
}  // namespace SGPP

#endif /* ADAMSBASHFORTH_HPP */
