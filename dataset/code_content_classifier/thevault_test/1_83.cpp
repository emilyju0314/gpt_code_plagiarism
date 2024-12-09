void GeoVaLs::putAtLevel(const std::vector<float> & vals,
                         const std::string & var,
                         const int lev) const {
  oops::Log::trace() << "GeoVaLs::putAtLevel(float) starting" << std::endl;
  size_t nlocs;
  ufo_geovals_nlocs_f90(keyGVL_, nlocs);
  ASSERT(vals.size() == nlocs);
  std::vector<double> doublevals(vals.begin(), vals.end());
  ufo_geovals_putdouble_f90(keyGVL_, var.size(), var.c_str(), lev, nlocs, doublevals[0]);
  oops::Log::trace() << "GeoVaLs::putAtLevel(float) done" << std::endl;
}