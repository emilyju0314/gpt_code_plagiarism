double GeoVaLs::dot_product_with(const GeoVaLs & other) const {
  oops::Log::trace() << "GeoVaLs::dot_product_with starting" << std::endl;
  const size_t nlocs = this->nlocs();
  assert(nlocs == other.nlocs());
  assert(vars_ == other.vars_);
  auto accumulator = dist_->createAccumulator<double>();
  std::vector<double> this_values(nlocs), other_values(nlocs);
  const double missing = util::missingValue(missing);
  // loop over all variables in geovals
  for (size_t jvar = 0; jvar < vars_.size(); ++jvar) {
    const size_t nlevs = this->nlevs(vars_[jvar]);
    assert(nlevs == other.nlevs(vars_[jvar]));
    // loop over all levels for this variable
    for (size_t jlev = 0; jlev < nlevs; ++jlev) {
      this->getAtLevel(this_values, vars_[jvar], jlev);
      other.getAtLevel(other_values, vars_[jvar], jlev);
      // loop over all locations
      for (size_t jloc = 0; jloc < nlocs; ++jloc) {
        if ((this_values[jloc] != missing) && (other_values[jloc] != missing)) {
          accumulator->addTerm(jloc, this_values[jloc]*other_values[jloc]);
        }
      }
    }
  }
  const double dotprod = accumulator->computeResult();
  oops::Log::trace() << "GeoVaLs::dot_product_with done" << std::endl;
  return dotprod;
}