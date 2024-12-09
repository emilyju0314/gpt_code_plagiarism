void GeoVaLs::putAtLevel(const std::vector<double> & vals,
                         const std::string & var,
                         const int lev) const {
  oops::Log::trace() << "GeoVaLs::putAtLevel(double) starting" << std::endl;
  size_t nlocs;
  ufo_geovals_nlocs_f90(keyGVL_, nlocs);
  ASSERT(vals.size() == nlocs);
  ufo_geovals_putdouble_f90(keyGVL_, var.size(), var.c_str(), lev, nlocs, vals[0]);
  oops::Log::trace() << "GeoVaLs::putAtLevel(double) done" << std::endl;
}