void GeoVaLs::read(const eckit::Configuration & config,
                   const ioda::ObsSpace & obspace) {
  oops::Log::trace() << "GeoVaLs::read starting" << std::endl;
  ufo_geovals_read_file_f90(keyGVL_, config, obspace, vars_);
  oops::Log::trace() << "GeoVaLs::read done" << std::endl;
}