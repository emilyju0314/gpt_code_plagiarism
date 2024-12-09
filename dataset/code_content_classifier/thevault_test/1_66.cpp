GeoVaLs::GeoVaLs(const eckit::Configuration & config,
                 const ioda::ObsSpace & obspace,
                 const oops::Variables & vars)
  : keyGVL_(-1), vars_(vars), dist_(obspace.distribution())
{
  oops::Log::trace() << "GeoVaLs constructor config starting" << std::endl;
  ufo_geovals_partial_setup_f90(keyGVL_, 0, vars_);
  // only read if there are variables specified
  if (vars_.size() > 0)  ufo_geovals_read_file_f90(keyGVL_, config, obspace, vars_);
  oops::Log::trace() << "GeoVaLs contructor config key = " << keyGVL_ << std::endl;
}