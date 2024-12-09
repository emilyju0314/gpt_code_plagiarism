std::vector<bool> identifyRejectedObservations(const ObsFilterData &data) {
  const size_t nlocs = data.nlocs();
  const oops::Variables &simulatedVars = data.obsspace().obsvariables();
  std::vector<bool> rejected(nlocs, true);

  std::vector<int> qcflags(nlocs);
  for (size_t iv = 0; iv < simulatedVars.size(); ++iv) {
    data.get(Variable(simulatedVars[iv] + "@QCflagsData"), qcflags);
    for (size_t iloc = 0; iloc < nlocs; ++iloc)
      if (qcflags[iloc] == QCflags::pass)
        rejected[iloc] = false;
  }

  return rejected;
}