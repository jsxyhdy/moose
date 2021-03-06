//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "BoostNormalDistribution.h"

#include "libmesh/auto_ptr.h"

registerMooseObjectAliased("StochasticToolsApp", BoostNormalDistribution, "BoostNormal");
registerMooseObjectReplaced("StochasticToolsApp",
                            BoostNormalDistribution,
                            "07/01/2020 00:00",
                            BoostNormal);

InputParameters
BoostNormalDistribution::validParams()
{
  InputParameters params = Distribution::validParams();
  params.addClassDescription("Boost Normal distribution.");
  params.addRequiredParam<Real>("mean", "Mean of the distribution.");
  params.addRequiredParam<Real>("standard_deviation", "Standard deviation of the distribution.");
  return params;
}

BoostNormalDistribution::BoostNormalDistribution(const InputParameters & parameters)
  : BoostDistribution<boost::math::normal_distribution<Real>>(parameters)
{
  _distribution_unique_ptr = libmesh_make_unique<boost::math::normal_distribution<Real>>(
      getParam<Real>("mean"), getParam<Real>("standard_deviation"));
}
