GeoVaLs::GeoVaLs(std::shared_ptr<const ioda::Distribution> dist,
                 const oops::Variables & vars)
  : keyGVL_(-1), vars_(vars), dist_(std::move(dist))
{
  oops::Log::trace() << "GeoVaLs default constructor starting" << std::endl;
  ufo_geovals_default_constr_f90(keyGVL_);
  oops::Log::trace() << "GeoVaLs default constructor end" << std::endl;
}