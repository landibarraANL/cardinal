#pragma once

#include "ThreadedGeneralUserObject.h"

/**
 * Class that provides a bin index given a spatial coordinate
 */
class SpatialBinUserObject : public ThreadedGeneralUserObject
{
public:
  static InputParameters validParams();

  SpatialBinUserObject(const InputParameters & parameters);

  virtual void execute() final {}
  virtual void initialize() final {}
  virtual void finalize() final {}

  virtual void threadJoin(const UserObject &) final {}
  virtual void subdomainSetup() final {}

  virtual Real spatialValue(const Point & p) const override;

  /**
   * Get the bin index from a spatial point
   * @param[in] p point
   * @return bin index
   */
  virtual const unsigned int bin(const Point & p) const = 0;

  /**
   * Get the total number of bins
   * @return total number of bins
   */
  virtual const unsigned int num_bins() const = 0;

  /**
   * Get the bin given a point in an array of bounding points between layers
   * @param[in] pt point along axis of the bounding points
   * @param[in] bounds vector of bounding points
   * @return layer
   */
  unsigned int binFromBounds(const Real & pt, const std::vector<Real> & bounds) const;
};