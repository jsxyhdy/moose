//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "BoostWeibullDistribution.h"

#include "libmesh/auto_ptr.h"

registerMooseObjectAliased("StochasticToolsApp", BoostWeibullDistribution, "BoostWeibull");
registerMooseObjectReplaced("StochasticToolsApp",
                            BoostWeibullDistribution,
                            "07/01/2020 00:00",
                            BoostWeibull);

InputParameters
BoostWeibullDistribution::validParams()
{
  InputParameters params = Distribution::validParams();
  params.addClassDescription("Boost Weibull distribution.");
  params.addRequiredParam<Real>("shape", "The Weibull shape parameter.");
  params.addParam<Real>("scale", 1, "The Weibull scale parameter.");
  return params;
}

BoostWeibullDistribution::BoostWeibullDistribution(const InputParameters & parameters)
  : BoostDistribution<boost::math::weibull_distribution<Real>>(parameters)
{
  _distribution_unique_ptr = libmesh_make_unique<boost::math::weibull_distribution<Real>>(
      getParam<Real>("shape"), getParam<Real>("scale"));
}
