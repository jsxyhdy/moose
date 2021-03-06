//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADComputeEigenstrainBase.h"
#include "DerivativeMaterialPropertyNameInterface.h"

template <typename>
class RankTwoTensorTempl;
typedef RankTwoTensorTempl<Real> RankTwoTensor;

/**
 * ADComputeThermalExpansionEigenstrainBase is a base class for all models that
 * compute eigenstrains due to thermal expansion of a material.
 */
class ADComputeThermalExpansionEigenstrainBase : public ADComputeEigenstrainBase,
                                                 public DerivativeMaterialPropertyNameInterface
{
public:
  static InputParameters validParams();

  ADComputeThermalExpansionEigenstrainBase(const InputParameters & parameters);

protected:
  virtual void computeQpEigenstrain() override;

  /*
   * Compute the total thermal strain relative to the stress-free temperature at
   * the current temperature, as well as the current instantaneous thermal
   * expansion coefficient.
   * param thermal_strain    The current total linear thermal strain
   *                         (\delta L / L)
   */
  virtual void computeThermalStrain(ADReal & thermal_strain) = 0;

  const ADVariableValue & _temperature;
  const ADVariableValue & _stress_free_temperature;
};
