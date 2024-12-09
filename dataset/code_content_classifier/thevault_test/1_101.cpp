void assignToVariable(const ufo::Variable &variable,
                      ioda::ObsDtype dtype,
                      const AssignmentParameters &params,
                      const std::vector<bool> &apply,
                      const ObsFilterData &data,
                      ioda::ObsSpace &obsdb,
                      ioda::ObsDataVector<int> &qcflags) {
  switch (dtype) {
  case ioda::ObsDtype::Float:
    assignToFloatVariable(variable, params, apply, data, obsdb, qcflags);
    break;
  case ioda::ObsDtype::Integer:
    assignToIntVariable(variable, params, apply, data, obsdb);
    break;
  case ioda::ObsDtype::String:
    assignToNonnumericVariable<std::string>(variable, params, apply, data, obsdb);
    break;
  case ioda::ObsDtype::DateTime:
    assignToNonnumericVariable<util::DateTime>(variable, params, apply, data, obsdb);
    break;
  default:
    ASSERT_MSG(false, "Unrecognized data type");
  }
}