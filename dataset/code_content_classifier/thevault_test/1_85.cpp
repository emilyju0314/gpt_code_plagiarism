void GeoVaLs::putAtLocation(const std::vector<double> & vals,
                            const std::string & var,
                            const int loc) const {
  oops::Log::trace() << "GeoVaLs::putAtLocation(double) starting" << std::endl;
  const size_t nlevs = this->nlevs(var);
  ASSERT(vals.size() == nlevs);
  ASSERT(loc >= 0 && loc < this->nlocs());
  ufo_geovals_put_loc_f90(keyGVL_, var.size(), var.c_str(), loc, nlevs, vals[0]);
  oops::Log::trace() << "GeoVaLs::putAtLocation(double) done" << std::endl;
}