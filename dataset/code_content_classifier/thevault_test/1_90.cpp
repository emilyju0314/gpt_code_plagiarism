size_t GeoVaLs::nlocs() const {
  oops::Log::trace() << "GeoVaLs::nlocs starting" << std::endl;
  size_t nlocs;
  ufo_geovals_nlocs_f90(keyGVL_, nlocs);
  oops::Log::trace() << "GeoVaLs::nlocs done" << std::endl;
  return nlocs;
}