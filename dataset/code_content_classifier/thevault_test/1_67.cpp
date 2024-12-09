GeoVaLs::GeoVaLs(const GeoVaLs & other, const int & index)
  : keyGVL_(-1), vars_(other.vars_), dist_(other.dist_)
{
  oops::Log::trace() << "GeoVaLs copy one GeoVaLs constructor starting" << std::endl;
  ufo_geovals_copy_one_f90(keyGVL_, other.keyGVL_, index);
  oops::Log::trace() << "GeoVaLs copy one GeoVaLs constructor key = " << keyGVL_ << std::endl;
}