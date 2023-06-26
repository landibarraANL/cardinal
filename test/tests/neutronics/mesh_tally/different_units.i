[Mesh]
  [sphere]
    type = FileMeshGenerator
    file = ../meshes/sphere_in_m.e
  []
  [solid_ids]
    type = SubdomainIDGenerator
    input = sphere
    subdomain_id = '100'
  []

  allow_renumbering = false
[]

[Problem]
  type = OpenMCCellAverageProblem
  solid_blocks = '100'
  initial_properties = xml
  verbose = true
  solid_cell_level = 0

  tally_type = mesh
  power = 100.0

  # the [Mesh] is in units of meters, so the mesh_template must also be in units of meters
  scaling = 100.0
  mesh_template = '../meshes/sphere_in_m.e'

  normalize_by_global_tally = false
[]

[Executioner]
  type = Steady
[]

[Postprocessors]
  [kappa_fission]
    type = ElementIntegralVariablePostprocessor
    variable = kappa_fission
  []
[]

[Outputs]
  execute_on = final
  exodus = true
  hide = 'temp'
[]
