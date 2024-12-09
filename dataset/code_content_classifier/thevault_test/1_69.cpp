void GeoVaLs::reorderzdir(const std::string & varname, const std::string & vardir) {
  oops::Log::trace() << "GeoVaLs::reorderzdir starting" << std::endl;
  ufo_geovals_reorderzdir_f90(keyGVL_, varname.size(), varname.c_str(),
                              vardir.size(), vardir.c_str());
  oops::Log::trace() << "GeoVaLs::reorderzdir done" << std::endl;
}