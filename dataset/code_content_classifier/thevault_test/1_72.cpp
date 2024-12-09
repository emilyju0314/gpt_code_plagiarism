size_t GeoVaLs::nlevs(const std::string & var) const {
  oops::Log::trace() << "GeoVaLs::nlevs starting" << std::endl;
  int nlevs;
  ufo_geovals_nlevs_f90(keyGVL_, var.size(), var.c_str(), nlevs);
  oops::Log::trace() << "GeoVaLs::nlevs done" << std::endl;
  return nlevs;
}