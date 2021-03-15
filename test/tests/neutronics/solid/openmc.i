# The OpenMC model is created with the scripts/openmc_pebble_bed_model.py with the following args
# openmc_pebble_bed_model.py -e 1.0
#
# This is a vertical stack of three pebbles, with a 1 meter thick layer of flibe
# on the outer periphery and on the top and bottom, to get a k closer to 1.0.

[Mesh]
  [sphere]
    # Mesh of a single pebble with outer radius of 1.5 (cm)
    type = FileMeshGenerator
    file = ../meshes/sphere.e
  []
  [multiple]
    type = CombinerGenerator
    inputs = sphere
    positions = '0 0 0
                 0 0 4
                 0 0 8'
  []
[]

[Problem]
  type = OpenMCProblem
  power = 10.0
  centers_file = 'pebble_centers_rescaled.txt'

  # volumes of each of the pebbles in the MOOSE mesh, so that we get the
  # correct normalization
  volumes = '1.322128e+01'

  tally_type = 'cell'
  pebble_cell_level = 1
[]

[Executioner]
  type = Transient
[]

[Outputs]
  exodus = true
[]
