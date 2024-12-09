Eigen::ArrayXXi deriveIndices(const ioda::ObsSpace & obsdb,
                              const int numLevels) {
  // Assume ObsSpace contains only the averaged profiles if this variable isn't present.
  boost::optional<std::vector<int>> extended_obs_space;
  if (obsdb.has("MetaData", "extended_obs_space")) {
    extended_obs_space = std::vector<int>(obsdb.nlocs());
    obsdb.get_db("MetaData", "extended_obs_space", *extended_obs_space);
  }
  Eigen::ArrayXXi profileIndex {obsdb.nrecs(), numLevels};

  int recnum = 0;
  for (ioda::ObsSpace::RecIdxIter irec = obsdb.recidx_begin(); irec != obsdb.recidx_end(); ++irec) {
    int levnum = 0;
    const std::vector<std::size_t> &rSort = obsdb.recidx_vector(irec);
    for (size_t ilocs = 0; ilocs < rSort.size(); ++ilocs) {
      if (extended_obs_space && ((*extended_obs_space)[rSort[ilocs]] != 1))
        continue;
      profileIndex(recnum, levnum) = rSort[ilocs];
      levnum++;
    }
    if (levnum != numLevels) {
      std::stringstream msg;
      msg << "Record (profile): " << recnum << " length: " << levnum+1 << " does not match the "
          << "number of levels expected: " << numLevels;
      throw eckit::UserError(msg.str(), Here());
    }
    recnum++;
  }
  return profileIndex;
}