/********************************************************************/
/*                  SOFTWARE COPYRIGHT NOTIFICATION                 */
/*                             Cardinal                             */
/*                                                                  */
/*                  (c) 2021 UChicago Argonne, LLC                  */
/*                        ALL RIGHTS RESERVED                       */
/*                                                                  */
/*                 Prepared by UChicago Argonne, LLC                */
/*               Under Contract No. DE-AC02-06CH11357               */
/*                With the U. S. Department of Energy               */
/*                                                                  */
/*             Prepared by Battelle Energy Alliance, LLC            */
/*               Under Contract No. DE-AC07-05ID14517               */
/*                With the U. S. Department of Energy               */
/*                                                                  */
/*                 See LICENSE for full restrictions                */
/********************************************************************/

#pragma once

#include "NekSideIntegral.h"
#include "CardinalEnums.h"

/**
 * Compute the integral of a specified quantity over the boundaries
 * in the nekRS mesh, weighted by the mass flux,
 * \f$\int_\Gamma \rho_f\vec{V}\cdot\hat{n} fd\Gamma\f$, where \f$f\f$ is the
 * field to be integrated, \f$\Gamma\f$ is the boundary, and
 * \f$\rho_f\vec{V}\cdot\hat{n}\f$ is the mass flux.
 *
 * Note that this calculation is done directly on the mesh that nekRS solves on,
 * _not_ the mesh created for solution transfer in NekRSMesh.
 */
class NekMassFluxWeightedSideIntegral : public NekSideIntegral
{
public:
  static InputParameters validParams();

  NekMassFluxWeightedSideIntegral(const InputParameters & parameters);

  virtual Real getValue() const override;
};
