void GeoVaLs::getAtLevel(std::vector<float> & vals, const std::string & var, const int lev) const {
  oops::Log::trace() << "GeoVaLs::getAtLevel(float) starting" << std::endl;
  size_t nlocs;
  ufo_geovals_nlocs_f90(keyGVL_, nlocs);
  ASSERT(vals.size() == nlocs);
  ufo_geovals_get_f90(keyGVL_, var.size(), var.c_str(), lev, nlocs, vals[0]);
  oops::Log::trace() << "GeoVaLs::getAtLevel(float) done" << std::endl;
}