void GeoVaLs::get(std::vector<double> & vals, const std::string & var) const {
  oops::Log::trace() << "GeoVaLs::get 2D starting" << std::endl;
  size_t nlocs;
  ufo_geovals_nlocs_f90(keyGVL_, nlocs);
  ASSERT(vals.size() == nlocs);
  ufo_geovals_get2d_f90(keyGVL_, var.size(), var.c_str(), nlocs, vals[0]);
  oops::Log::trace() << "GeoVaLs::get 2D done" << std::endl;
}