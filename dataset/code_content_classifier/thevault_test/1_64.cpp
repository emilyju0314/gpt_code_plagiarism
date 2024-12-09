GeoVaLs::GeoVaLs(const Locations & locs, const oops::Variables & vars)
  : keyGVL_(-1), vars_(vars), dist_(locs.distribution())
{
  oops::Log::trace() << "GeoVaLs contructor starting" << std::endl;
  ufo_geovals_partial_setup_f90(keyGVL_, locs.size(), vars_);
  oops::Log::trace() << "GeoVaLs contructor key = " << keyGVL_ << std::endl;
}