ioda::ObsDtype ObsFilterData::dtype(const Variable & varname) const {
  const std::string var = varname.variable();
  const std::string grp = varname.group();
  // Default to float
  ioda::ObsDtype res = ioda::ObsDtype::Float;
  if (obsdb_.has(grp, var)) {
    res = obsdb_.dtype(grp, var);
  } else if (hasDataVectorInt(varname.group(), varname.variable())) {
    res = ioda::ObsDtype::Integer;
  } else if (!this->has(varname)) {
    oops::Log::error() << "ObsFilterData::dtype unable to find provided variable."
                       << std::endl;
    ABORT("ObsFilterData::dtype unable to find provided variable.");
  }
  return res;
}