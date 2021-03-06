// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "BasisEval.hpp"

SGPP::float_t basisEvalDx(SGPP::base::SBasis& basis, SGPP::base::level_t l,
                          SGPP::base::index_t i, SGPP::float_t x) {
  SGPP::base::SBsplineBase* bsplineBasis =
      dynamic_cast<SGPP::base::SBsplineBase*>(&basis);
  SGPP::base::SBsplineBoundaryBase* bsplineBoundaryBasis =
      dynamic_cast<SGPP::base::SBsplineBoundaryBase*>(&basis);
  SGPP::base::SBsplineClenshawCurtisBase* bsplineClenshawCurtisBasis =
      dynamic_cast<SGPP::base::SBsplineClenshawCurtisBase*>(&basis);
  SGPP::base::SBsplineModifiedBase* bsplineModifiedBasis =
      dynamic_cast<SGPP::base::SBsplineModifiedBase*>(&basis);
  SGPP::base::SBsplineModifiedClenshawCurtisBase* bsplineModifiedClenshawCurtisBasis =
      dynamic_cast<SGPP::base::SBsplineModifiedClenshawCurtisBase*>(&basis);
  SGPP::base::SFundamentalSplineBase* fundamentalSplineBasis =
      dynamic_cast<SGPP::base::SFundamentalSplineBase*>(&basis);
  SGPP::base::SFundamentalSplineModifiedBase* fundamentalSplineModifiedBasis =
      dynamic_cast<SGPP::base::SFundamentalSplineModifiedBase*>(&basis);
  SGPP::base::SWaveletBase* waveletBasis =
      dynamic_cast<SGPP::base::SWaveletBase*>(&basis);
  SGPP::base::SWaveletBoundaryBase* waveletBoundaryBasis =
      dynamic_cast<SGPP::base::SWaveletBoundaryBase*>(&basis);
  SGPP::base::SWaveletModifiedBase* waveletModifiedBasis =
      dynamic_cast<SGPP::base::SWaveletModifiedBase*>(&basis);

  if (bsplineBasis != nullptr) {
    return bsplineBasis->evalDx(l, i, x);
  } else if (bsplineBoundaryBasis != nullptr) {
    return bsplineBoundaryBasis->evalDx(l, i, x);
  } else if (bsplineClenshawCurtisBasis != nullptr) {
    return bsplineClenshawCurtisBasis->evalDx(l, i, x);
  } else if (bsplineModifiedBasis != nullptr) {
    return bsplineModifiedBasis->evalDx(l, i, x);
  } else if (bsplineModifiedClenshawCurtisBasis != nullptr) {
    return bsplineModifiedClenshawCurtisBasis->evalDx(l, i, x);
  } else if (fundamentalSplineBasis != nullptr) {
    return fundamentalSplineBasis->evalDx(l, i, x);
  } else if (fundamentalSplineModifiedBasis != nullptr) {
    return fundamentalSplineModifiedBasis->evalDx(l, i, x);
  } else if (waveletBasis != nullptr) {
    return waveletBasis->evalDx(l, i, x);
  } else if (waveletBoundaryBasis != nullptr) {
    return waveletBoundaryBasis->evalDx(l, i, x);
  } else if (waveletModifiedBasis != nullptr) {
    return waveletModifiedBasis->evalDx(l, i, x);
  } else {
    BOOST_THROW_EXCEPTION(std::runtime_error("Invalid basis."));
    return NAN;
  }
}

SGPP::float_t basisEvalDxDx(SGPP::base::SBasis& basis, SGPP::base::level_t l,
                            SGPP::base::index_t i, SGPP::float_t x) {
  SGPP::base::SBsplineBase* bsplineBasis =
      dynamic_cast<SGPP::base::SBsplineBase*>(&basis);
  SGPP::base::SBsplineBoundaryBase* bsplineBoundaryBasis =
      dynamic_cast<SGPP::base::SBsplineBoundaryBase*>(&basis);
  SGPP::base::SBsplineClenshawCurtisBase* bsplineClenshawCurtisBasis =
      dynamic_cast<SGPP::base::SBsplineClenshawCurtisBase*>(&basis);
  SGPP::base::SBsplineModifiedBase* bsplineModifiedBasis =
      dynamic_cast<SGPP::base::SBsplineModifiedBase*>(&basis);
  SGPP::base::SBsplineModifiedClenshawCurtisBase* bsplineModifiedClenshawCurtisBasis =
      dynamic_cast<SGPP::base::SBsplineModifiedClenshawCurtisBase*>(&basis);
  SGPP::base::SFundamentalSplineBase* fundamentalSplineBasis =
      dynamic_cast<SGPP::base::SFundamentalSplineBase*>(&basis);
  SGPP::base::SFundamentalSplineModifiedBase* fundamentalSplineModifiedBasis =
      dynamic_cast<SGPP::base::SFundamentalSplineModifiedBase*>(&basis);
  SGPP::base::SWaveletBase* waveletBasis =
      dynamic_cast<SGPP::base::SWaveletBase*>(&basis);
  SGPP::base::SWaveletBoundaryBase* waveletBoundaryBasis =
      dynamic_cast<SGPP::base::SWaveletBoundaryBase*>(&basis);
  SGPP::base::SWaveletModifiedBase* waveletModifiedBasis =
      dynamic_cast<SGPP::base::SWaveletModifiedBase*>(&basis);

  if (bsplineBasis != nullptr) {
    return bsplineBasis->evalDxDx(l, i, x);
  } else if (bsplineBoundaryBasis != nullptr) {
    return bsplineBoundaryBasis->evalDxDx(l, i, x);
  } else if (bsplineClenshawCurtisBasis != nullptr) {
    return bsplineClenshawCurtisBasis->evalDxDx(l, i, x);
  } else if (bsplineModifiedBasis != nullptr) {
    return bsplineModifiedBasis->evalDxDx(l, i, x);
  } else if (bsplineModifiedClenshawCurtisBasis != nullptr) {
    return bsplineModifiedClenshawCurtisBasis->evalDxDx(l, i, x);
  } else if (fundamentalSplineBasis != nullptr) {
    return fundamentalSplineBasis->evalDxDx(l, i, x);
  } else if (fundamentalSplineModifiedBasis != nullptr) {
    return fundamentalSplineModifiedBasis->evalDxDx(l, i, x);
  } else if (waveletBasis != nullptr) {
    return waveletBasis->evalDxDx(l, i, x);
  } else if (waveletBoundaryBasis != nullptr) {
    return waveletBoundaryBasis->evalDxDx(l, i, x);
  } else if (waveletModifiedBasis != nullptr) {
    return waveletModifiedBasis->evalDxDx(l, i, x);
  } else {
    BOOST_THROW_EXCEPTION(std::runtime_error("Invalid basis."));
    return NAN;
  }
}
