#pragma once

#include "SideSpatialBinUserObject.h"

/**
 * Class that bins spatial coordinates into planes oriented in a particular direction.
 */
class LayeredGapBin : public SideSpatialBinUserObject
{
public:
  static InputParameters validParams();

  LayeredGapBin(const InputParameters & parameters);

  virtual const unsigned int bin(const Point & p) const override;

  virtual const unsigned int num_bins() const override;

  virtual Real distanceFromGap(const Point & point, const unsigned int & gap_index) const override;

  virtual unsigned int gapIndex(const Point & point) const override;

  virtual void gapIndexAndDistance(const Point & point, unsigned int & index, Real & distance) const override;

  virtual const std::vector<Point> & gapUnitNormals() const override { return _unit_normals; }

protected:
  /// Direction of the bins (x, y, or z)
  const unsigned int _direction;

  /// Number of equal-size layers
  const unsigned int & _num_layers;

  /// Underlying problem
  const SubProblem * _layered_subproblem;

  /// Number of bins
  const unsigned int _num_faces;

  /// Minimum coordinate in the direction
  Real _direction_min;

  /// Maxium coordinate in the direction
  Real _direction_max;

  /// Bounds of the 1-D layering
  std::vector<Real> _layer_pts;

  /// Bounds of the volume bins that achieve the same pairing of points to bins
  std::vector<Real> _effective_layer_pts;

  /// Unit normal vectors of the gaps
  std::vector<Point> _unit_normals;
};
