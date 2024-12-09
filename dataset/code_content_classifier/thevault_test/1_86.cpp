void GeoVaLs::putAtLocation(const std::vector<float> & vals,
                            const std::string & var,
                            const int loc) const {
  oops::Log::trace() << "GeoVaLs::putAtLocation(float) starting" << std::endl;
  const size_t nlevs = this->nlevs(var);
  ASSERT(vals.size() == nlevs);
  ASSERT(loc >= 0 && loc < this->nlocs());
  std::vector<double> doublevals(vals.begin(), vals.end());
  ufo_geovals_put_loc_f90(keyGVL_, var.size(), var.c_str(), loc, nlevs, doublevals[0]);
  oops::Log::trace() << "GeoVaLs::putAtLocation(float) done" << std::endl;
}