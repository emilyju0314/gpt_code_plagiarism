void assignToIntVariable(const ufo::Variable &variable,
                         const AssignmentParameters &params,
                         const std::vector<bool> &apply,
                         const ObsFilterData &data,
                         ioda::ObsSpace &obsdb) {
  ioda::ObsDataVector<int> values = getCurrentValues<int>(variable, obsdb);
  assignNumericValues(params, variable, apply, data, values);
  saveValues(variable, values, obsdb);
}