void GeoVaLs::write(const eckit::Configuration & config) const {
  oops::Log::trace() << "GeoVaLs::write starting" << std::endl;
  ufo_geovals_write_file_f90(keyGVL_, config, dist_->rank());
  oops::Log::trace() << "GeoVaLs::write done" << std::endl;
}